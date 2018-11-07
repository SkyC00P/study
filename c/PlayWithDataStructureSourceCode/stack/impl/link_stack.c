#include "../stack.h"
#include <stdlib.h>
#include <stdio.h>

#define T Stack_T
typedef int SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode * next;
}StackNode, *LinkStackPtr;

typedef struct T {
	int count;
	LinkStackPtr top;
} LinkStack;

static int ptrCount = 0;

Status InitStack(T * S)
{
	*S = malloc(sizeof(LinkStack));
	if (!(*S)) return ERROR;

	printf("已分配在堆的指针(%d):%p\n", ++ptrCount, *S);
	(*S)->count = 0;
	(*S)->top = NULL;
	return OK;
}

Status ClearStack(T S) {
	if (!S) { return ERROR; }
	LinkStackPtr ptr = S->top;
	LinkStackPtr tmp = NULL;
	while (ptr) {
		tmp = ptr->next;
		free(ptr);
		printf("释放指针(%d):%p\n", --ptrCount, ptr);
		ptr = tmp;
	}
	S->top = NULL;
	S->count = 0;
	return OK;
}

Bool StackEmpty(T S) {
	if (!S) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
	return S->count == 0 ? TRUE : FALSE;
}

Status DestroyStack(T S)
{
	if (!S) return ERROR;
	if (!StackEmpty(S)) {
		ClearStack(S);
	}
	free(S);
	printf("释放指针(%d):%p\n", --ptrCount, S);
	return OK;
}

int StackLength(T S) {
	if (!S) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
	return S->count;
}

Status GetTop(T S, int * e) {
	if (!S) return ERROR;
	if (StackEmpty(S)) return ERROR;
	*e = S->top->data;
	return OK;
}

Status Push(T S, int e) {
	if (!S) return ERROR;
	LinkStackPtr ptr = malloc(sizeof(StackNode));
	if (!ptr) return ERROR;
	printf("已分配在堆的指针(%d):%p\n", ++ptrCount, ptr);
	ptr->data = e;
	ptr->next = S->top;
	S->top = ptr;
	S->count++;
	return OK;
}

Status Pop(T S, int * e) {
	if (!S) return ERROR;
	if (StackEmpty(S)) return ERROR;

	*e = S->top->data;
	LinkStackPtr ptr = S->top->next;
	free(S->top);
	printf("释放指针(%d):%p\n", --ptrCount, S->top);
	S->top = ptr;
	S->count--;
	return OK;
}

void StackTraverse(T S) {
	if (!S) return;

	LinkStackPtr ptr = S->top;
	printf("LinkStack count : %d, data --> ", S->count);
	while (ptr){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
#undef T