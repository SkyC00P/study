/*
 邻接矩阵用两个数组来保存图的信息。一个一维数组来保存顶点信息，一个二维数组来保存边集信息
*/
#ifndef  HAVE_MGRAPH_H
#define HAVE_MGRAPH_H
#include "common.h"
#include <limits.h>

#define MAX_VERTEX_NUM 20							//  顶点最大的值
#define INFINITY INT_MAX							//  无穷大
typedef char MG_VertexType;							//  顶点类型
typedef int MG_Weight;								//  权值类型
typedef enum _MGraphKind { DG, DN, UDG, UDN }MGraphKind;		//0-有向图，1-有向网（带权值），2-无向图，3-无向网（带权值）

typedef struct _MGraph {
	MG_VertexType vexs[MAX_VERTEX_NUM];
	MG_Weight arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int numVertexes, numEdges;
	MGraphKind kind;
}_MGraph, *MGraphPtr;

typedef _MGraph * MGraph;

/* 创建图 */
MGraph MGraph_create(FILE * fp);

/* 清空图 */
void MGraph_clear(MGraph G);

/* 销毁图 */
void MGraph_destroy(MGraph G);

/* 寻找顶点v的位置。 */
int MGraph_locate(MGraph G, MG_VertexType v);

/* 返回第v个结点的值 */
MG_VertexType MGraph_get(MGraph G, int order);

/* 对顶点v赋值value。 */
void MGraph_set(MGraph G, MG_VertexType old, MG_VertexType new);

/* 返回v的第一个邻接顶点序号 */
int MGraph_frist_vertex(MGraph G, MG_VertexType v);

/* 返回v相对于w的下一个邻接顶点序号 */
int MGraph_next_vertex(MGraph G, MG_VertexType v, MG_VertexType w);

/* 插入顶点v到图 */
Status MGraph_add_vertex(MGraph G, MG_VertexType v);

/* 从图中删除顶点v以及相关的弧 */
Status MGraph_del_vertex(MGraph G, MG_VertexType v);

/* 插入弧<v,w>到图 */
Status MGraph_add_arc(MGraph G, MG_VertexType v, MG_VertexType w);

/* 删除弧<v,w>到图 */
Status MGraph_del_arc(MGraph G, MG_VertexType v, MG_VertexType w);

/* 深度优先遍历 */
void MGraph_DFS(MGraph G);

/* 广度优先遍历 */
void MGraph_HFS(MGraph G);

/* 打印图 */
void MGraph_print(MGraph G);

#endif // ! HAVE_MGRAPH_H
