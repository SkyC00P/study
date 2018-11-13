#ifndef SQLIST_H
#define SQLIST_H 1

#include "common.h"
#define MAXSIZE 10

typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
} SqList;

/* 初始化操作，建立一个空的线性表L */
Status InitList(SqList *L);

/* 若线性表为空，返回true,否则返回false */
Bool ListEmpty(SqList L);

/* 将线性表清空 */
Status ClearList(SqList *L);

/* 将线性表L中的第i个位置元素返回给e */
Status GetElem(SqList L, int i, ElemType *e);

/* 在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功，否则返回0表示失败 */
int LocateElem(SqList L, ElemType e);

/* 在线性表L中的第i个元素插入新元素e */
Status ListInsert(SqList *L, int i, ElemType e);

/* 删除线性表L中第i个位置元素，并用e返回其值 */
Status ListDelete(SqList *L, int i, ElemType *e);

/* 返回线性表L的元素个数 */
int ListLength(SqList L);

#endif // !SQLIST_H
