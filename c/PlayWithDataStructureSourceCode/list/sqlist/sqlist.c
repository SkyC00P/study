#include "sqlist.h"

Status InitList(SqList *L) {
	L->length = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		L->data[i] = 0;
	}
	return OK;
}

Bool ListEmpty(SqList L) {
	if (L.length == 0){
		return TRUE;
	}
	return FALSE;
}

Status ClearList(SqList * L) {
	if (L->length == 0) {
		return OK;
	}
	for (int i = 0; i < L->length; i++){
		L->data[i] = 0;
	}
	L->length = 0;
	return OK;
}

int LocateElem(SqList L, ElemType e) {
	if (L.length == 0) {
		return 0;
	}

	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}

	return 0;
}

int ListLength(SqList L) {
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

/*
  以数组保存维护的顺序存储线性表，该方法的实现仅在有效Length范围内进行随意插入
  当Length为0时，仅能从第一个位置插入
  当Length递增时，可插入的范围为 0<x<=length+1
  每一次在i位置插入，都会使得length-i+1个元素向后移动一位
  最好的情况:插入到末尾，即Length=i,插入的时间复杂度为O(1)
  最坏的情况:插入到头部，即i=1,则插入的时间复杂度为O(n)
  ? 平均情况是怎么推算的，还未理清
  平均情况: 由于元素要插入到第i个位置,需要移动n-i个元素。根据概率原理，每个位置插入或删除元素的可能性是相同的，最终的平均移动次数和最中间的元素的移动次数相同，为(n-1)/2
*/
Status ListInsert(SqList *L, int i, ElemType e) {
	int k;
	if (L->length == MAXSIZE) {
		return ERROR;
	}

	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}

	if (i <= L->length) {
		for (k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];
		}
	}

	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
	int k;
	if (L->length == 0) {
		return ERROR;
	}

	if (i < 1 || i > L->length) {
		return ERROR;
	}

	*e = L->data[i - 1];
	if (i < L->length) {
		for (k = i; k < L->length; k++) {
			L->data[k - 1] = L->data[k];
		}
	}

	L->length--;
	return OK;
}