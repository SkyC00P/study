#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H 1

#include "common.h"

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node * next;
	struct Node * prior;
}Node;

typedef struct Node * DuLinkList;

/* ��ʼ�������� */
Status InitList(DuLinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Bool ListEmpty(DuLinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(DuLinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(DuLinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(DuLinkList L, int i, ElemType *e);

/* ��ʼ���������Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(DuLinkList L, ElemType e);

/* ��ʼ���������Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(DuLinkList *L, int i, ElemType e);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(DuLinkList *L, int i, ElemType *e);

#endif // !DOUBLE_LINK_LIST_H
