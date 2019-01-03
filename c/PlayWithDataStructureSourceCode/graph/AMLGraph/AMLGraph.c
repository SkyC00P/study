#include "AMLGraph.h"
#include "../file.c"

static ALMGraph _create_udg(FILE * fp) {
	CheckPtr(fp);
	ALMGraph alm = malloc(sizeof(struct ALM_Graph));
	if (!alm) {
		Exit_with_msg("Out of memory");
	}

	alm->kind = UDG_2;
	alm->numVertexes = _read_int(fp);
	alm->numEdges = _read_int(fp);

	for (int i = 0; i < alm->numVertexes; i++) {
		alm->vers[i].data = _read_ve(fp);
		alm->vers[i].firstEdgeNode = NULL;
	}

	for (int i = 0; i < alm->numEdges; i++) {
		char v1, v1;
		_read_edge_g(fp, &v1, &v2);
		int ivex = ALMGraph_locate(G, v1);
		int jvex = ALMGraph_locate(G, v2);
		if (ivex < 0 || jvex < 0) {
			ALMGraph_destroy(&alm);
			return NULL;
		}
		ALM_EdgeNodePtr ptr = malloc(sizeof(ALM_EdgeNode));
		if (!ptr) {
			Exit_with_msg("Out of memory");
		}
		ptr->ivex = ivex;
		ptr->jvex = jvex;
		ptr->ilink = alm->vers[ivex].firstEdgeNode;
		ptr->jlink = alm->vers[jvex].firstEdgeNode;
		alm->vers[ivex].firstEdgeNode = ptr;
		alm->vers[jvex].firstEdgeNode = ptr;
	}
}
static ALMGraph _create_udn(FILE * fp) {
	CheckPtr(fp);
	ALMGraph alm = malloc(sizeof(struct ALM_Graph));
	if (!alm) {
		Exit_with_msg("Out of memory");
	}

	alm->kind = UDN_3;
	alm->numVertexes = _read_int(fp);
	alm->numEdges = _read_int(fp);

	for (int i = 0; i < alm->numVertexes; i++) {
		alm->vers[i].data = _read_ve(fp);
		alm->vers[i].firstEdgeNode = NULL;
	}

	for (int i = 0; i < alm->numEdges; i++) {
		char v1, v1;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int ivex = ALMGraph_locate(G, v1);
		int jvex = ALMGraph_locate(G, v2);
		if (ivex < 0 || jvex < 0) {
			ALMGraph_destroy(&alm);
			return NULL;
		}
		ALM_EdgeNodePtr ptr = malloc(sizeof(ALM_EdgeNode));
		if (!ptr) {
			Exit_with_msg("Out of memory");
		}
		ptr->ivex = ivex;
		ptr->jvex = jvex;
		ptr->weight = weight;
		ptr->ilink = alm->vers[ivex].firstEdgeNode;
		ptr->jlink = alm->vers[jvex].firstEdgeNode;
		alm->vers[ivex].firstEdgeNode = ptr;
		alm->vers[jvex].firstEdgeNode = ptr;
	}
}
/* 创建图 */
ALMGraph ALMGraph_create(FILE * fp) {
	CheckPtr(fp);

	ALMGraphKind kind = _read_int(fp);
	switch (kind)
	{
	case UDG_2:
		return _create_udg(fp);
	case UDN_3:
		return _create_udn(fp);
	default:
		return NULL;
	}
}

/* 清空图 */
/* 在邻接多重表里清空是需要特别注意的。因为一个边结点有两个引用 */
void ALMGraph_clear(ALMGraph G) {
	if (G) {
		ALM_EdgeNodePtr ptr, p, tmp;
		for (int i = 0; i < G->numVertexes; i++) {
			ptr = G->vers[i].firstEdgeNode;
			while (ptr) {
				tmp = ptr->ilink;
				p = G->vers[ptr->jvex].firstEdgeNode;
				if (p == ptr) {
					G->vers[ptr->jvex].firstEdgeNode = NULL;
				}
				else
				{
					while (1) {
						if (p->ivex == ptr->jvex) {
							if (p->ilink == ptr) {
								p->ilink = ptr->jlink;
								break;
							}
							p = p->ilink;
						}
						else if (p->jvex == ptr->jvex) {
							if (p->jlink == ptr) {
								p->jlink = ptr->jlink;
								break;
							}
							p = p->jlink;
						}
					}
				}
				free(ptr);
				ptr = tmp;
			}
		}
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

/* 销毁图 */
void ALMGraph_destroy(ALMGraph * G) {
	if (*G) {
		ALMGraph_clear(*G);
		free(*G);
		*G = NULL;
	}
}

/* 寻找顶点v的位置。 */
int ALMGraph_locate(ALMGraph G, ALM_VertexType v) {
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->vers[i].data == v) {
			return i;
		}
	}
	return -1;
}

/* 返回第v个结点的值 */
ALM_VertexType ALMGraph_get(ALMGraph G, int order) {
	CheckPtr(G);
	if (order < 0 || order >= G->numVertexes) {
		Exit_with_msg("param:order is error");
	}
	return G->vers[order].data;
}

