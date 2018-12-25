#include "stack.h"

LinkStack LinkStack_init()
{
	LinkStack stack = malloc(sizeof(struct LinkStack));
	if (!stack) {
		exit(OVERFLOW);
	}
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

Status LinkStack_push(LinkStack stack, SElemType data)
{
	CheckPtr(stack);
	StackNodePtr ptr = malloc(sizeof(StackNode));
	if (!ptr) return ERROR;
	ptr->data = data;
	ptr->next = stack->top;
	stack->top = ptr;
	stack->count++;
	return OK;
}

Bool LinkStack_empty(LinkStack stack)
{
	CheckPtr(stack);
	return stack->count == 0 ? TRUE : FALSE;
}

SElemType LinkStack_top(LinkStack stack)
{
	CheckPtr(stack);
	return stack->top->data;
}

SElemType LinkStack_pop(LinkStack stack)
{
	CheckPtr(stack);
	StackNodePtr ls = stack->top;
	if (!ls) {
		return NULL;
	}
	stack->top = ls->next;
	SElemType data = ls->data;
	free(ls);
	stack->count--;
	return data;
}

void LinkStack_destory(LinkStack stack)
{
	if (stack) {
		if (!LinkStack_empty(stack)) {
			StackNodePtr ptr = stack->top;
			StackNodePtr tmp = NULL;
			while (ptr) {
				tmp = ptr->next;
				free(ptr);
				ptr = tmp;
			}
		}
		free(stack);
	}
}
