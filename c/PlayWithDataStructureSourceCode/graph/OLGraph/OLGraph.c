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
// 解法:1. 删除该顶点的所有弧 2. 释放顶点 3. 顶点数减一
Status OLGraph_del_vertex(OLGraph G, OL_VertexType v) {
	CheckPtr(G);
	if (!OLGraph_vertex_exist(G, v)) {
		return  ERROR;
	}
	int index = OLGraph_locate(G, v);
	OL_EdgeNodePtr in_ptr = G->vers[index].firstIn;
	OL_EdgeNodePtr out_ptr = G->vers[index].firstOut;
	OL_EdgeNodePtr tmp;
	while (in_ptr) {
		tmp = in_ptr->headlink
			OLGraph_del_arc(G, in_ptr->tailvex, in_ptr->headvex);
		in_ptr = tmp;
	}
	while (out_ptr) {
		tmp = out_ptr->taillink;
		OLGraph_del_arc(G, out_ptr->tailvex, out_ptr->headvex);
		out_ptr = tmp;
	}

	for (int i = index; i < G->numVertexes; i++) {
		G->vers[i].data = G->vers[i + 1].data;
		G->vers[i].firstIn = G->vers[i + 1].firstIn;
		G->vers[i].firstOut = G->vers[i + 1].firstOut;
	}

	G->numVertexes--;
	return OK;
}

/* 插入弧<v,w>到图 */
Status OLGraph_add_arc(OLGraph G, OL_VertexType v, OL_VertexType w, OL_Weight weight) {
	CheckPtr(G);
	if (OLGraph_arc_exist(G, v, w)) {
		return ERROR;
	}
	if (!OLGraph_vertex_exist(G, v) || !OLGraph_vertex_exist(G, w)) {
		return ERROR;
	}
	int vex_tail = OLGraph_locate(G, v);
	int vex_head = OLGraph_locate(G, w);
	OL_EdgeNodePtr ptr = malloc(sizeof(OL_EdgeNode));
	if (!ptr) {
		Exit_with_msg("Out of memory");
	}
	ptr->tailvex = vex_tail;
	ptr->headvex = vex_head;
	ptr->headlink = G->vers[vex_head].firstIn;
	ptr->taillink = G->vers[vex_tail].firstOut;

	ol->vers[vex_head].firstIn = ptr;
	ol->vers[vex_tail].firstOut = ptr;
	G->numEdges++;
	return OK;
}

/* 删除弧<v,w>到图 */
Status OLGraph_del_arc(OLGraph G, OL_VertexType v, OL_VertexType w) {
	CheckPtr(G);
	OL_EdgeNodePtr delPtr = OLGraph_get_arc(G, v, w);
	if (!delPtr) {
		return ERROR;
	}
	OL_EdgeNodePtr del_ptr_bef;
	OL_EdgeNodePtr ptr = G->vers[delPtr->tailvex].firstOut;
	if (ptr == delPtr) {
		G->vers[delPtr->tailvex].firstOut = ptr->taillink;
	}
	else {
		while (ptr != delPtr) {
			del_ptr_bef = ptr;
			ptr = ptr->taillink;
		}
		del_ptr_bef = delPtr->taillink;
		delPtr->taillink = NULL;
	}

	ptr = G->vers[delPtr->headvex].firstIn;
	if (ptr == delPtr) {
		G->vers[delPtr->headvex].firstIn = ptr->headlink;
	}
	else
	{
		while (ptr != delPtr) {
			del_ptr_bef = ptr;
			ptr = ptr->headlink;
		}
		del_ptr_bef->headlink = delPtr->headlink;
		delPtr->headlink = NULL;
	}
	free(delPtr);
	G->numEdges--;
	return OK;
}

/* 判断边是否存在 */
Bool OLGraph_arc_exist(OLGraph G, OL_VertexType v, OL_VertexType w) {
	CheckPtr(G);
	return OLGraph_get_arc(G, v, w);
}

OL_EdgeNodePtr OLGraph_get_arc(OLGraph G, OL_VertexType v, OL_VertexType w) {
	CheckPtr(G);
	if (G->numEdges == 0) {
		return NULL;
	}
	int index = OLGraph_locate(G, v);
	if (index < 0) {
		return NULL;
	}

	OL_EdgeNodePtr ptr = G->vers[index].firstOut;
	OL_EdgeNodePtr tmp;
	while (ptr) {
		tmp = ptr->taillink;
		if (G->vers[ptr->headvex].data == w) {
			return ptr;
		}
		ptr = tmp;
	}
	return NULL;
}

/* 返回边的权值 */
OL_Weight OLGraph_arc_weight(OLGraph G, OL_VertexType v, OL_VertexType w) {
	CheckPtr(G);
	OL_EdgeNodePtr ptr = OLGraph_get_arc(G, v, w);
	if (!ptr) {
		Exit_with_msg("no exist arc.");
	}
	return ptr->weight;
}

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
void OLGraph_print(OLGraph G) {
	if (G) {
		char * kindMsg;
		switch (G->kind)
		{
		case DG_0:kindMsg = "DG-0-有向图"; break;
		case DN_1:kindMsg = "DN-1-有向网（带权值）"; break;
		default:
			kindMsg = "unkonwn kind";
			break;
		}
		printf("顶点数:%d, 边集数:%d, 类型:%s\n", G->numVertexes, G->numEdges, kindMsg);
		for (int i = 0; i < G->numVertexes; i++) {
			printf("[%d]顶点: %c \n\tfirstIn:", i, G->vers[i].data);
			OL_EdgeNodePtr ptr = G->vers[i].firstIn;
			while (ptr)
			{
				printf("%c<-%c=%d ", G->vers[ptr->headvex].data, G->vers[ptr->tailvex].data, ptr->weight);
				ptr = ptr->headlink;
			}
			printf("\n\tfirstOut:");
			ptr = G->vers[i].firstOut;
			while (ptr) {
				printf("%c->%c=%d ", G->vers[ptr->tailvex].data, G->vers[ptr->headvex].data, ptr->weight);
				ptr = ptr->taillink;
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		printf("空图\n");
	}

}