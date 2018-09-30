#include "link_list.h"

#ifndef DEBUG
#include "stdlib.h"
Status InitList(LinkList * L) {
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L)) {
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}

Bool ListEmpty(LinkList L) {
	return L->next == NULL ? TRUE : FALSE;
}

int ListLength(LinkList L) {
	int length = 0;
	LinkList p = L->next;
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}

Status GetElem(LinkList L, int i, ElemType *e) {
	int len = ListLength(L);
	if (len == 0 || i<1 || i>len){
		return ERROR;
	}
	Node * node = L->next;
	for (int index = 1; index < i; index++){
		node = node->next;
	}
	*e = node->data;
	return OK;
}

Status ListInsert(LinkList * L, int i, ElemType e) {
	int len = ListLength(*L);
	if (i<1 || i>len + 1) {
		return ERROR;
	}

	Node * node = (Node *)malloc(sizeof(Node));
	if (!node) {
		return ERROR;
	}
	Node * node_before_one = *L;

	for (int index = 1; index < i; index++) {
		node_before_one = node_before_one->next;
	}

	node->data = e;
	node->next = node_before_one->next;
	node_before_one->next = node;
	return OK;
}

Status ListDelete(LinkList * L, int i, ElemType * e) {
	int len = ListLength(*L);
	if (i<1 || len == 0 || i>len) {
		return ERROR;
	}
	Node * del_before = *L;
	for (int index = 1; index <= i - 1; index++) {
		del_before = del_before->next;
	}
	Node * del = del_before->next;
	*e = del->data;
	del_before->next = del->next;
	free(del);

	return OK;
}
#endif // !DEBUG

#ifdef DEBUG
#include "stdio.h"    
#include "stdlib.h"   
#include "time.h"

Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(*L)) /* 存储分配失败 */
		return ERROR;
	(*L)->next = NULL; /* 指针域为空 */

	return OK;
}

Status ListEmpty(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;           /*  p指向第一个结点 */
	while (p)                /*  没到表尾 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        /* 头结点指针域为空 */
	return OK;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j < i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if (!p || j > i)
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

int LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) /* 找到这样的数据元素 */
			return i;
		p = p->next;
	}

	return 0;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;
		(*L)->next = p;						/*  插入到表头 */
	}
}

void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

#endif // DEBUG