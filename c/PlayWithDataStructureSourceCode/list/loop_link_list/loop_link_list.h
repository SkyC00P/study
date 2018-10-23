#ifndef LOOP_LINK_LIST_H
#define LOOP_LINK_LIST_H 1

#include "common.h"

typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node * next;
}Node;

typedef struct Node *LoopLinkList;

/* ��ʼ�������� */
Status InitList(LoopLinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Bool ListEmpty(LoopLinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LoopLinkList *L);

/* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LoopLinkList L);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LoopLinkList L, int i, ElemType *e);

/* ��ʼ���������Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(LoopLinkList L, ElemType e);

/* ��ʼ���������Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LoopLinkList *L, int i, ElemType e);

/* ��ʼ���������Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LoopLinkList *L, int i, ElemType *e);

#endif // !LOOP_LINK_LIST_H
