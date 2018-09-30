#ifndef LINK_LIST_H
#define LINK_LIST_H 1

#include "common.h"

typedef int ElemType;
typedef struct Node{
	ElemType data;
	struct Node * next;
}Node;

typedef struct Node *LinkList;

/* 初始化单链表 */
Status InitList(LinkList *L);

/* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Bool ListEmpty(LinkList L);

/* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L);

/* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L);

/* 初始条件：线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L, int i, ElemType *e);

/* 初始条件：线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L, ElemType e);

/* 初始条件：线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L, int i, ElemType e);

/* 初始条件：线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i, ElemType *e);

/* 初始条件：线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法) */
void CreateListHead(LinkList *L, int n);

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法) */
void CreateListTail(LinkList *L, int n);

#endif // !LINK_LIST_H
