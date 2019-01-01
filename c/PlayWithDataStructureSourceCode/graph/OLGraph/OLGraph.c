#include "OLGraph.h"
#include "../file.c"
static OLGraph _create_dg(FILE * fp) {
	CheckPtr(fp);
	OLGraph ol = malloc(sizeof(struct OL_Graph));
	if (!ol) {
		Exit_with_msg("Out of memory");
	}

	ol->kind = DG_0;
	ol->numVertexes = _read_int(fp);
	ol->numEdges = _read_int(fp);

	for (int i = 0; i < ol->numVertexes; i++) {
		ol->vers[i].data = _read_ve(fp);
		ol->vers[i].firstIn = NULL;
		ol->vers[i].firstOut = NULL;
	}

	for (int i = 0; i < ol->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, &v1, &v2);
		int index_out = OLGraph_locate(G, v1);
		int index_in = OLGraph_locate(G, v2);
		if (index_out < 0 || index_in < 0) {
			OLGraph_destroy(&ol);
			return NULL;
		}
		OL_EdgeNodePtr ptr = malloc(sizeof(OL_EdgeNode));
		if (!ptr) {
			Exit_with_msg("Out of memory");
		}
		ptr->tailvex = index_out;
		ptr->headvex = index_in;
		ptr->headlink = ol->vers[index_in].firstIn;
		ptr->taillink = ol->vers[index_out].firstOut;

		ol->vers[index_in].firstIn = ptr;
		ol->vers[index_out].firstOut = ptr;
	}
}

static OLGraph _create_dn(FILE * fp) {
	CheckPtr(fp);
	OLGraph ol = malloc(sizeof(struct OL_Graph));
	if (!ol) { Exit_with_msg("Out of memory"); }
	ol->kind = DN_1;
	ol->numVertexes = _read_int(fp);
	ol->numEdges = _read_int(fp);
	for (int i = 0; i < ol->numVertexes; i++) {
		ol->vers[i].data = _read_ve(fp);
		ol->vers[i].firstIn = NULL;
		ol->vers[i].firstOut = NULL;
	}
	for (int i = 0; i < ol->numEdges; i++) {
		char v1, v2;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int index_out = OLGraph_locate(G, v1);
		int index_in = OLGraph_locate(G, v2);
		if (index_out < 0 || index_in < 0) {
			OLGraph_destroy(&ol);
			return NULL;
		}
		OL_EdgeNodePtr ptr = malloc(sizeof(OL_EdgeNode));
		if (!ptr) {
			Exit_with_msg("Out of memory");
		}
		ptr->tailvex = index_out;
		ptr->headvex = index_in;
		ptr->weight = weight;
		ptr->headlink = ol->vers[index_in].firstIn;
		ptr->taillink = ol->vers[index_out].firstOut;

		ol->vers[index_in].firstIn = ptr;
		ol->vers[index_out].firstOut = ptr;
	}
}
/* 创建图 */
OLGraph OLGraph_create(FILE * fp) {
	CheckPtr(fp);

	OLGraphKind kind = _read_int(fp);
	switch (kind)
	{
	case DG_0:
		return _create_dg(fp);
	case DN_1:
		return _create_dn(fp);
	default:
		return NULL;
	}
}

/* 清空图 */
void OLGraph_clear(OLGraph G) {
	if (G)
	{
		OL_EdgeNodePtr ptr, tmp;
		for (int i = 0; i < G->numVertexes; i++) {
			ptr = G->vers[i].firstOut;

			while (ptr) {
				tmp = ptr->taillink;
				free(ptr);
				ptr = tmp;
			}
			G->vers[i].firstIn = NULL;
			G->vers[i].firstOut = NULL;
		}
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* 销毁图 */
void OLGraph_destroy(OLGraph * G) {
	if (*G) {
		OLGraph_clear(*G);
		free(*G);
		*G = NULL;
	}
}

/* 寻找顶点v的位置。 */
int OLGraph_locate(OLGraph G, OL_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->vers[i].data == v) {
			return i;
		}
	}
	return -1;
}

