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
/* ����ͼ */
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

/* ���ͼ */
void ALMGraph_clear(ALMGraph G){}

/* ����ͼ */
void ALMGraph_destroy(ALMGraph * G){}

/* Ѱ�Ҷ���v��λ�á� */
int ALMGraph_locate(ALMGraph G, ALM_VertexType v){}

/* ���ص�v������ֵ */
ALM_VertexType ALMGraph_get(ALMGraph G, int order){}

/* �Զ���v��ֵvalue�� */
void ALMGraph_set(ALMGraph G, ALM_VertexType old, ALM_VertexType new){}

/* ����v�ĵ�һ���ڽӶ������ */
int ALMGraph_frist_vertex(ALMGraph G, ALM_VertexType v){}

/* ����v�����w����һ���ڽӶ������ */
int ALMGraph_next_vertex(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* ���붥��v��ͼ */
Status ALMGraph_add_vertex(ALMGraph G, ALM_VertexType v){}

/* ��ͼ��ɾ������v�Լ���صĻ� */
Status ALMGraph_del_vertex(ALMGraph G, ALM_VertexType v){}

/* ���뻡<v,w>��ͼ */
Status ALMGraph_add_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w, AL_Weight weight){}

/* ɾ����<v,w>��ͼ */
Status ALMGraph_del_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* �жϱ��Ƿ���� */
Bool ALMGraph_arc_exist(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}
ALM_EdgeNodePtr ALMGraph_get_arc(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* ���رߵ�Ȩֵ */
ALM_Weight ALMGraph_arc_weight(ALMGraph G, ALM_VertexType v, ALM_VertexType w){}

/* �����Ƿ���� */
Bool * ALMGraph_vertex_exist(ALMGraph G, ALM_VertexType v){}

/* ������ȱ��� */
void ALMGraph_DFS(ALMGraph G){}

/* ������ȱ��� */
void ALMGraph_HFS(ALMGraph G){}

/* ��ӡͼ */
void ALMGraph_print(ALMGraph G){}