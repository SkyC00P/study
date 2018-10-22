#ifndef STATIC_LINK_LIST_H
#define STATIC_LINK_LIST_H 1

#include "common.h"

typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */
#define MAXSIZE 10 /* 存储空间初始分配量,设置为5是为了测试 */

/* 线性表的静态链表存储结构 */
typedef struct
{
	ElemType data;
	int cur;  /* 游标(Cursor) ，为0时表示无指向 */
} Component, StaticLinkList[MAXSIZE];

/* 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 */
Status InitList(StaticLinkList space);

/* 若备用空间链表非空，则返回分配的结点下标，否则返回0 */
int Malloc_SSL(StaticLinkList space);

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k);

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L);

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList L, int i, ElemType e);

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i);

/* 初始条件：线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(StaticLinkList L);

#endif // !STATIC_LINK_LIST_H
