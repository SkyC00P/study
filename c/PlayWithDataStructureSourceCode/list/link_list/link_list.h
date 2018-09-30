#ifndef LINK_LIST_H
#define LINK_LIST_H 1

#include "common.h"

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

typedef struct Node *LinkList;

/* ��ʼ�������� */
Status InitList(LinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Bool ListEmpty(LinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LinkList L, int i, ElemType *e);

/* ��ʼ���������Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(LinkList L, ElemType e);

/* ��ʼ���������Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LinkList *L, int i, ElemType e);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L, int i, ElemType *e);

/* ��ʼ���������Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(LinkList L);

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨) */
void CreateListHead(LinkList *L, int n);

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨) */
void CreateListTail(LinkList *L, int n);

#endif // !LINK_LIST_H
