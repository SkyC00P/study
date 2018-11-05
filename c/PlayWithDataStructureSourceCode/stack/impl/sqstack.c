/* 顺序栈暴露给外部调用的函数声明与具体结构声明 */
#include "../stack.h"
#include <stdlib.h>
#include <stdio.h>

#define T Stack_T
#define MAXSIZE 10
typedef void * SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
struct T
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack, * ptrSqStack;

Status InitStack(T * S)
{
	(*S) = (T)malloc(sizeof(*S));
	if (!(*S)) {
		return ERROR;
	}
	(*S)->top = -1;
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
	return ClearStack(S);
}

int StackLength(T S)
{
	return S->top+1;
}

Status GetTop(T S, void * e)
{
	if (!StackEmpty(S))
	{
		e = S->data[S->top];
		return OK;
	}
	return ERROR;
}

Status Push(T S, void * e)
{
	if (S && StackLength(S) != MAXSIZE)
	{
		S->top++;
		S->data[S->top] = e;
		return OK;
	}
	return ERROR;
}

Status T_Pop(T S, void * e)
{
	if (S && !StackEmpty(S))
	{
		e = S->data[S->top];
		S->top--;
		return OK;
	}
	return ERROR;
}

extern void StackTraverse(T S) {
	if (S)
	{
		int len = StackLength(S);
		for (int index = 0; index < len; index++)
		{
			printf("%d ", S->data[index]);
		}
		printf("\n");
	}
}
#undef T