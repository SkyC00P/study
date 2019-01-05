#include "SGraph.h"
#include "../file.c"
#include <string.h>

/* 创建图 */
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

/* 清空图 */
void SGraph_clear(SGraph G) {
	if (G) {
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* 销毁图 */
void SGraph_destroy(SGraph * G) {
	if (*G) {
		free(*G);
		*G = NULL;
	}
}

/* 寻找顶点v的位置。 */
int SGraph_locate(SGraph G, S_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->ves[i] == v) {
			return i;
		}
	}
	return -1;
}

/* 返回第v个结点的值 */
S_VertexType SGraph_get(SGraph G, int order) {
	CheckPtr(G);
	if (order < 0 || order >= G->numVertexes) {
		Exit_with_msg("param:order is error");
	}
	return G->ves[order];
}

/* 对顶点v赋值value。 */
void SGraph_set(SGraph G, S_VertexType old, S_VertexType new) {
	CheckPtr(G);
	int index = SGraph_locate(G, old);
	if (index >= 0) {
		G->ves[index] = new;
	}
}

/* 返回v的第一个邻接顶点序号 */
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

/* 返回v相对于w的下一个邻接顶点序号 */
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

/* 插入顶点v到图 */
Status SGraph_add_vertex(SGraph G, S_VertexType v) {
	CheckPtr(G);
	if (SGraph_vertex_exist(G, v) || G->numVertexes == MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->numVertexes++;
	G->ves[G->numVertexes - 1] = v;
	return OK;
}

/* 从图中删除顶点v以及相关的弧 */
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

/* 插入弧<v,w>到图 */
Status SGraph_add_arc(SGraph G, S_VertexType v, S_VertexType w, S_weight weight) {
	CheckPtr(G);
	if (SGraph_arc_exist(G, v, w)) {
		return ERROR;
	}

	int vex_v = SGraph_locate(G, v);
	int vex_w = SGraph_locate(G, w);
	if (vex_v < 0 || vex_w < 0) {
		return ERROR;
	}

	G->edges[G->numEdges].begin = vex_v;
	G->edges[G->numEdges].end = vex_w;
	G->edges[G->numEdges].weight = weight;
	G->numEdges++;
	return OK;
}

/* 删除弧<v,w>到图 */
Status SGraph_del_arc(SGraph G, S_VertexType v, S_VertexType w) {
	CheckPtr(G);
	int vex_v = SGraph_locate(G, v);
	int vex_w = SGraph_locate(G, w);
	if (vex_v < 0 || vex_v < 0) {
		return ERROR;
	}
	int index = -1;
	Bool hasDirection = G->kind == DG_0 || G->kind == DN_1;
	for (int i = 0; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;
		if (begin == vex_v && end == vex_w) {
			index = i;
			break;
		}
		if (!hasDirection && begin == vex_w && end == vex_v) {
			index = i;
			break;
		}
	}
	if (index >= 0) {
		for (int i = index; i < G->numEdges; i++) {
			G->edges[i].begin = G->edges[i + 1].begin;
			G->edges[i].end = G->edges[i + 1].end;
			G->edges[i].weight = G->edges[i + 1].weight;
		}
		G->numEdges--;
		return OK;
	}
	return ERROR;
}

/* 判断边是否存在 */
Bool SGraph_arc_exist(SGraph G, S_VertexType v, S_VertexType w) {
	CheckPtr(G);
	if (G->numEdges == 0) {
		return FALSE;
	}
	Bool hasDirection = G->kind == DG_0 || G->kind == DN_1;
	for (int i = 0; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;
		if (G->ves[begin] == v && G->ves[end] == w) {
			return TRUE;
		}
		if (!hasDirection && G->ves[begin] == w && G->ves[end] == v) {
			return TRUE;
		}
	}
	return FALSE;
}

S_EdgeNodePtr SGraph_get_arc(SGraph G, S_VertexType v, S_VertexType w) {
	CheckPtr(G);
	if (G->numEdges == 0) {
		return NULL;
	}
	Bool hasDirection = G->kind == DG_0 || G->kind == DN_1;
	for (int i = 0; i < G->numEdges; i++) {
		int begin = G->edges[i].begin;
		int end = G->edges[i].end;
		if (G->ves[begin] == v && G->ves[end] == w) {
			return G->edges[i];
		}
		if (!hasDirection && G->ves[begin] == w && G->ves[end] == v) {
			return G->edges[i];
		}
	}
	return NULL;
}

/* 返回边的权值 */
S_weight SGraph_arc_weight(SGraph G, S_VertexType v, S_VertexType w) {
	CheckPtr(G);
	S_EdgeNodePtr ptr = SGraph_get_arc(G, v, w);
	if (!ptr) {
		Exit_with_msg("no exist arc.");
	}
	return ptr->weight:
}

/* 顶点是否存在 */
Bool SGraph_vertex_exist(SGraph G, S_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->ves[i] == v) {
			return TRUE;
		}
	}
	return FALSE;
}

/* 深度优先遍历 */
void SGraph_DFS(SGraph G) {}

/* 广度优先遍历 */
void SGraph_HFS(SGraph G) {}

/* 打印图 */
void SGraph_print(SGraph G) {
	if (G) {
		char * kindMsg;
		switch (G->kind)
		{
		case DG_0:kindMsg = "DG-0-有向图"; break;
		case DN_1:kindMsg = "DN-1-有向网（带权值）"; break;
		case UDG_2:kindMsg = "UDG-2-无向图"; break;
		case UDN_3:kindMsg = "UDN-3-无向网（带权值）"; break;
		default:
			kindMsg = "unkonwn kind";
			break;
		}
		printf("顶点数:%d, 边集数:%d, 类型:%s\n", G->numVertexes, G->numEdges, kindMsg);
		printf("顶点数组:");
		for (int i = 0; i < G->numVertexes; i++) {
			printf("%c ", G->ves[i]);
		}
		printf("\n边数组");
		printf("%9c  begin  end  weight");
		for (int i = 0; i < G->numEdges; i++) {
			S_EdgeNodePtr p = G->edges[i];
			printf("edges[%2d]  %2d  %2d  %2d\n", i, p->begin, p->end, p->weight);
		}
		printf("\n");
	}
	else
	{
		printf("空图\n");
	}
}