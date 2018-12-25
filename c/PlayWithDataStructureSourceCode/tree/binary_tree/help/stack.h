#ifndef HAVE_STACK_H
#define HAVE_STACK_H
#include "common.h"

typedef void * SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode * next;
}StackNode, *StackNodePtr;

typedef struct LinkStack {
	int count;
	StackNodePtr top;
}*LinkStack;

LinkStack LinkStack_init();

Status LinkStack_push(LinkStack stack, SElemType data);

Bool LinkStack_empty(LinkStack stack);

SElemType LinkStack_top(LinkStack stack);

SElemType LinkStack_pop(LinkStack stack);

void LinkStack_destory(LinkStack stack);

#endif // !HAVE_STACK_H
