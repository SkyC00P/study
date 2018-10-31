/*
ADT 栈(stack)
Data
  同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
  InitStack(*S):初始化操作，建立一个空栈S
  DestroyStack(*S):若栈存在，则销毁它
  ClearStack(*S):将栈清空
  StackEmpty(S):若栈为空，返回true，否则返回false
  GetTop(S,*e):若栈S存在且非空，用e返回S的栈顶元素
  Push(*S, e):若栈S存在，插入新元素e到栈S中并成为栈顶元素
  Pop(*S, e): 删除栈S中栈顶元素，并用e返回其值
  StackLength(S):返回栈S的元素个数
endADT
*/
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include "common.h"

struct Stack_I
{
	/*  函数指针InitStack:构造一个空栈S */
	Status(*InitStack)(void * S);

	/* 函数指针ClearStack:把S置为空栈 */
	Status(*ClearStack)(void * S);

	/* 函数指针StackEmpty:若栈S为空栈，则返回TRUE，否则返回FALSE */
	Status(*StackEmpty)(void * S);

	/* 函数指针DestroyStack:若栈存在，则销毁它 */
	Status(*DestroyStack)(void * S);

	/* 函数指针StackLength:返回S的元素个数，即栈的长度 */
	int(*StackLength)(void * S);

	/* 函数指针GetTop:若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
	Status(*GetTop)(void * S, void * e);

	/* 函数指针Push:插入元素e为新的栈顶元素 */
	Status(*Push)(void *S, void * e);

	/* 函数指针Pop:若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
	Status(*Pop)(void *S, void * e);
};

#endif // !STACK_INTERFACE_H