#include "link_queue.h"

typedef struct QueueNode {
	LinkQueue_Data_T data;
	struct QueueNode * next;
}QueueNode, *QueueNodePtr;

typedef struct LinkQueue
{
	int len;
	QueueNodePtr rear;
	QueueNodePtr head;
}* LinkQueue;

#define T LinkQueue
#define D LinkQueue_Data_T

LinkQueue LinkQueue_init()
{
	LinkQueue queue = malloc(sizeof(struct LinkQueue));
	CheckPtr(queue);

	queue->len = 0;
	queue->head = queue->rear = NULL;

	return queue;
}

Status LinkQueue_add(T t, D d)
{
	CheckPtr(t);
	QueueNodePtr ptr = malloc(sizeof(QueueNode));
	if (!ptr) {
		return ERROR;
	}
	ptr->data = d;
	ptr->next = NULL;

	if (t->len == 0) {
		t->head = t->rear = ptr;
	}
	else
	{
		t->rear->next = ptr;
		t->rear = ptr;
	}
	t->len++;
	return OK;
}

void LinkQueue_destory(T t, LinkQueue_FucPtr_value_free method)
{
	CheckPtr(t);
	QueueNodePtr tmp,freeNode = t->head;
	while (1) {
		if (t->len == 0) {
			break;
		}
		tmp = freeNode->next;
		if (method) {
			method(freeNode->data);
		}
		free(freeNode);
		freeNode = tmp;
		t->len--;
	}
}

D LinkQueue_remove(T t)
{
	CheckPtr(t);
	if (t->len == 0) {
		return NULL;
	}
	D d = t->head->data;
	t->head = t->head->next;
	t->len--;
	return d;
}
Bool LinkQueue_isEmpty(T t)
{
	CheckPtr(t);
	return t->len == 0;
}
#undef T
#undef D