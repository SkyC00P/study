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
	int index = ALGraph_locate(G, v);
	if (index < 0 || !(G->adlist[index].firstEdge)) {
		return -1;
	}
	else {
		return G->adlist[index].firstEdge->adjvex;
	}
}

int ALGraph_next_vertex(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	CheckPtr(G);
	int index_1 = ALGraph_locate(G, v);
	int index_2 = ALGraph_locate(G, v);
	if (index_1 < 0 || index_1 < 0) {
		return -1;
	}

	SingleLinkList list = G->adlist[index_1].firstEdge;
	if (list) {
		EdgeNodePtr ptr = SingleLinkList_get(list, index_2);
		if (ptr && ptr->next) {
			return ptr->next->adjvex;
		}
	}
	return -1;
}

Status ALGraph_add_vertex(ALGraph G, AL_VertexType v)
{
	CheckPtr(G);
	G->numVertexes++;
	G->adlist[G->numVertexes - 1].data = v;
	G->adlist[G->numVertexes - 1].firstEdge = NULL;
	return OK;
}

Status ALGraph_del_vertex(ALGraph G, AL_VertexType v)
{
	CheckPtr(G);
	int index = ALGraph_locate(G, v);
	if (index >= 0) {
		int size = SingleLinkList_size(G->adlist[index].firstEdge);
		G->numEdges -= size;
		SingleLinkList_destroy(G->adlist[index].firstEdge);
		for (int i = index; i < G->numVertexes; i++) {
			G->adlist[i].data = G->adlist[i + 1].data;
			G->adlist[i].firstEdge = G->adlist[i + 1].firstEdge;
		}

		Bool direction = G->kind == DG_0 || G->kind == DN_1 ? TRUE : FALSE;
		for (int i = 0; i < G->numVertexes; i++) {
			SingleLinkList list = G->adlist[i].firstEdge;
			if (list && SingleLinkList_remove(list, index) && direction) {
				G->numEdges--;
			}
		}
		G->numVertexes--;
	}
	return OK;
}

Status ALGraph_add_arc(ALGraph G, AL_VertexType v, AL_VertexType w, AL_Weight weight)
{
	CheckPtr(G);
	if (ALGraph_arc_exist(G, v, w)) {
		return ERROR;
	}
	int index_1 = ALGraph_locate(G, v);
	int index_2 = ALGraph_locate(G, w);
	if (index_1 < 0 || index_2 < 0) {
		return ERROR;
	}
	
	Bool direction = G->kind == DG_0 || G->kind == DN_1 ? TRUE : FALSE;
	SingleLinkList list_1 = G->adlist[index_1].firstEdge;
	SingleLinkList list_2 = G->adlist[index_2].firstEdge;

	if (!list_1) {
		list_1 = G->adlist[index_1].firstEdge = SingleLinkList_init();
	}
	SingleLinkList_add(list_1, index_2, weight);
	G->numEdges++;
	if (!direction) {
		if (!list_2) {
			list_2 = G->adlist[index_2].firstEdge = SingleLinkList_init();
		}
		SingleLinkList_add(list_2, index_1, weight);
	}

	return OK;
}

Status ALGraph_del_arc(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	CheckPtr(G);

	if (ALGraph_arc_exist(G, v, w))
	{
		Bool direction = G->kind == DG_0 || G->kind == DN_1 ? TRUE : FALSE;
		int index_1 = ALGraph_locate(G, v);
		int index_2 = ALGraph_locate(G, w);

		SingleLinkList list_1 = G->adlist[index_1].firstEdge;
		if (list_1 && SingleLinkList_remove(list_1, index_2)) {
			G->numEdges--;
		}
		SingleLinkList list_2 = G->adlist[index_2].firstEdge;
		if (!direction && list_2) {
			SingleLinkList_remove(list_2, index_1);
		}
		return OK;
	}
	return ERROR;
}

Bool ALGraph_arc_exist(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	CheckPtr(G);
	int index_1 = ALGraph_locate(G, v);
	int index_2 = ALGraph_locate(G, w);
	if (index_1 < 0 || index_2 < 0) {
		return FALSE;
	}
	SingleLinkList list = G->adlist[index_1].firstEdge;
	return list && SingleLinkList_get(list, index_2);
}

AL_Weight ALGraph_arc_weight(ALGraph G, AL_VertexType v, AL_VertexType w)
{
	CheckPtr(G);
	if (ALGraph_arc_exist(G, v, w)) {
		int index_1 = ALGraph_locate(G, v);
		int index_2 = ALGraph_locate(G, w);
		SingleLinkList list = G->adlist[index_1].firstEdge;
		return SingleLinkList_get(list, index_2);
	}
	Exit_with_msg("no exist arc.");
}

void ALGraph_DFS(ALGraph G)
{
}

void ALGraph_HFS(ALGraph G)
{
}

void ALGraph_print(ALGraph G)
{
	if (G) {
		char * kindMsg;
		switch (G->kind)
		{
		case DG_0:kindMsg = "DG-0-有向图"; break;
		case DN_1:kindMsg = "DN-1-有向网（带权值）"; break;
		case UDG_2:kindMsg = "UDG-2-无向图"; break;
		case UDN_3:kindMsg = "UDN-3-无向网（带权值）"; break;
		default:
			kindMsg = "unkonwn kind";
			break;
		}
		printf("顶点数:%d, 边集数:%d, 类型:%s\n", G->numVertexes, G->numEdges, kindMsg);
		for (int i = 0; i < G->numVertexes; i++) {
			printf("%3c ", G->adlist[i].data);
			if (G->adlist[i].firstEdge) {
				SingleLinkList_print(G->adlist[i].firstEdge);
			}
			printf("\n");
		}
	}
	else {
		printf("空图");
	}
}