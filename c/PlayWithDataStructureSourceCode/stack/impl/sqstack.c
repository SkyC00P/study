/* ˳��ջ��¶���ⲿ���õĺ������������ṹ���� */
#include "../sqstack.h"

typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

/* ˳��ջ�ṹ */
struct SqStack
{
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
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
