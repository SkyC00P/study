#ifndef SQLIST_H
#define SQLIST_H 1

#include "common.h"
#define MAXSIZE 10

typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
} SqList;

/* ��ʼ������������һ���յ����Ա�L */
Status InitList(SqList *L);

/* �����Ա�Ϊ�գ�����true,���򷵻�false */
Bool ListEmpty(SqList L);

/* �����Ա���� */
Status ClearList(SqList *L);

/* �����Ա�L�еĵ�i��λ��Ԫ�ط��ظ�e */
Status GetElem(SqList L, int i, ElemType *e);

/* �����Ա�L�в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򷵻�0��ʾʧ�� */
int LocateElem(SqList L, ElemType e);

/* �����Ա�L�еĵ�i��Ԫ�ز�����Ԫ��e */
Status ListInsert(SqList *L, int i, ElemType e);

/* ɾ�����Ա�L�е�i��λ��Ԫ�أ�����e������ֵ */
Status ListDelete(SqList *L, int i, ElemType *e);

/* �������Ա�L��Ԫ�ظ��� */
int ListLength(SqList L);

#endif // !SQLIST_H
