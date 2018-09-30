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
	*L = (LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(*L)) /* �洢����ʧ�� */
		return ERROR;
	(*L)->next = NULL; /* ָ����Ϊ�� */

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
	p = (*L)->next;           /*  pָ���һ����� */
	while (p)                /*  û����β */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; /* pָ���һ����� */
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
	LinkList p;		/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j < i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if (!p || j > i)
		return ERROR;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return OK;
}

int LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) /* �ҵ�����������Ԫ�� */
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
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
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
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

#endif // DEBUG