/*
 用数组来保存顶点，列表来表示边集，这种数组和链表相结合的存储方法叫做邻接表
*/
#ifndef HAVE_ALGRAPH_H
#define HAVE_ALGRAPH_H
#include "common.h"
#define MAX_ALG_VERTEX_NUM 10						//  顶点最大的值

typedef char AL_VertexType;							//  顶点类型
typedef int AL_Weight;								//  权值类型

typedef struct EdgeNode {
	int adjvex;
	AL_Weight weight;
	struct EdgeNode * next;
}EdgeNode, *EdgeNodePtr;

typedef struct VertexNode {
	AL_VertexType data;
	EdgeNodePtr firstEdge;
}VertexNode, AdjList[MAX_ALG_VERTEX_NUM];

typedef enum ALGraphKind { DG_0, DN_1, UDG_2, UDN_3 }ALGraphKind;					//0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）

typedef struct ALGraph {
	AdjList adlist;
	int numVertexes, numEdges;
	ALGraphKind kind;
}*ALGraph;

/* 创建图 */
ALGraph ALGraph_create(FILE * fp);

/* 清空图 */
void ALGraph_clear(ALGraph G);

/* 销毁图 */
void ALGraph_destroy(ALGraph * G);

/* 寻找顶点v的位置。 */
int ALGraph_locate(ALGraph G, AL_VertexType v);

/* 返回第v个结点的值 */
AL_VertexType ALGraph_get(ALGraph G, int order);

/* 对顶点v赋值value。 */
void ALGraph_set(ALGraph G, AL_VertexType old, AL_VertexType new);

/* 返回v的第一个邻接顶点序号 */
int ALGraph_frist_vertex(ALGraph G, AL_VertexType v);

/* 返回v相对于w的下一个邻接顶点序号 */
int ALGraph_next_vertex(ALGraph G, AL_VertexType v, AL_VertexType w);

/* 插入顶点v到图 */
Status ALGraph_add_vertex(ALGraph G, AL_VertexType v);

/* 从图中删除顶点v以及相关的弧 */
Status ALGraph_del_vertex(ALGraph G, AL_VertexType v);

/* 插入弧<v,w>到图 */
Status ALGraph_add_arc(ALGraph G, AL_VertexType v, AL_VertexType w, AL_Weight weight);

/* 删除弧<v,w>到图 */
Status ALGraph_del_arc(ALGraph G, AL_VertexType v, AL_VertexType w);

/* 判断边是否存在 */
Bool ALGraph_arc_exist(ALGraph G, AL_VertexType v, AL_VertexType w);

/* 返回边的权值 */
AL_Weight ALGraph_arc_weight(ALGraph G, AL_VertexType v, AL_VertexType w);

/* 深度优先遍历 */
void ALGraph_DFS(ALGraph G);

/* 广度优先遍历 */
void ALGraph_HFS(ALGraph G);

/* 打印图 */
void ALGraph_print(ALGraph G);
#endif // !HAVE_ALGRAPH_H
