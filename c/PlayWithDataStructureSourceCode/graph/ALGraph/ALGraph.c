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
		_read_edge_g(fp, &v1, &v2);
		int index_1 = ALGraph_locate(al, v1);
		int index_2 = ALGraph_locate(al, v2);
		if (index_1 < 0 || index_2 < 0) {
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
	ALGraph al = malloc(sizeof(struct ALGraph));
	if (!al) {
		Exit_with_msg("Out of memory");
	}

	al->kind = DN_1;
	al->numVertexes = _read_int(fp);
	al->numEdges = _read_int(fp);

	for (int i = 0; i < al->numVertexes; i++) {
		al->adlist[i].data = _read_ve(fp);
		al->adlist[i].firstEdge = NULL;
	}

	for (int i = 0; i < al->numEdges; i++) {
		char v1, v2;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int index_1 = ALGraph_locate(al, v1);
		int index_2 = ALGraph_locate(al, v2);
		if (index_1 < 0 || index_2 < 0) {
			_create_fail(&al);
			return NULL;
		}

		SingleLinkList list = al->adlist[index_1].firstEdge;
		if (!list) {
			list = al->adlist[index_1].firstEdge = SingleLinkList_init();
		}

		SingleLinkList_add(list, index_2, weight);
	}
}

static ALGraph _create_udg(FILE * fp) {
	CheckPtr(fp);
	ALGraph al = malloc(sizeof(struct ALGraph));
	if (!al) {
		Exit_with_msg("Out of memory");
	}

	al->kind = UDG_2;
	al->numVertexes = _read_int(fp);
	al->numEdges = _read_int(fp);

	for (int i = 0; i < al->numVertexes; i++) {
		al->adlist[i].data = _read_ve(fp);
		al->adlist[i].firstEdge = NULL;
	}

	for (int i = 0; i < al->numEdges; i++) {
		char v1, v2;
		_read_edge_g(fp, &v1, &v2);
		int index_1 = ALGraph_locate(al, v1);
		int index_2 = ALGraph_locate(al, v2);
		if (index_1 < 0 || index_2 < 0) {
			_create_fail(&al);
			return NULL;
		}

		SingleLinkList list_1 = al->adlist[index_1].firstEdge;
		SingleLinkList list_2 = al->adlist[index_2].firstEdge;

		if (!list_1) {
			list_1 = al->adlist[index_1].firstEdge = SingleLinkList_init();
		}
		if (!list_2) {
			list_2 = al->adlist[index_2].firstEdge = SingleLinkList_init();
		}
		SingleLinkList_add(list_1, index_2, 0);
		SingleLinkList_add(list_2, index_1, 0);
	}
}

static ALGraph _create_udn(FILE * fp) {
	CheckPtr(fp);
	ALGraph al = malloc(sizeof(struct ALGraph));
	if (!al) {
		Exit_with_msg("Out of memory");
	}

	al->kind = UDN_3;
	al->numVertexes = _read_int(fp);
	al->numEdges = _read_int(fp);

	for (int i = 0; i < al->numVertexes; i++) {
		al->adlist[i].data = _read_ve(fp);
		al->adlist[i].firstEdge = NULL;
	}

	for (int i = 0; i < al->numEdges; i++) {
		char v1, v2;
		int weight;
		_read_edge_n(fp, &v1, &v2, &weight);
		int index_1 = ALGraph_locate(al, v1);
		int index_2 = ALGraph_locate(al, v2);
		if (index_1 < 0 || index_2 < 0) {
			_create_fail(&al);
			return NULL;
		}

		SingleLinkList list_1 = al->adlist[index_1].firstEdge;
		SingleLinkList list_2 = al->adlist[index_2].firstEdge;
		if (!list_1) {
			list_1 = al->adlist[index_1].firstEdge = SingleLinkList_init();
		}
		if (!list_2) {
			list_2 = al->adlist[index_2].firstEdge = SingleLinkList_init();
		}
		SingleLinkList_add(list_1, index_2, weight);
		SingleLinkList_add(list_2, index_1, weight);
	}
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
	if (G) {
		for (int i = 0; i < G->numVertexes; i++) {
			SingleLinkList_clear(G->adlist[i].firstEdge);
		}
		G->numEdges = 0;
		G->numVertexes = 0;
	}
}

void ALGraph_destroy(ALGraph * G)
{
	_create_fail(G);
}

int ALGraph_locate(ALGraph G, AL_VertexType v)
{
	CheckPtr(G);
	for (int i = 0; i < G->numVertexes; i++) {
		if (G->adlist[i].data == v) {
			return i;
		}
	}
	return -1;
}

AL_VertexType ALGraph_get(ALGraph G, int order)
{
	CheckPtr(G);
	return order >= 0 ? G->adlist[order].data : '\0';
}

void ALGraph_set(ALGraph G, AL_VertexType old, AL_VertexType new)
{
	CheckPtr(G);
	int index = ALGraph_locate(G, old);
	if (index >= 0) {
		G->adlist[index].data = new;
	}
}

int ALGraph_frist_vertex(ALGraph G, AL_VertexType v)
{
	CheckPtr(G);
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