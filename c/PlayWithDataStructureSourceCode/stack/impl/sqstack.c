/* 顺序栈暴露给外部调用的函数声明与具体结构声明 */
#include "../sqstack.h"

typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
struct SqStack
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
};

Status SqStack_InitStack(SqStack * S)
{
	return OK;
}

Status SqStack_ClearStack(SqStack * S)
{
	return OK;
}

Status SqStack_StackEmpty(SqStack S)
{
	return OK;
}

Status SqStack_DestroyStack(SqStack * S)
{
	return OK;
}

int SqStack_StackLength(SqStack S)
{
	return 0;
}

Status SqStack_GetTop(SqStack S, void * e)
{
	return OK;
}

Status SqStack_Push(SqStack * S, void * e)
{
	return OK;
}

Status SqStack_Pop(SqStack * S, void * e)
{
	return OK;
}

struct Stack_I Get_SqStack() {
	struct Stack_I stack = {
		SqStack_InitStack,
		SqStack_ClearStack,
		SqStack_StackEmpty,
		SqStack_DestroyStack,
		SqStack_StackLength,
		SqStack_GetTop,
		SqStack_Push,
		SqStack_Pop
	};
	return stack;
}
