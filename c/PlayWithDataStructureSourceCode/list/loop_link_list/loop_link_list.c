#include "loop_link_list.h"
#include <stdlib.h>

Status InitList(LoopLinkList *L) {
	*L = (LoopLinkList)malloc(sizeof(LoopLinkList));
	if (!(*L)) {
		return ERROR;
	}
	(*L)->next = *L;
	return OK;
}

Bool ListEmpty(LoopLinkList L) {
	return L->next == L;
}

Status ClearList(LoopLinkList * L) {
	return OK;
}

int ListLength(LoopLinkList L) {
	return 0;
}

Status GetElem(LoopLinkList L, int i, ElemType * e) {
	return OK;
}

int LocateElem(LoopLinkList L, ElemType e) {
	return 0;
}

Status ListInsert(LoopLinkList * L, int i, ElemType e) {
	int len = ListLength(*L);
	if (i<1 || i>len + 1) {
		return ERROR;
	}

	Node * node = (Node *)malloc(sizeof(Node));
	if (!node) {
		return ERROR;
	}

	Node * node_before_one = (*L)->next;
	for (int index = 1; index < i; index++) {
		node_before_one = node_before_one->next;
	}

	node->data = e;
	node->next = node_before_one->next;
	node_before_one->next = node;

	if (len + 1 == i)
		(*L) = node;
	return OK;
}

Status ListDelete(LoopLinkList * L, int i, ElemType * e) {
	return OK;
}

