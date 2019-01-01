/*
 十字链表是为了解决邻接表在有向图中一个顶点只能知晓单方向的弧，即入度和出度只能存其一。
 十字链表修改了顶点表结构为 [data, firstIn, firstOut],边表结点为 [tailvex, headvex, headlink, taillink]
 可以看做十字链表是对有向图的邻接表的优化。
*/
#ifndef HAVE_OLGRAPH_H
#define HAVE_OLGRAPH_H
#include "common.h"

#define MAX_VERTEX_NUM 20
typedef char OL_VertexType;
typedef int OL_Weight;

typedef struct OL_EdgeNode {
	int tailvex, headvex;
	OL_Weight weight;
	struct OL_EdgeNode *headlink;
	struct OL_EdgeNode *taillink;
}OL_EdgeNode, * OL_EdgeNodePtr;

typedef struct OL_VertexNode {
	OL_VertexType data;
	OL_EdgeNodePtr firstIn;
	OL_EdgeNodePtr firstOut;
}OL_VertexNode, OL_Array[MAX_VERTEX_NUM];

typedef enum OLGraphKind {DG_0 , DN_1} OLGraphKind;

typedef struct OL_Graph {
	OL_Array vers;
	int numVertexes, numEdges;
	OLGraphKind kind;
}*OLGraph;

/* 创建图 */
OLGraph OLGraph_create(FILE * fp);

/* 清空图 */
void OLGraph_clear(OLGraph G);

/* 销毁图 */
void OLGraph_destroy(OLGraph * G);

/* 寻找顶点v的位置。 */
int OLGraph_locate(OLGraph G, OL_VertexType v);

/* 返回第v个结点的值 */
OL_VertexType OLGraph_get(OLGraph G, int order);

/* 对顶点v赋值value。 */
void OLGraph_set(OLGraph G, OL_VertexType old, OL_VertexType new);

/* 返回v的第一个邻接顶点序号 */
int OLGraph_frist_vertex(OLGraph G, OL_VertexType v);

/* 返回v相对于w的下一个邻接顶点序号 */
int OLGraph_next_vertex(OLGraph G, OL_VertexType v, OL_VertexType w);

/* 插入顶点v到图 */
Status OLGraph_add_vertex(OLGraph G, OL_VertexType v);

/* 从图中删除顶点v以及相关的弧 */
Status OLGraph_del_vertex(OLGraph G, OL_VertexType v);

/* 插入弧<v,w>到图 */
Status OLGraph_add_arc(OLGraph G, OL_VertexType v, OL_VertexType w, AL_Weight weight);

/* 删除弧<v,w>到图 */
Status OLGraph_del_arc(OLGraph G, OL_VertexType v, OL_VertexType w);

/* 判断边是否存在 */
Bool OLGraph_arc_exist(OLGraph G, OL_VertexType v, OL_VertexType w);

/* 返回边的权值 */
OL_Weight OLGraph_arc_weight(OLGraph G, OL_VertexType v, OL_VertexType w);

/* 深度优先遍历 */
void OLGraph_DFS(OLGraph G);

/* 广度优先遍历 */
void OLGraph_HFS(OLGraph G);

/* 打印图 */
void OLGraph_print(OLGraph G);

#endif // !HAVE_OLGRAPH_H