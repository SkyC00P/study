#include "MGraph.h"

static void _skip_note(FILE * fp) {
	CheckPtr(fp);
	char ch = fgetc(fp);
	if (ch == '#') {
		while (ch != '\n' || ch != EOF) {
			ch = fgetc(fp);
		}
	}
	else {
		ungetc(ch, fp);
	}
}

static int _read_int(FILE * fp) {
	CheckPtr(fp);
	_skip_note(fp);
	int num;
	if (fscanf(fp, "%d", &num) != 1) {
		Exit_with_msg("read err");
	}
	return num;
}

static char _read_ve(FILE * fp) {
	CheckPtr(fp);
	_skip_note(fp);
	char ch;
	if (fscanf(fp, "%c,", &ch) != 1) {
		Exit_with_msg("read err");
	}
	return ch;
}

static char _read_edge_g(FILE * fp, char * v1, char * v2) {
	CheckPtr(fp);
	_skip_note(fp);
	if (fscanf(fp, "%c-%c", v1, v2) != 2) {
		Exit_with_msg("read err");
	}
}

static char _read_edge_n(FILE * fp, char * v1, char * v2, int * weight) {
	CheckPtr(fp);
	_skip_note(fp);
	if (fscanf(fp, "%c-%c-%d", v1, v2, weight) != 3) {
		Exit_with_msg("read err");
	}
}

