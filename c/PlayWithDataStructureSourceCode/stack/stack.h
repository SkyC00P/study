/*
ADT ջ(stack)
Data
  ͬ���Ա�Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ��
Operation
  InitStack(*S):��ʼ������������һ����ջS
  DestroyStack(*S):��ջ���ڣ���������
  ClearStack(*S):��ջ���
  StackEmpty(*S):��ջΪ�գ�����true�����򷵻�false
  GetTop(*S,*e):��ջS�����ҷǿգ���e����S��ջ��Ԫ��
  Push(*S, e):��ջS���ڣ�������Ԫ��e��ջS�в���Ϊջ��Ԫ��
  Pop(*S, e): ɾ��ջS��ջ��Ԫ�أ�����e������ֵ
  StackLength(S):����ջS��Ԫ�ظ���
endADT
*/
#ifndef STACK_H
#define STACK_H
#include "common.h"

#define T Stack_T

typedef struct T *T;

/*  ����һ����ջS */
extern Status InitStack(T *S);

/* ��S��Ϊ��ջ */
extern Status ClearStack(T S);

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
extern Status StackEmpty(T S);

/* ��ջ���ڣ��������� */
extern Status DestroyStack(T S);

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
extern int StackLength(T S);

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
extern Status GetTop(T S, void * e);

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
extern Status Push(T S, void * e);

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
extern Status Pop(T S, void * e);

extern void StackTraverse(T S);
#undef T
#endif // !STACK_H
