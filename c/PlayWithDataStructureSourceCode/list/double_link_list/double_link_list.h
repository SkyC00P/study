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

/* 初始化 */
Status InitList(DuLinkList *L);

/* 创建默认值为0，长度为n的链表 */
Status CreateList(DuLinkList *L, int n);

/* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Bool ListEmpty(DuLinkList L);

/* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(DuLinkList *L);

/* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(DuLinkList L);

/* 初始条件：线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(DuLinkList L, int i, ElemType *e);

/* 初始条件：线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(DuLinkList L, ElemType e);

/* 初始条件：线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(DuLinkList *L, int i, ElemType e);

/* 初始条件：线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(DuLinkList *L, int i, ElemType *e);

#endif // !DOUBLE_LINK_LIST_H
