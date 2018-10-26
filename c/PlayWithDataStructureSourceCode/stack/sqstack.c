#include "stack.h"

#define T SqStack
#define D SElemType

typedef int SElemType;

/* 顺序栈结构 */
struct T{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
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