static MGraph _create_dg(FILE * fp) {
	CheckPtr(fp);
	MGraph mg = malloc(sizeof(_MGraph));
	if (!mg) {
		return NULL;
	}

	mg->kind = DG;
	mg->numVertexes = _read_int(fp);
	mg->numEdges = _read_int(fp);

	for (int i = 0; i < mg->numVertexes; i++) {
		MG_VertexType data = _read_ve(fp);
		mg->vexs[i] = data;
		for (int j = 0; j < mg->numVertexes; j++) {
			mg->numEdges[i][j] = 0;
		}
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, &v1, &v2);
		int e1 = MGraph_locate(mg, v1);
		int e2 = MGraph_locate(mg, v2);
		if (e1 < 0 || e2 < 0) {
			return NULL;
		}
		mg->arcs[e1][e2] = 1;
	}
	return mg;
}
static MGraph _create_dn(FILE * fp) {
	CheckPtr(fp);
	MGraph mg = malloc(sizeof(_MGraph));
	if (!mg) {
		return NULL;
	}

	mg->kind = DN;
	mg->numVertexes = _read_int(fp);
	mg->numEdges = _read_int(fp);

	for (int i = 0; i < mg->vexs; i++) {
		mg->vexs[i] = _read_ve(fp);
		for (int j = 0; j < mg->vexs; j++) {
			mg->arcs[i][j] = INFINITY;
		}
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int e1 = MGraph_locate(mg, v1);
		int e2 = MGraph_locate(mg, v2);
		if (e1 < 0 || e2 < 0) {
			return NULL;
		}
		mg->arcs[e1][e2] = weight;
	}
	return mg;
}
static MGraph _create_udg(FILE * fp) {
	CheckPtr(fp);
	MGraph mg = malloc(sizeof(_MGraph));
	if (!mg) {
		return NULL;
	}
	mg->kind = UDG;
	mg->numVertexes = _read_int(fp);
	mg->numEdges = _read_int(fp);

	for (int i = 0; i < mg->numVertexes; i++) {
		mg->vexs[i] = _read_ve(fp);
		for (int j = 0; j < mg->numVertexes; j++) {
			mg->numEdges[i][j] = 0;
		}
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, &v1, &v2);
		int e1 = MGraph_locate(mg, v1);
		int e2 = MGraph_locate(mg, v2);
		if (e1 < 0 || e2 < 0) {
			return NULL;
		}
		mg->arcs[e1][e2] = 1;
		mg->arcs[e2][e1] = 1;
	}
	return mg;
}
static MGraph _create_udn(FILE * fp) {
	CheckPtr(fp);
	MGraph mg = malloc(sizeof(_MGraph));
	if (!mg) {
		return NULL;
	}
	mg->kind = UDN;
	mg->numVertexes = _read_int(fp);
	mg->numEdges = _read_int(fp);

	for (int i = 0; i < mg->numVertexes; i++) {
		mg->vexs[i] = _read_ve(fp);
		for (int j = 0; j < mg->numVertexes; j++) {
			mg->numEdges[i][j] = INFINITY;
		}
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int e1 = MGraph_locate(mg, v1);
		int e2 = MGraph_locate(mg, v2);
		if (e1 < 0 || e2 < 0) {
			return NULL;
		}
		mg->arcs[e1][e2] = weight;
		mg->arcs[e2][e1] = weight;
	}
	return mg;
}
MGraph MGraph_create(FILE * fp)
{
	CheckPtr(fp);

	MGraphKind kind = _read_int(fp);
	switch (kind)
	{
	case DG:
		return _create_dg(fp);
	case DN:
		return _create_dn(fp);
	case UDG:
		return _create_udg(fp);
	case UDN:
		return _create_udn(fp);
	default:
		return NULL;
	}

}
/* ���ͼ */
void MGraph_clear(MGraph G) {
	if (G) {
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* ����ͼ */
void MGraph_destroy(MGraph G) {
	if (G) {
		free(G);
		G = NULL;
	}
}

/* Ѱ�Ҷ���v��λ�á� */
int MGraph_locate(MGraph G, MG_VertexType v) {
	CheckPtr(G);

	for (int i = 0; i < G->numEdges; i++) {
		if (G->vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

/* ���ص�v������ֵ */
MG_VertexType MGraph_get(MGraph G, int order) {
	CheckPtr(G);
	return order >= 0 ? G->vexs[order] : '\0';
}

/* �Զ���v��ֵvalue�� */
void MGraph_set(MGraph G, MG_VertexType old, MG_VertexType new) {
	CheckPtr(G);
	int index = MGraph_locate(G, old);
	if (index >= 0)
		G->vexs[index] = new;
}

/* ����v�ĵ�һ���ڽӶ������ */
int MGraph_frist_vertex(MGraph G, MG_VertexType v) {
	CheckPtr(G);
	int index = MGraph_locate(G, v);
	if (index >= 0) {
		int flag;
		switch (G->kind)
		{
		case DG:
		case UDG:
			flag = 0;
			break;
		default:
			flag = INFINITY;
			break;
		}

		for (int i = 0; i < G->numVertexes; i++) {
			if (G->arcs[index][i] != flag) {
				return i;
			}
		}
	}
	return -1;
}

/* ����v�����w����һ���ڽӶ������ */
int MGraph_next_vertex(MGraph G, MG_VertexType v, MG_VertexType w) {
	CheckPtr(G);
	int i1 = MGraph_locate(G, v);
	int i2 = MGraph_locate(G, w);
	if (i1 >= 0 && i2 >= 0) {
		int flag;
		switch (G->kind)
		{
		case DG:
		case UDG:
			flag = 0;
			break;
		default:
			flag = INFINITY;
			break;
		}

		for (int i = i2 + 1; i < G->numVertexes; i++) {
			if (G->arcs[i1][i] != flag) {
				return i;
			}
		}
	}
	return -1;
}

/* ���붥��v��ͼ */
Status MGraph_add_vertex(MGraph G, MG_VertexType v) {
	CheckPtr(G);
	if (G->numVertexes == MAX_VERTEX_NUM) {
		return ERROR;
	}
	int index = MGraph_locate(G, v);
	if (index >= 0) {
		return ERROR;
	}
	G->numVertexes++;
	G->vexs[G->numVertexes] = v;
	int weight = G->kind % 2 ? INFINITY : 0;
	for (int i = 0; i < G->numVertexes; i++) {
		G->arcs[i][G->numVertexes] = weight;
		G->arcs[G->numVertexes][i] = weight;
	}
	return OK;
}

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status MGraph_del_vertex(MGraph G, MG_VertexType v) {
	CheckPtr(G);
	int index = MGraph_locate(G, v);
	if (index < 0) {
		return ERROR;
	}
	for (int i = index; i < G->numVertexes; i++) {
		G->vexs[i] = G->vexs[i + 1];
	}
	int flag = G->kind % 2 ? INFINITY : 0;
	int delCount = 0;
	for (int i = 0; i < G->numVertexes; i++) {
		// ����ͼ�ԳƵ㿴���Ƿ����
		if (flag && G->arcs[i][index] != flag) {
			delCount++;
		}
		if (G->arcs[index][i] != flag) {
			delCount++;
		}
	}

	for (int i = index; i < G->numVertexes; i++) {
		G->arcs[i] = G->arcs[i + 1];
		for (int j = index; j < G->numVertexes; j++) {
			G->arcs[i][j] = G->arcs[i][j + 1];
		}
	}
	G->numEdges -= delCount;
	G->numVertexes--;
	return OK;
}

/* ���뻡<v,w>��ͼ */
Status MGraph_add_arc(MGraph G, MG_VertexType v, MG_VertexType w, MG_Weight weight) {
	CheckPtr(G);
	int index_1 = MGraph_locate(G, v);
	if (index_1 < 0) {
		if (!MGraph_add_vertex(G, v)) {
			return ERROR;
		}
		index_1 = MGraph_locate(G, v);
	}

	int index_2 = MGraph_locate(G, w);
	if (index_2 < 0) {
		if (!MGraph_add_vertex(G, w)) {
			return ERROR;
		}
		index_2 = MGraph_locate(G, w);
	}
	G->arcs[index_1][index_2] = weight;
	if (G->kind == UDN || G->kind == UDG) {
		G->arcs[index_2][index_1] = weight;
		G->numEdges++;
	}
	G->numEdges++;
	return OK;
}

/* ɾ����<v,w>��ͼ */
Status MGraph_del_arc(MGraph G, MG_VertexType v, MG_VertexType w) {}

/* ������ȱ��� */
void MGraph_DFS(MGraph G) {}

/* ������ȱ��� */
void MGraph_HFS(MGraph G) {}

/* ��ӡͼ */
void MGraph_print(MGraph G) {}