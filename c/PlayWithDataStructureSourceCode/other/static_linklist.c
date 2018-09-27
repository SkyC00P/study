#include "data_struct.h"

#ifndef MAXSIZE
#define MAXSIZE 1000
#endif
typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

/*
 * 数组的第一个元素的cur来存放备用链表第一个节点的下标
 * 数组的最后一个元素的cur来存放第一个插入元素的下标，相当于头结点, 为0表示未有一个元素插入
 */
Status InitList(StaticLinkList space) {
    int i = 0;
    for (i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;
    }

    space[MAXSIZE - 1].cur = 0;
    return OK;
}

/*
 * 获得链表可插入的索引
 */
int Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList L) {
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1 || ListLength(L) == MAXSIZE - 2) {
        return ERROR;
    }

    j = Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }

    return ERROR;
}

/*  将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k) {
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList L, int i, ElemType *e) {
    int j, k;
    if (i < 1 || i > ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
        k = L[k].cur;
    j = L[k].cur;
    *e = L[j].data;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}