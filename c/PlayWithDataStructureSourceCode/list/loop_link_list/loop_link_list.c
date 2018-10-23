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
	return OK;
}

Status ListDelete(LoopLinkList * L, int i, ElemType * e) {
	return OK;
}

