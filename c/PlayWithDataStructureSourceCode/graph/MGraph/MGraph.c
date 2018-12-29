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
	if (fscanf(fp, "%c,", &ch)!= 1) {
		Exit_with_msg("read err");
	}
	return ch;
}

static char _read_edge(FILE * fp, char * v1, char * v2) {
	CheckPtr(fp);
	_skip_note(fp);
	if (fscanf(fp, "%c-%c", v1, v2) != 2) {
		Exit_with_msg("read err");
	}
}

MGraph _create_dg(FILE * fp) {
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
	}

	for (int i = 0; i < mg->numEdges; i++) {
		char v1, v2;
		_read_edge(fp, &v1, &v2);
	}
}
MGraph _create_dn(FILE * fp) {

}
MGraph _create_udg(FILE * fp) {

}
MGraph _create_udn(FILE * fp) {

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

}

/* ����ͼ */
void MGraph_destroy(MGraph G) {}

/* Ѱ�Ҷ���v��λ�á� */
int MGraph_locate(MGraph G, MG_VertexType v) {}

/* ���ص�v������ֵ */
MG_VertexType MGraph_get(MGraph G, int order) {}

/* �Զ���v��ֵvalue�� */
void MGraph_set(MGraph G, MG_VertexType old, MG_VertexType new) {}

/* ����v�ĵ�һ���ڽӶ������ */
int MGraph_frist_vertex(MGraph G, MG_VertexType v) {}

/* ����v�����w����һ���ڽӶ������ */
int MGraph_next_vertex(MGraph G, MG_VertexType v, MG_VertexType w) {}

/* ���붥��v��ͼ */
Status MGraph_add_vertex(MGraph G, MG_VertexType v) {}

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status MGraph_del_vertex(MGraph G, MG_VertexType v) {}

/* ���뻡<v,w>��ͼ */
Status MGraph_add_arc(MGraph G, MG_VertexType v, MG_VertexType w) {}

/* ɾ����<v,w>��ͼ */
Status MGraph_del_arc(MGraph G, MG_VertexType v, MG_VertexType w) {}

/* ������ȱ��� */
void MGraph_DFS(MGraph G) {}

/* ������ȱ��� */
void MGraph_HFS(MGraph G) {}

/* ��ӡͼ */
void MGraph_print(MGraph G) {}