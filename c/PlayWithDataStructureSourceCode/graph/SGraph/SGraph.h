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

typedef enum _SGraphKind { DG_0, DN_1, UDG_2, UDN_3 }SGraphKind;		//0-����ͼ��1-����������Ȩֵ����2-����ͼ��3-����������Ȩֵ��

typedef struct SGraph {
	S_EdgeArray edges;
	S_VertexType ves[MAX_VERTEX_NUM];
	int numVertexes, numEdges;
	SGraphKind kind;
}*SGraph;

/* ����ͼ */
SGraph SGraph_create(FILE * fp);

/* ���ͼ */
void SGraph_clear(SGraph G);

/* ����ͼ */
void SGraph_destroy(SGraph * G);

/* Ѱ�Ҷ���v��λ�á� */
int SGraph_locate(SGraph G, S_VertexType v);

/* ���ص�v������ֵ */
S_VertexType SGraph_get(SGraph G, int order);

/* �Զ���v��ֵvalue�� */
void SGraph_set(SGraph G, S_VertexType old, S_VertexType new);

/* ����v�ĵ�һ���ڽӶ������ */
int SGraph_frist_vertex(SGraph G, S_VertexType v);

/* ����v�����w����һ���ڽӶ������ */
int SGraph_next_vertex(SGraph G, S_VertexType v, S_VertexType w);

/* ���붥��v��ͼ */
Status SGraph_add_vertex(SGraph G, S_VertexType v);

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status SGraph_del_vertex(SGraph G, S_VertexType v);

/* ���뻡<v,w>��ͼ */
Status SGraph_add_arc(SGraph G, S_VertexType v, S_VertexType w, S_weight weight);

/* ɾ����<v,w>��ͼ */
Status SGraph_del_arc(SGraph G, S_VertexType v, S_VertexType w);

/* �жϱ��Ƿ���� */
Bool SGraph_arc_exist(SGraph G, S_VertexType v, S_VertexType w);

S_EdgeNodePtr SGraph_get_arc(SGraph G, S_VertexType v, S_VertexType w);

/* ���رߵ�Ȩֵ */
S_weight SGraph_arc_weight(SGraph G, S_VertexType v, S_VertexType w);

/* �����Ƿ���� */
Bool * SGraph_vertex_exist(SGraph G, S_VertexType v);

/* ������ȱ��� */
void SGraph_DFS(SGraph G);

/* ������ȱ��� */
void SGraph_HFS(SGraph G);

/* ��ӡͼ */
void SGraph_print(SGraph G);

#endif // !HAVE_SGRAPH_H
