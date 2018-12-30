#include "MGraph.h"
#include "../file.c"

static MGraph _create_dg(FILE * fp) {
	CheckPtr(fp);
	MGraph mg = malloc(sizeof(_MGraph));
	if (!mg) {
		Exit_with_msg("Out of memory");
	}

	mg->kind = DG;
	mg->numVertexes = _read_int(fp);
	mg->numEdges = _read_int(fp);

	for (int i = 0; i < mg->numVertexes; i++) {
		MG_VertexType data = _read_ve(fp);
		mg->vexs[i] = data;
		for (int j = 0; j < mg->numVertexes; j++) {
			mg->arcs[i][j] = 0;
		}
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, &v1, &v2);
		int e1 = MGraph_locate(mg, v1);
		int e2 = MGraph_locate(mg, v2);
		if (e1 < 0 || e2 < 0) {
			free(mg);
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

	for (int i = 0; i < mg->numVertexes; i++) {
		mg->vexs[i] = _read_ve(fp);
		for (int j = 0; j < mg->numVertexes; j++) {
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
			mg->arcs[i][j] = 0;
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
/* 清空图 */
void MGraph_clear(MGraph G) {
	if (G) {
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* 销毁图 */
void MGraph_destroy(MGraph * G) {
	if (*G) {
		free(*G);
		*G = NULL;
	}
}

/* 寻找顶点v的位置。 */
int MGraph_locate(MGraph G, MG_VertexType v) {
	CheckPtr(G);

	for (int i = 0; i < G->numVertexes; i++) {
		if (G->vexs[i] == v) {
			return i;
		}
	}
	return -1;
}

/* 返回第v个结点的值 */
MG_VertexType MGraph_get(MGraph G, int order) {
	CheckPtr(G);
	return order >= 0 ? G->vexs[order] : '\0';
}

/* 对顶点v赋值value。 */
void MGraph_set(MGraph G, MG_VertexType old, MG_VertexType new) {
	CheckPtr(G);
	int index = MGraph_locate(G, old);
	if (index >= 0)
		G->vexs[index] = new;
}

/* 返回v的第一个邻接顶点序号 */
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

/* 返回v相对于w的下一个邻接顶点序号 */
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

/* 插入顶点v到图 */
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
	G->vexs[G->numVertexes - 1] = v;
	int weight = G->kind % 2 ? INFINITY : 0;
	for (int i = 0; i < G->numVertexes; i++) {
		G->arcs[i][G->numVertexes - 1] = weight;
		G->arcs[G->numVertexes - 1][i] = weight;
	}
	return OK;
}

/* 从图中删除顶点v以及相关的弧 */
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
	Bool direction = G->kind == DG || G->kind == DN;
	int delCount = 0;
	for (int i = 0; i < G->numVertexes; i++) {
		// 有向图对称点看边是否存在
		if (direction && G->arcs[i][index] != flag) {
			delCount++;
		}
		if (G->arcs[index][i] != flag) {
			delCount++;
		}
	}

	for (int i = index; i < G->numVertexes - 1; i++) {
		for (int j = 0; j < index; j++) {
			G->arcs[i][j] = G->arcs[i + 1][j];
		}
		for (int j = index; j < G->numVertexes - 1; j++) {
			G->arcs[i][j] = G->arcs[i + 1][j + 1];
		}
	}
	G->numEdges -= delCount;
	G->numVertexes--;
	return OK;
}

static void _MGraph_add_arc_error_handle(MGraph G, MG_VertexType v, MG_VertexType w) {
	CheckPtr(G);
	MGraph_del_vertex(G, v);
	MGraph_del_vertex(G, w);
}

/* 插入弧<v,w>到图 */
Status MGraph_add_arc(MGraph G, MG_VertexType v, MG_VertexType w, MG_Weight weight) {
	CheckPtr(G);
	int index_1 = MGraph_locate(G, v);
	if (index_1 < 0) {
		if (!MGraph_add_vertex(G, v)) {
			_MGraph_add_arc_error_handle(G, v, w);
			return ERROR;
		}
		index_1 = MGraph_locate(G, v);
	}

	int index_2 = MGraph_locate(G, w);
	if (index_2 < 0) {
		if (!MGraph_add_vertex(G, w)) {
			_MGraph_add_arc_error_handle(G, v, w);
			return ERROR;
		}
		index_2 = MGraph_locate(G, w);
	}

	if (G->kind == UDN || G->kind == UDG) {
		MG_Weight flag = G->kind % 2 ? INFINITY : 0;
		if (G->arcs[index_1][index_2] == flag) {
			G->numEdges++;
		}
		G->arcs[index_1][index_2] = weight;
		G->arcs[index_2][index_1] = weight;
	}
	else
	{
		G->arcs[index_1][index_2] = weight;
		G->numEdges++;
	}
	return OK;
}

/* 删除弧<v,w>到图 */
Status MGraph_del_arc(MGraph G, MG_VertexType v, MG_VertexType w) {
	CheckPtr(G);
	int index_1 = MGraph_locate(G, v);
	int index_2 = MGraph_locate(G, w);
	if (index_1 < 0 || index_2 < 0) {
		return ERROR;
	}

	if (G->kind == UDN || G->kind == UDG) {
		G->arcs[index_2][index_1] = 0;
	}

	if (G->kind == DN || G->kind == UDN) {
		G->arcs[index_1][index_2] = INFINITY;
	}
	else
	{
		G->arcs[index_1][index_2] = 0;
	}
	G->numEdges--;
	return OK;
}

Bool MGraph_arc_exist(MGraph G, MG_VertexType v, MG_VertexType w)
{
	CheckPtr(G);
	MG_Weight flag = G->kind % 2 ? INFINITY : 0;
	int index_1 = MGraph_locate(G, v);
	int index_2 = MGraph_locate(G, w);
	if (index_1 < 0 || index_2 < 0) {
		return FALSE;
	}

	return G->arcs[index_1][index_2] != flag;
}

MG_Weight MGraph_arc_weight(MGraph G, MG_VertexType v, MG_VertexType w)
{
	CheckPtr(G);
	int index_1 = MGraph_locate(G, v);
	int index_2 = MGraph_locate(G, w);
	if (index_1 < 0 || index_2 < 0) {
		Exit_with_msg("[MG_VertexType] can't not be null.");
	}
	return G->arcs[index_1][index_2];
}

/* 深度优先遍历 */
void MGraph_DFS(MGraph G) {}

/* 广度优先遍历 */
void MGraph_HFS(MGraph G) {}

/* 打印图 */
void MGraph_print(MGraph G) {
	if (G) {
		char * kindMsg;
		switch (G->kind)
		{
		case DG:kindMsg = "DG-0-有向图"; break;
		case DN:kindMsg = "DN-1-有向网（带权值）"; break;
		case UDG:kindMsg = "UDG-2-无向图"; break;
		case UDN:kindMsg = "UDN-3-无向网（带权值）"; break;
		default:
			kindMsg = "unkonwn kind";
			break;
		}
		printf("顶点数:%d, 边集数:%d, 类型:%s\n", G->numVertexes, G->numEdges, kindMsg);
		printf("%3c ", ' ');
		for (int i = 0; i < G->numVertexes; i++) {
			printf("%3c ", G->vexs[i]);
		}
		printf("\n");
		for (int i = 0; i < G->numVertexes; i++) {
			printf("%3c ", G->vexs[i]);
			for (int j = 0; j < G->numVertexes; j++) {
				if (G->arcs[i][j] == INFINITY) {
					printf("%3s ", "inf");
				}
				else
				{
					printf("%3d ", G->arcs[i][j]);
				}
			}
			printf("\n");
		}
	}
	else {
		printf("空图");
	}
}