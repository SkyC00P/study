/*
 �ڽӾ�������������������ͼ����Ϣ��һ��һά���������涥����Ϣ��һ����ά����������߼���Ϣ
*/
#ifndef  HAVE_MGRAPH_H
#define HAVE_MGRAPH_H
#include "common.h"
#include <limits.h>

#define MAX_VERTEX_NUM 20							//  ��������ֵ
#define INFINITY INT_MAX							//  �����
typedef char MG_VertexType;							//  ��������
typedef int MG_Weight;								//  Ȩֵ����
typedef enum _MGraphKind { DG, DN, UDG, UDN }MGraphKind;		//0-����ͼ��1-����������Ȩֵ����2-����ͼ��3-����������Ȩֵ��

typedef struct _MGraph {
	MG_VertexType vexs[MAX_VERTEX_NUM];
	MG_Weight arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int numVertexes, numEdges;
	MGraphKind kind;
}_MGraph, *MGraphPtr;

typedef _MGraph * MGraph;

/* ����ͼ */
MGraph MGraph_create(FILE * fp);

/* ���ͼ */
void MGraph_clear(MGraph G);

/* ����ͼ */
void MGraph_destroy(MGraph G);

/* Ѱ�Ҷ���v��λ�á� */
int MGraph_locate(MGraph G, MG_VertexType v);

/* ���ص�v������ֵ */
MG_VertexType MGraph_get(MGraph G, int order);

/* �Զ���v��ֵvalue�� */
void MGraph_set(MGraph G, MG_VertexType old, MG_VertexType new);

/* ����v�ĵ�һ���ڽӶ������ */
int MGraph_frist_vertex(MGraph G, MG_VertexType v);

/* ����v�����w����һ���ڽӶ������ */
int MGraph_next_vertex(MGraph G, MG_VertexType v, MG_VertexType w);

/* ���붥��v��ͼ */
Status MGraph_add_vertex(MGraph G, MG_VertexType v);

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status MGraph_del_vertex(MGraph G, MG_VertexType v);

/* ���뻡<v,w>��ͼ */
Status MGraph_add_arc(MGraph G, MG_VertexType v, MG_VertexType w);

/* ɾ����<v,w>��ͼ */
Status MGraph_del_arc(MGraph G, MG_VertexType v, MG_VertexType w);

/* ������ȱ��� */
void MGraph_DFS(MGraph G);

/* ������ȱ��� */
void MGraph_HFS(MGraph G);

/* ��ӡͼ */
void MGraph_print(MGraph G);

#endif // ! HAVE_MGRAPH_H
