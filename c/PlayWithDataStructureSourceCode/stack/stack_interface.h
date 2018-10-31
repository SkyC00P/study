/*
ADT ջ(stack)
Data
  ͬ���Ա�Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ��
Operation
  InitStack(*S):��ʼ������������һ����ջS
  DestroyStack(*S):��ջ���ڣ���������
  ClearStack(*S):��ջ���
  StackEmpty(S):��ջΪ�գ�����true�����򷵻�false
  GetTop(S,*e):��ջS�����ҷǿգ���e����S��ջ��Ԫ��
  Push(*S, e):��ջS���ڣ�������Ԫ��e��ջS�в���Ϊջ��Ԫ��
  Pop(*S, e): ɾ��ջS��ջ��Ԫ�أ�����e������ֵ
  StackLength(S):����ջS��Ԫ�ظ���
endADT
*/
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include "common.h"

struct Stack_I
{
	/*  ����ָ��InitStack:����һ����ջS */
	Status(*InitStack)(void * S);

	/* ����ָ��ClearStack:��S��Ϊ��ջ */
	Status(*ClearStack)(void * S);

	/* ����ָ��StackEmpty:��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
	Status(*StackEmpty)(void * S);

	/* ����ָ��DestroyStack:��ջ���ڣ��������� */
	Status(*DestroyStack)(void * S);

	/* ����ָ��StackLength:����S��Ԫ�ظ�������ջ�ĳ��� */
	int(*StackLength)(void * S);

	/* ����ָ��GetTop:��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
	Status(*GetTop)(void * S, void * e);

	/* ����ָ��Push:����Ԫ��eΪ�µ�ջ��Ԫ�� */
	Status(*Push)(void *S, void * e);

	/* ����ָ��Pop:��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
	Status(*Pop)(void *S, void * e);
};

#endif // !STACK_INTERFACE_H