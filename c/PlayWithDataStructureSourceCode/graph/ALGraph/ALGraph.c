#include "ALGraph.h"
#include "help/SingleLinkList.h"
#include "../file.c"
static void _create_fail(ALGraph * al) {
	if (*al) {
		ALGraph als = *al;
		for (int i = 0; i < als->numVertexes; i++) {
			if (als->adlist[i].firstEdge) {
				SingleLinkList_destroy(als->adlist[i].firstEdge);
			}
		}
		free(als);
		*al = NULL;
	}
}

static ALGraph _create_dg(FILE * fp) {
	CheckPtr(fp);
	ALGraph al = malloc(sizeof(struct ALGraph));
	if (!al) {
		Exit_with_msg("Out of memory");
	}
	
	al->kind = DG_0;
	al->numVertexes = _read_int(fp);
	al->numEdges = _read_int(fp);

	for (int i = 0; i < al->numVertexes; i++) {
		al->adlist[i].data = _read_ve(fp);
		al->adlist[i].firstEdge = NULL;
	}

	for (int i = 0; i < al->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, v1, v2);
		int index_1 = ALGraph_locate(al, v1);
		int index_2 = ALGraph_locate(al, v2);
		if (index_1 < 0 || index_2) {
			_create_fail(&al);
			return NULL;
		}

		SingleLinkList list = al->adlist[index_1].firstEdge;
		if (!list) {
			list = al->adlist[index_1].firstEdge = SingleLinkList_init();
		}
		
		SingleLinkList_add(list, index_2, 0);
	}
}

static ALGraph _create_dn(FILE * fp) {
	CheckPtr(fp);

}

ALGraph ALGraph_create(FILE * fp)
{
	CheckPtr(fp);

	ALGraphKind kind = _read_int(fp);
	switch (kind)
	{
	case DG_0:
		return _create_dg(fp);
	case DN_1:
		return _create_dn(fp);
	case UDG_2:
		return _create_udg(fp);
	case UDN_3:
		return _create_udn(fp);
	default:
		return NULL;
	}
}

void ALGraph_clear(ALGraph G)
{
}

void ALGraph_destroy(ALGraph * G)
{
}

int ALGraph_locate(ALGraph G, AL_VertexType v)
{
	return 0;
}

AL_VertexType ALGraph_get(ALGraph G, int order)
{
	return AL_VertexType();
}

void ALGraph_set(ALGraph G, AL_VertexType old, AL_VertexType new)
{
}

int ALGraph_frist_vertex(ALGraph G, AL_VertexType v)
{
	return 0;
}

int ALGraph_next_vertex(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	return 0;
}

Status ALGraph_add_vertex(ALGraph G, AL_VertexType v)
{
	return Status();
}

Status ALGraph_del_vertex(ALGraph G, AL_VertexType v)
{
	return Status();
}

Status ALGraph_add_arc(ALGraph G, AL_VertexType v, AL_VertexType w, AL_Weight weight)
{
	return Status();
}

Status ALGraph_del_arc(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	return Status();
}

Bool ALGraph_arc_exist(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	return Bool();
}

AL_Weight ALGraph_arc_weight(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	return AL_Weight();
}

void ALGraph_DFS(ALGraph G)
{
}

void ALGraph_HFS(ALGraph G)
{
}

void ALGraph_print(ALGraph G)
{
}