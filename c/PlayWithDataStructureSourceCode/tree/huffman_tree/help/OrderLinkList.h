#ifndef HAVE_ORDER_LINK_LIST_H
#define HAVE_ORDER_LINK_LIST_H
#include "common.h"

typedef struct _order_link_list_node_st {
	void * data;
	struct _order_link_list_node_st * next;
}OrderLinkListNode, * OrderLinkListNodePtr;

typedef int(*OrderLinkList_FucPtr_compare)(void* v1, void * v2);

typedef void(*OrderLinkList_FucPtr_free_val)(void* val);

typedef struct _order_link_list_st {
	OrderLinkListNode * head;
	OrderLinkList_FucPtr_compare compare;
	int len;
}*OrderLinkList;

OrderLinkList OrderLinkList_init(OrderLinkList_FucPtr_compare compare);

Status OrderLinkList_add(OrderLinkList list, void * val);

int OrderLinkList_size(OrderLinkList list);

void OrderLinkList_destroy(OrderLinkList list, OrderLinkList_FucPtr_free_val fuc);

void * OrderLinkList_remove_frist(OrderLinkList list);

#endif // !HAVE_ORDER_LINK_LIST_H
