#include "stack.h"
#include <stdlib.h>

#define T Stack_T
#define MAXSIZE 5
typedef void * SElemType;

/* ˳��ջ�ṹ */
struct T {
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
};

typedef struct T *Sqstack;

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

Status GetTop(T S, void * e){
	return OK;
}

Status Push(T * S, void * e){
	return OK;
}

Status Pop(T * S, void * e){
	return OK;
}
#undef T
