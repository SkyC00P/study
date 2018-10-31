#ifndef SQSTACK_H
#define SQSTACK_H

#include "stack_interface.h"

#define MAXSIZE 10 /* 存储空间初始分配量 */

typedef struct SqStack * SqStack;

/*  构造一个空栈S */
extern Status SqStack_InitStack(SqStack *S);

/* 把S置为空栈 */
extern Status SqStack_ClearStack(SqStack *S);

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
extern Status SqStack_StackEmpty(SqStack S);

/* 若栈存在，则销毁它 */
extern Status SqStack_DestroyStack(SqStack *S);

/* 返回S的元素个数，即栈的长度 */
extern int SqStack_StackLength(SqStack S);

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
extern Status SqStack_GetTop(SqStack S, void * e);

/* 插入元素e为新的栈顶元素 */
extern Status SqStack_Push(SqStack *S, void * e);

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
extern Status SqStack_Pop(SqStack *S, void * e);

extern struct Stack_I Get_SqStack();
#endif // !SQSTACK_H
