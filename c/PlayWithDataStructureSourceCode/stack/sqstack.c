#include "stack.h"

#define T SqStack
#define D SElemType

typedef int SElemType;

/* ˳��ջ�ṹ */
struct T{
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
};

Status InitStack(T * S)
{
	return OK;
}

Status ClearStack(T * S){
	return OK;
}

Status StackEmpty(T S){
	return OK;
}

Status DestroyStack(T * S)
{
	return OK;
}

int StackLength(T S){
	return 0;
}

Status GetTop(T S, D * e){
	return OK;
}

Status Push(T * S, D e){
	return OK;
}

Status Pop(T * S, D * e){
	return OK;
}
