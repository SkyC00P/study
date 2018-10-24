#include "loop_link_list.h"
#include <stdio.h>
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
	Node * headNode = (*L)->next; // 头结点
	Node * freeNode = headNode->next; // 第一个有效数据节点
	int freeTimes = 0;
	while (freeNode != headNode) {
		Node * next = freeNode->next;
		free(freeNode);
		freeTimes++;
		freeNode = next;
	}
	(*L)->next = *L;
	printf("clear node num is %d\n", freeTimes++);
	return OK;
}

int ListLength(LoopLinkList L) {
	int len = 0;
	Node * node = L;
	while (L != node->next) {
		len++;
		node = node->next;
	}
	return len;
}

Status GetElem(LoopLinkList L, int i, ElemType * e) {
	int len = ListLength(L);
	if (len == 0 || i<1 || i>len) {
		return ERROR;
	}
	Node * node = L->next->next;
	for (int index = 1; index < i; index++) {
		node = node->next;
	}
	*e = node->data;
	return OK;
}

int LocateElem(LoopLinkList L, ElemType e) {
	int index = 0;
	Node * node = L->next->next;

	while (node != L->next) {
		index++;
		if (node->data == e) {
			return index;
		}
		node = node->next;
	}
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
	int len = ListLength(*L);
	if (i<1 || len == 0 || i>len) {
		return ERROR;
	}

	Node * del_before = (*L)->next;
	for (int index = 1; index < i; index++){
		del_before = del_before->next;
	}

	Node * del = del_before->next;
	*e = del->data;
	del_before->next = del->next;
	free(del);

	if (i==len){
		*L = del_before;
	}
	return OK;
}

