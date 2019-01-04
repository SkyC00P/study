#include "SGraph.h"
#include "../file.c"
#include <string.h>

/* ����ͼ */
SGraph SGraph_create(FILE * fp) {
	CheckPtr(fp);

	SGraphKind kind = _read_int(fp);
	SGraph sg = malloc(sizeof(struct SGraph));
	if (!sg) {
		Exit_with_msg("Out of memory");
	}

	sg->kind = kind;
	sg->numVertexes = _read_int(fp);
	sg->numEdges = _read_int(fp);

	if (sg->numVertexes > MAX_VERTEX_NUM) {
		Exit_with_msg("Out of MAX_VERTEX_NUM");
	}
	if (sg->numEdges > MAX_EDGE_NUM) {
		Exit_with_msg("Out of MAX_EDGE_NUM");
	}
	for (int i = 0; i < sg->numVertexes; i++) {
		sg->ves[i] = _read_ve(fp);
	}
	Bool hasWeight = sg->kind == DN_1 || sg->kind == UDN_3;
	for (int i = 0; i < sg->numEdges; i++) {
		char v1, v2;
		int weight = 0;
		if (hasWeight) {
			_read_edge_n(fp, &v1, &v2, &weight);
		}
		else {
			_read_edge_g(fp, &v1, &v2);
		}
		int index_1 = SGraph_locate(G, v1);
		int index_2 = SGraph_locate(G, v2);
		if (index_1 < 0 || index_2 < 0) {
			SGraph_destroy(&sg);
			return NULL;
		}
		sg->edges[i].begin = index_1;
		sg->edges[i].end = index_2;
		sg->edges[i].weight = weight;
	}
	return sg;
}

/* ���ͼ */
void SGraph_clear(SGraph G) {
	if (G) {
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* ����ͼ */
void SGraph_destroy(SGraph * G) {
	if (*G) {
		free(*G);
		*G = NULL;
	}
}

/* Ѱ�Ҷ���v��λ�á� */
int SGraph_locate(SGraph G, S_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->ves[i] == v) {
			return i;
		}
	}
	return -1;
}

/* ���ص�v������ֵ */
S_VertexType SGraph_get(SGraph G, int order) {
	CheckPtr(G);
	if (order < 0 || order >= G->numVertexes) {
		Exit_with_msg("param:order is error");
	}
	return G->ves[order];
}

/* �Զ���v��ֵvalue�� */
void SGraph_set(SGraph G, S_VertexType old, S_VertexType new) {
	CheckPtr(G);
	int index = SGraph_locate(G, old);
	if (index >= 0) {
		G->ves[index] = new;
	}
}

/* ����v�ĵ�һ���ڽӶ������ */
int SGraph_frist_vertex(SGraph G, S_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;

		if (G->ves[begin] == v) {
			return end;
		}

		if (G->ves[end] == v) {
			return begin;
		}
	}
	return -1;
}

/* ����v�����w����һ���ڽӶ������ */
int SGraph_next_vertex(SGraph G, S_VertexType v, S_VertexType w) {
	CheckPtr(G);

	int find_index = -1;
	for (int i = 0; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;

		if (G->ves[begin] == v && G->ves[end] == w) {
			find_index = i;
			break;
		}

		if (G->ves[end] == v && G->ves[begin] == w) {
			find_index = i;
			break;
		}
	}

	if (find_index < 0) {
		return -1;
	}

	for (int i = find_index + 1; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;
		if (G->ves[begin] == v && G->ves[end] != w) {
			return end;
		}
		if (G->ves[end] == v && G->ves[begin] != w) {
			return begin;
		}
	}

	return -1;
}

/* ���붥��v��ͼ */
Status SGraph_add_vertex(SGraph G, S_VertexType v) {
	CheckPtr(G);
	if (SGraph_vertex_exist(G, v) || G->numVertexes == MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->numVertexes++;
	G->ves[G->numVertexes - 1] = v;
	return OK;
}

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status SGraph_del_vertex(SGraph G, S_VertexType v) {
	CheckPtr(G);
	int index = SGraph_locate(G, v);
	if (index < 0) {
		return ERROR;
	}
	for (int i = index; i < G->numVertexes; i++) {
		G->ves[i] = G->ves[i + 1];
	}
	G->numVertexes--;
	S_EdgeNode * array = malloc(sizeof(S_EdgeNode) * G->numEdges);
	memcpy(array, G->edges, sizeof array);
	int index, i;
	for (i = 0, index = 0; i < G->numEdges; i++) {
		if (array[i].begin == index || array[i].end == index) {
			continue;
		}
		else {
			G->edges[index].begin = array[i].begin;
			G->edges[index].end = array[i].end;
			G->edges[index].weight = array[i].weight;
			index++;
		}
	}
	G->numEdges = index;
	free(array);
	return OK;
}

/* ���뻡<v,w>��ͼ */
Status SGraph_add_arc(SGraph G, S_VertexType v, S_VertexType w, S_weight weight) {}

/* ɾ����<v,w>��ͼ */
Status SGraph_del_arc(SGraph G, S_VertexType v, S_VertexType w) {}

/* �жϱ��Ƿ���� */
Bool SGraph_arc_exist(SGraph G, S_VertexType v, S_VertexType w) {}

S_EdgeNodePtr SGraph_get_arc(SGraph G, S_VertexType v, S_VertexType w) {}

/* ���رߵ�Ȩֵ */
S_weight SGraph_arc_weight(SGraph G, S_VertexType v, S_VertexType w) {}

/* �����Ƿ���� */
Bool * SGraph_vertex_exist(SGraph G, S_VertexType v) {}

/* ������ȱ��� */
void SGraph_DFS(SGraph G) {}

/* ������ȱ��� */
void SGraph_HFS(SGraph G) {}

/* ��ӡͼ */
void SGraph_print(SGraph G) {}