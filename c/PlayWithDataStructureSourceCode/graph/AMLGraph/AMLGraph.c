#include "AMLGraph.h"
#include "../file.c"

static ALMGraph _create_udg(FILE * fp){
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
	}
}
static ALMGraph _create_udn(FILE * fp) {}
/* 创建图 */
ALMGraph ALMGraph_create(FILE * fp){
	CheckPtr(fp);
	
	ALMGraphKind kind = _read_int(fp);
	switch (kind)
	{
	case UDG_2 :
		return _create_udg(fp);
	case UDN_3:
		return _create_udn(fp);
	default:
		return NULL;
	}
}

/* 清空图 */
void ALMGraph_clear(ALMGraph G){}

/* 销毁图 */
void ALMGraph_destroy(ALMGraph * G){}

/* 寻找顶点v的位置。 */
int ALMGraph_locate(ALMGraph G, ALM_VertexType v){}

/* 返回第v个结点的值 */
ALM_VertexType ALMGraph_get(ALMGraph G, int order){}

/* 对顶点v赋值value。 */
void ALMGraph_set(ALMGraph G, ALM_VertexType old, ALM_VertexType new){}

/* 返回v的第一个邻接顶点序号 */
int ALMGraph_frist_vertex(ALMGraph G, ALM_VertexType v){}

/* 返回v相对于w的下一个邻接顶点序号 */
int ALMGraph_next_vertex(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* 插入顶点v到图 */
Status ALMGraph_add_vertex(ALMGraph G, ALM_VertexType v){}

/* 从图中删除顶点v以及相关的弧 */
Status ALMGraph_del_vertex(ALMGraph G, ALM_VertexType v){}

/* 插入弧<v,w>到图 */
Status ALMGraph_add_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w, AL_Weight weight){}

/* 删除弧<v,w>到图 */
Status ALMGraph_del_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* 判断边是否存在 */
Bool ALMGraph_arc_exist(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}
ALM_EdgeNodePtr ALMGraph_get_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* 返回边的权值 */
ALM_Weight ALMGraph_arc_weight(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* 顶点是否存在 */
Bool * ALMGraph_vertex_exist(ALMGraph G, ALM_VertexType v){}

/* 深度优先遍历 */
void ALMGraph_DFS(ALMGraph G){}

/* 广度优先遍历 */
void ALMGraph_HFS(ALMGraph G){}

/* 打印图 */
void ALMGraph_print(ALMGraph G){}