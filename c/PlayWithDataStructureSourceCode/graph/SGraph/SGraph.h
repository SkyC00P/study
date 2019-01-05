#ifndef HAVE_SGRAPH_H
#define HAVE_SGRAPH_H
#include "common.h"

#define MAX_VERTEX_NUM 20
#define MAX_EDGE_NUM 100

typedef char S_VertexType;
typedef int S_weight;
typedef struct S_EdgeNode {
	int begin, end;
	S_weight weight;
}S_EdgeNode, *S_EdgeNodePtr, S_EdgeArray[MAX_EDGE_NUM];

typedef enum _SGraphKind { DG_0, DN_1, UDG_2, UDN_3 }SGraphKind;		//0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）

typedef struct SGraph {
	S_EdgeArray edges;
	S_VertexType ves[MAX_VERTEX_NUM];
	int numVertexes, numEdges;
	SGraphKind kind;
}*SGraph;

/* 创建图 */
SGraph SGraph_create(FILE * fp);

/* 清空图 */
void SGraph_clear(SGraph G);

/* 销毁图 */
void SGraph_destroy(SGraph * G);

/* 寻找顶点v的位置。 */
int SGraph_locate(SGraph G, S_VertexType v);

/* 返回第v个结点的值 */
S_VertexType SGraph_get(SGraph G, int order);

/* 对顶点v赋值value。 */
void SGraph_set(SGraph G, S_VertexType old, S_VertexType new);

/* 返回v的第一个邻接顶点序号 */
int SGraph_frist_vertex(SGraph G, S_VertexType v);

/* 返回v相对于w的下一个邻接顶点序号 */
int SGraph_next_vertex(SGraph G, S_VertexType v, S_VertexType w);

/* 插入顶点v到图 */
Status SGraph_add_vertex(SGraph G, S_VertexType v);

/* 从图中删除顶点v以及相关的弧 */
Status SGraph_del_vertex(SGraph G, S_VertexType v);

/* 插入弧<v,w>到图 */
Status SGraph_add_arc(SGraph G, S_VertexType v, S_VertexType w, S_weight weight);

/* 删除弧<v,w>到图 */
Status SGraph_del_arc(SGraph G, S_VertexType v, S_VertexType w);

/* 判断边是否存在 */
Bool SGraph_arc_exist(SGraph G, S_VertexType v, S_VertexType w);

S_EdgeNodePtr SGraph_get_arc(SGraph G, S_VertexType v, S_VertexType w);

/* 返回边的权值 */
S_weight SGraph_arc_weight(SGraph G, S_VertexType v, S_VertexType w);

/* 顶点是否存在 */
Bool SGraph_vertex_exist(SGraph G, S_VertexType v);

/* 深度优先遍历 */
void SGraph_DFS(SGraph G);

/* 广度优先遍历 */
void SGraph_HFS(SGraph G);

/* 打印图 */
void SGraph_print(SGraph G);

#endif // !HAVE_SGRAPH_H
