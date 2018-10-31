#ifndef SQSTACK_H
#define SQSTACK_H

#include "stack_interface.h"

#define MAXSIZE 10 /* �洢�ռ��ʼ������ */

typedef struct SqStack * SqStack;

/*  ����һ����ջS */
extern Status SqStack_InitStack(SqStack *S);

/* ��S��Ϊ��ջ */
extern Status SqStack_ClearStack(SqStack *S);

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
extern Status SqStack_StackEmpty(SqStack S);

/* ��ջ���ڣ��������� */
extern Status SqStack_DestroyStack(SqStack *S);

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
extern int SqStack_StackLength(SqStack S);

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
extern Status SqStack_GetTop(SqStack S, void * e);

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
extern Status SqStack_Push(SqStack *S, void * e);

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
extern Status SqStack_Pop(SqStack *S, void * e);

extern struct Stack_I Get_SqStack();
#endif // !SQSTACK_H