/* 对顶点v赋值value。 */
void ALMGraph_set(ALMGraph G, ALM_VertexType old, ALM_VertexType new) {
	CheckPtr(G);
	int index = ALMGraph_locate(G, old);
	if (index >= 0) {
		G->vers[index].data = new;
	}
}

/* 返回v的第一个邻接顶点序号 */
int ALMGraph_frist_vertex(ALMGraph G, ALM_VertexType v) {
	CheckPtr(G);
	int index = ALMGraph_locate(G, v);
	if (index < 0) {
		return -1;
	}
	return G->vers[index].firstEdgeNode ? G->vers[index].firstEdgeNode->jvex : -1;
}

/* 返回v相对于w的下一个邻接顶点序号 */
int ALMGraph_next_vertex(ALMGraph G, ALM_VertexType v, ALM_VertexType w) {
	CheckPtr(G);
	int i_v = ALMGraph_locate(G, v);
	int i_w = ALMGraph_locate(G, w);
	if (i_v < 0 || i_w < 0) {
		return -1;
	}
	ALM_EdgeNodePtr ptr = G->vers[i_v].firstEdgeNode;
	if (!ptr) {
		return -1;
	}
	while (ptr) {
		if (ptr->ivex == i_v) {
			if (ptr->jvex == i_w) {
				return ptr->ilink ? ptr->ilink->ivex : -1;
			}
			ptr = ptr->ilink;
		}
		else if (ptr->jvex == i_v) {
			if (ptr->ivex == i_w) {
				return ptr->jlink ? ptr->jlink->jvex : -1;
			}
			ptr = ptr->jlink;
		}
		else {
			ptr = NULL;
		}
	}
	return -1;
}

/* 插入顶点v到图 */
Status ALMGraph_add_vertex(ALMGraph G, ALM_VertexType v) {
	CheckPtr(G);
	if (ALMGraph_vertex_exist(G, v) || G->numVertexes == MAX_VERTEX_NUM) {
		return ERROR;
	}
	G->numVertexes++;
	G->vers[G->numVertexes - 1].data = v;
	G->vers[G->numVertexes - 1].firstEdgeNode = NULL;
	return OK;
}

/* 从图中删除顶点v以及相关的弧 */
Status ALMGraph_del_vertex(ALMGraph G, ALM_VertexType v) {
	CheckPtr(G);
	if (!ALMGraph_vertex_exist(G, v)) {
		return ERROR;
	}
	int index = ALMGraph_locate(G, v);
	ALM_EdgeNodePtr ptr = G->vers[index].firstEdgeNode;
	ALM_EdgeNodePtr tmp;
	while (ptr) {
		if (ptr.ivex == index) {
			tmp = ptr->ilink;
			ALMGraph_del_arc(G, ptr->ivex, ptr->jvex);
			ptr = tmp;
		}
		else if (ptr->jvex == index) {
			tmp = ptr->jlink;
			ALMGraph_del_arc(G, ptr->ivex, ptr->jvex);
			ptr = tmp;
		}
		else {
			ptr = NULL;
		}
	}
	for (int i = index; i < G->numVertexes; i++) {
		G->vers[i].data = G->vers[i + 1].data;
		G->vers[i].firstEdgeNode = G->vers[i + 1].firstEdgeNode;
	}
	G->numVertexes--;
	return OK;
}

/* 插入弧<v,w>到图 */
Status ALMGraph_add_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w, ALM_Weight weight) {
	CheckPtr(G);
	if (ALMGraph_arc_exist(G, v, w)) {
		return ERROR;
	}

	if (!ALMGraph_vertex_exist(G, v) || !ALMGraph_vertex_exist(G, w)) {
		return ERROR;
	}
	int index_v = ALMGraph_locate(G, v);
	int index_w = ALMGraph_locate(G, w);
	ALM_EdgeNodePtr ptr = malloc(sizeof(ALM_EdgeNode));
	if (!ptr) {
		Exit_with_msg("Out of memory");
	}
	ptr->ivex = index_v;
	ptr->jvex = index_w;
	ptr->ilink = G->vers[index_v].firstEdgeNode;
	ptr->jlink = G->vers[index_w].firstEdgeNode;
	G->vers[index_v].firstEdgeNode = ptr;
	G->vers[index_w].firstEdgeNode = ptr;
	G->numEdges++;
	return OK;
}

/* 删除弧<v,w>到图 */
Status ALMGraph_del_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w) {}

/* 判断边是否存在 */
Bool ALMGraph_arc_exist(ALMGraph G, ALM_VertexType v, ALM_VertexType w) {}
ALM_EdgeNodePtr ALMGraph_get_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w) {}

/* 返回边的权值 */
ALM_Weight ALMGraph_arc_weight(ALMGraph G, ALM_VertexType v, ALM_VertexType w) {}

/* 顶点是否存在 */
Bool * ALMGraph_vertex_exist(ALMGraph G, ALM_VertexType v) {}

/* 深度优先遍历 */
void ALMGraph_DFS(ALMGraph G) {}

/* 广度优先遍历 */
void ALMGraph_HFS(ALMGraph G) {}

/* 打印图 */
void ALMGraph_print(ALMGraph G) {}