/* 返回第v个结点的值 */
OL_VertexType OLGraph_get(OLGraph G, int order) {
	CheckPtr(G);
	if (order < 0 || order >= G->numVertexes) {
		Exit_with_msg("param:order is error");
	}
	return G->vers[order].data;
}

/* 对顶点v赋值value。 */
void OLGraph_set(OLGraph G, OL_VertexType old, OL_VertexType new) {
	CheckPtr(G);
	int index = OLGraph_locate(G, old);
	if (index >= 0) {
		G->vers[index].data = new;
	}
}

/* 返回v的第一个邻接顶点序号 */
int OLGraph_frist_vertex(OLGraph G, OL_VertexType v) {
	CheckPtr(G);
	int index = OLGraph_locate(G, v);
	if (index < 0) {
		return -1;
	}
	if (G->vers[index].firstOut) {
		return G->vers[index].firstOut->headvex;
	}

	if (G->vers[index].firstIn) {
		return G->vers[index].firstIn->tailvex;
	}
}

/* 返回v相对于w的下一个邻接顶点序号 */
int OLGraph_next_vertex(OLGraph G, OL_VertexType v, OL_VertexType w) {
	CheckPtr(G);
	int index_v = OLGraph_locate(G, v);
	int index_w = OLGraph_locate(G, w);
	if (index_v < 0 || index_w < 0) {
		return -1;
	}
	OL_EdgeNodePtr ptr = G->vers[index_v].firstIn;
	Bool find_it = FALSE;
	while (ptr) {
		if (ptr->tailvex == index_w) {
			find_it = TRUE;
			break;
		}
		else {
			ptr = ptr->headlink;
		}
	}
	if (!find_it) {
		ptr = G->vers[index_v].firstOut;
		while (ptr) {
			if (ptr->headvex == index_w) {
				find_it = TRUE;
				break;
			}
			else {
				ptr = ptr->taillink;
			}
		}

		return find_it && ptr->taillink ? ptr->taillink->headvex : -1;
	}
	else {
		return ptr->headlink ? ptr->headlink->tailvex : -1;
	}
}

/* 插入顶点v到图 */
Status OLGraph_add_vertex(OLGraph G, OL_VertexType v) {
	CheckPtr(G);
	if (OLGraph_arc_exist(G, v) || G->numVertexes == MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->numVertexes++;
	G->vers[G->numVertexes - 1].data = v;
	G->vers[G->numVertexes - 1].firstIn = NULL;
	G->vers[G->numVertexes - 1].firstOut = NULL;
}

/* 从图中删除顶点v以及相关的弧 */
Status OLGraph_del_vertex(OLGraph G, OL_VertexType v) {
	CheckPtr(G);
	if (!OLGraph_vertex_exist(G, v)) {
		return  ERROR;
	}
	int index = OLGraph_locate(G, v);

}

/* 插入弧<v,w>到图 */
Status OLGraph_add_arc(OLGraph G, OL_VertexType v, OL_VertexType w, AL_Weight weight) {}

/* 删除弧<v,w>到图 */
Status OLGraph_del_arc(OLGraph G, OL_VertexType v, OL_VertexType w) {}

/* 判断边是否存在 */
Bool OLGraph_arc_exist(OLGraph G, OL_VertexType v, OL_VertexType w) {}

/* 返回边的权值 */
OL_Weight OLGraph_arc_weight(OLGraph G, OL_VertexType v, OL_VertexType w) {}

Bool OLGraph_vertex_exist(OLGraph G, OL_VertexType v)
{
	CheckPtr(G);
	if (G->numVertexes == 0) {
		return FALSE;
	}

	for (int i = 0; i < G->numVertexes; i++) {
		if (G->vers[i].data == v) {
			return TRUE;
		}
	}
	return FALSE;
}

/* 深度优先遍历 */
void OLGraph_DFS(OLGraph G) {}

/* 广度优先遍历 */
void OLGraph_HFS(OLGraph G) {}

/* 打印图 */
void OLGraph_print(OLGraph G) {}