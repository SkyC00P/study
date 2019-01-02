/*
 邻接多重表是对无向图的邻接表的优化，在邻接表中，一条边需要两个结点来表示，但是实际上(v0,v1) 跟 (v1,v0)是一样的，所以对于表的处理，邻接表存在浪费空间的问题
 仿造十字链表，对边表结构进行改造[ivex, ilink, jvex, jlink, weight]
*/
#ifndef HAVE_ALMGRAPH_H
#define HAVE_ALMGRAPH_H
#include "common.h"

#define MAX_VERTEX_NUM 20
typedef char ALM_VertexType;
typedef int ALM_Weight;

typedef struct ALM_EdgeNode {
	int ivex, jvex;
	struct ALM_EdgeNode * ilink;
	struct ALM_EdgeNode * jlink;
	ALM_Weight weight;
}ALM_EdgeNode, *ALM_EdgeNodePtr;

typedef struct ALM_VertexNode {
	ALM_VertexType data;
	ALM_EdgeNodePtr firstEdgeNode;
}ALM_VertexNode, ALM_Array[MAX_VERTEX_NUM];

typedef enum ALMGraphKind { UDG_2 = 2, UDN_3 = 3 } ALMGraphKind;

typedef struct ALM_Graph {
	ALM_Array vers;
	int numVertexes, numEdges;
	ALMGraphKind kind;
}* ALMGraph;

/* 创建图 */
ALMGraph ALMGraph_create(FILE * fp);

/* 清空图 */
void ALMGraph_clear(ALMGraph G);

/* 销毁图 */
void ALMGraph_destroy(ALMGraph * G);

/* 寻找顶点v的位置。 */
int ALMGraph_locate(ALMGraph G, ALM_VertexType v);

/* 返回第v个结点的值 */
ALM_VertexType ALMGraph_get(ALMGraph G, int order);

/* 对顶点v赋值value。 */
void ALMGraph_set(ALMGraph G, ALM_VertexType old, ALM_VertexType new);

/* 返回v的第一个邻接顶点序号 */
int ALMGraph_frist_vertex(ALMGraph G, ALM_VertexType v);

/* 返回v相对于w的下一个邻接顶点序号 */
int ALMGraph_next_vertex(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* 插入顶点v到图 */
Status ALMGraph_add_vertex(ALMGraph G, ALM_VertexType v);

/* 从图中删除顶点v以及相关的弧 */
Status ALMGraph_del_vertex(ALMGraph G, ALM_VertexType v);

/* 插入弧<v,w>到图 */
Status ALMGraph_add_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w, AL_Weight weight);

/* 删除弧<v,w>到图 */
Status ALMGraph_del_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* 判断边是否存在 */
Bool ALMGraph_arc_exist(ALMGraph G, ALM_VertexType v, ALM_VertexType w);
ALM_EdgeNodePtr ALMGraph_get_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* 返回边的权值 */
ALM_Weight ALMGraph_arc_weight(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* 顶点是否存在 */
Bool * ALMGraph_vertex_exist(ALMGraph G, ALM_VertexType v);

/* 深度优先遍历 */
void ALMGraph_DFS(ALMGraph G);

/* 广度优先遍历 */
void ALMGraph_HFS(ALMGraph G);

/* 打印图 */
void ALMGraph_print(ALMGraph G);

#endif // !HAVE_ALMGRAPH_H
