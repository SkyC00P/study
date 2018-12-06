#include "double_link_list.h"
#include <stdlib.h>
#include <stdio.h>

Status InitList(DuLinkList * L) {
	*L = (DuLinkList)malloc(sizeof(DuLinkList));
	if (!(*L)) {
		return ERROR;
	}
	(*L)->next = *L;
	(*L)->prior = *L;
	return OK;
}

Status CreateList(DuLinkList * L, int n)
{
	InitList(L);
	Node * node;
	for (int i = 0; i < n; i++) {
		node = (Node *)malloc(sizeof(Node));
		if (!node) {
			ClearList(L);
			return ERROR;
		}
		node->data = 0;
		node->next = (*L)->next;
		node->prior = *L;

		(*L)->next = node;
		*L = node;
	}
	return OK;
}

Bool ListEmpty(DuLinkList L)
{
	return L->next == L;
}

Status ClearList(DuLinkList * L) {
	Node * headNode = (*L)->next; // 头结点
	Node * freeNode = headNode->next; // 第一个有效数据节点
	int freeTimes = 0;
	while (freeNode != headNode) {
		Node * next = freeNode->next;
		free(freeNode);
		freeTimes++;
		freeNode = next;
	}
	*L = headNode;
	(*L)->next = *L;
	(*L)->prior = *L;
	printf("clear node num is %d\n", freeTimes++);
	return OK;
}

int ListLength(DuLinkList L)
{
	int len = 0;
	Node * node = L;
	while (L != node->next) {
		len++;
		node = node->next;
	}
	return len;
}

Status GetElem(DuLinkList L, int i, ElemType * e)
{
	int len = ListLength(L);
	if (len == 0 || i<1 || i>len) {
		return ERROR;
	}

	if (i == len) {
		*e = L->data;
		return OK;
	}
	else if (i == 1) {
		*e = L->next->next->data;
		return OK;
	}

	Node * node = L->next->next;
	for (int index = 1; index < i; index++) {
		node = node->next;
	}
	*e = node->data;
	return OK;
}

int LocateElem(DuLinkList L, ElemType e)
{
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

Status ListInsert(DuLinkList * L, int i, ElemType e)
{
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

	Node * node_next_one = node_before_one->next;
	node->data = e;
	node->next = node_next_one;
	node->prior = node_before_one;
	node_before_one->next = node;
	node_next_one->prior = node;

	if (len + 1 == i)
		(*L) = node;
	return OK;
}

Status ListDelete(DuLinkList * L, int i, ElemType * e)
{
	int len = ListLength(*L);
	if (i<1 || len == 0 || i>len) {
		return ERROR;
	}

	Node * del_before = (*L)->next;
	for (int index = 1; index < i; index++) {
		del_before = del_before->next;
	}

	Node * del = del_before->next;
	*e = del->data;
	del_before->next = del->next;
	del->next->prior = del_before;
	free(del);

	if (i == len) {
		*L = del_before;
	}
	return OK;
}
