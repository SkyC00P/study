/* 顺序栈暴露给外部调用的函数声明与具体结构声明 */
#include "../stack.h"
#include <stdlib.h>
#include <stdio.h>

#define T Stack_T
#define MAXSIZE 10
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
struct T
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack, * ptrSqStack;

Status InitStack(T * S)
{
	(*S) = malloc(sizeof(SqStack));
	if (!(*S)) {
		return ERROR;
	}
	(*S)->top = -1;
	printf("已分配在堆的指针:%p\n", *S);
	return OK;
}

Status ClearStack(T S)
{
	S->top = -1;
	return OK;
}

Bool StackEmpty(T S)
{
	return S->top == -1 ? TRUE : FALSE;
}

Status DestroyStack(T S)
{
	if (S)
	{
		free(S);
		printf("释放的指针:%p\n", S);
		return OK;
	}
	return ERROR;
}

int StackLength(T S)
{
	return S->top+1;
}

Status GetTop(T S, int * e)
{
	if (!StackEmpty(S))
	{
		*e = S->data[S->top];
		return OK;
	}
	return ERROR;
}

Status Push(T S, int e)
{
	if (S && StackLength(S) != MAXSIZE)
	{
		S->top++;
		S->data[S->top] = e;
		return OK;
	}
	return ERROR;
}

Status Pop(T S, int * e)
{
	if (S && !StackEmpty(S))
	{
		*e = S->data[S->top];
		S->top--;
		return OK;
	}
	return ERROR;
}

extern void StackTraverse(T S) {
	if (S)
	{
		for (int index = 0; index < MAXSIZE; index++)
		{
			printf("%d ", S->data[index]);
		}
		printf("\n");
	}
}
#undef T