/*
 �ڽӶ��ر��Ƕ�����ͼ���ڽӱ���Ż������ڽӱ��У�һ������Ҫ�����������ʾ������ʵ����(v0,v1) �� (v1,v0)��һ���ģ����Զ��ڱ�Ĵ����ڽӱ�����˷ѿռ������
 ����ʮ�������Ա߱�ṹ���и���[ivex, ilink, jvex, jlink, weight]
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

/* ����ͼ */
ALMGraph ALMGraph_create(FILE * fp);

/* ���ͼ */
void ALMGraph_clear(ALMGraph G);

/* ����ͼ */
void ALMGraph_destroy(ALMGraph * G);

/* Ѱ�Ҷ���v��λ�á� */
int ALMGraph_locate(ALMGraph G, ALM_VertexType v);

/* ���ص�v������ֵ */
ALM_VertexType ALMGraph_get(ALMGraph G, int order);

/* �Զ���v��ֵvalue�� */
void ALMGraph_set(ALMGraph G, ALM_VertexType old, ALM_VertexType new);

/* ����v�ĵ�һ���ڽӶ������ */
int ALMGraph_frist_vertex(ALMGraph G, ALM_VertexType v);

/* ����v�����w����һ���ڽӶ������ */
int ALMGraph_next_vertex(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* ���붥��v��ͼ */
Status ALMGraph_add_vertex(ALMGraph G, ALM_VertexType v);

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status ALMGraph_del_vertex(ALMGraph G, ALM_VertexType v);

/* ���뻡<v,w>��ͼ */
Status ALMGraph_add_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w, AL_Weight weight);

/* ɾ����<v,w>��ͼ */
Status ALMGraph_del_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* �жϱ��Ƿ���� */
Bool ALMGraph_arc_exist(ALMGraph G, ALM_VertexType v, ALM_VertexType w);
ALM_EdgeNodePtr ALMGraph_get_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* ���رߵ�Ȩֵ */
ALM_Weight ALMGraph_arc_weight(ALMGraph G, ALM_VertexType v, ALM_VertexType w);

/* �����Ƿ���� */
Bool * ALMGraph_vertex_exist(ALMGraph G, ALM_VertexType v);

/* ������ȱ��� */
void ALMGraph_DFS(ALMGraph G);

/* ������ȱ��� */
void ALMGraph_HFS(ALMGraph G);

/* ��ӡͼ */
void ALMGraph_print(ALMGraph G);

#endif // !HAVE_ALMGRAPH_H
