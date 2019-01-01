#include "OLGraph.h"
#include "../file.c"

/* ����ͼ */
OLGraph OLGraph_create(FILE * fp){
	CheckPtr(fp);
}

/* ���ͼ */
void OLGraph_clear(OLGraph G){}

/* ����ͼ */
void OLGraph_destroy(OLGraph * G){}

/* Ѱ�Ҷ���v��λ�á� */
int OLGraph_locate(OLGraph G, OL_VertexType v){}

/* ���ص�v������ֵ */
OL_VertexType OLGraph_get(OLGraph G, int order){}

/* �Զ���v��ֵvalue�� */
void OLGraph_set(OLGraph G, OL_VertexType old, OL_VertexType new){}

/* ����v�ĵ�һ���ڽӶ������ */
int OLGraph_frist_vertex(OLGraph G, OL_VertexType v){}

/* ����v�����w����һ���ڽӶ������ */
int OLGraph_next_vertex(OLGraph G, OL_VertexType v, OL_VertexType w){}

/* ���붥��v��ͼ */
Status OLGraph_add_vertex(OLGraph G, OL_VertexType v){}

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status OLGraph_del_vertex(OLGraph G, OL_VertexType v){}

/* ���뻡<v,w>��ͼ */
Status OLGraph_add_arc(OLGraph G, OL_VertexType v, OL_VertexType w, AL_Weight weight){}

/* ɾ����<v,w>��ͼ */
Status OLGraph_del_arc(OLGraph G, OL_VertexType v, OL_VertexType w){}

/* �жϱ��Ƿ���� */
Bool OLGraph_arc_exist(OLGraph G, OL_VertexType v, OL_VertexType w){}

/* ���رߵ�Ȩֵ */
OL_Weight OLGraph_arc_weight(OLGraph G, OL_VertexType v, OL_VertexType w){}

/* ������ȱ��� */
void OLGraph_DFS(OLGraph G){}

/* ������ȱ��� */
void OLGraph_HFS(OLGraph G){}

/* ��ӡͼ */
void OLGraph_print(OLGraph G){}