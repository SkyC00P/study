#include "../queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct QueueNode {
	int data;
	struct QueueNode * next;
}QueueNode, *QueueNodePtr;

typedef struct Queue
{
	int len;
	QueueNodePtr rear;
}LinkQueue;

static int ptrCount = 0;

Status InitQueue(Queue * Q)
{
	if (*Q) return ERROR;
	*Q = malloc(sizeof(LinkQueue));
	if (!(*Q)) return ERROR;
	printf("已分配在堆的指针(%d):%p\n", ++ptrCount, *Q);
	(*Q)->rear = NULL;
	(*Q)->len = 0;
	return OK;
}

Status ClearQueue(Queue Q)
{
	if (!Q) return ERROR;
	if (QueueEmpty(Q)) return OK;

	QueueNodePtr tmp = NULL; // 尾节点
	QueueNodePtr freeNode = Q->rear;
	while (Q->len){
		tmp = freeNode->next;
		free(freeNode);
		printf("释放指针(%d):%p\n", --ptrCount, freeNode);
		freeNode = tmp;
		Q->len--;
	}
	Q->rear = NULL;
	return OK;
}

Bool QueueEmpty(Queue Q)
{
	if (!Q) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
	return Q->len==0 ? TRUE : FALSE;
}

int QueueLength(Queue Q)
{
	if (!Q) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}

	return Q->len;
}

Status GetHead(Queue Q, int * e)
{
	if (!Q) return ERROR;
	if (QueueEmpty(Q)) return ERROR;
	*e = Q->rear->next->data;
	return OK;
}

Status EnQueue(Queue Q, int e)
{
	if (!Q) return ERROR;
	QueueNodePtr node = malloc(sizeof(QueueNode));
	if (!node) return ERROR;
	printf("已分配在堆的指针(%d):%p\n", ++ptrCount, node);

	node->data = e;
	if (Q->rear == NULL) {
		Q->rear = node;
		Q->rear->next = Q->rear;
	}
	else
	{
		node->next = Q->rear->next; 
		Q->rear->next = node;
		Q->rear = node;
	}
	
	Q->len++;
	return OK;
}

Status DeQueue(Queue Q, int * e)
{
	if (!Q) return ERROR;
	if (QueueEmpty(Q)) return ERROR;

	QueueNodePtr headNode = Q->rear->next;
	*e = headNode->data;
	Q->rear->next = headNode->next;
	free(headNode);
	printf("释放指针(%d):%p\n", --ptrCount, headNode);
	Q->len--;
	return OK;
}

Status QueueTraverse(Queue Q)
{
	if (!Q) return ERROR;
	int len = QueueLength(Q);

	if (len == 0) {
		puts("Queue is Empty.");
		return OK;
	}

	QueueNodePtr head = Q->rear->next;
	printf("Head:%d, Rear:%d, The Data:", head->data, Q->rear->data);
	for (int i = 0; i < Q->len; i++) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
	return OK;
}

Status DestroyQueue(Queue Q)
{
	if (!Q) return ERROR;
	ClearQueue(Q);
	free(Q);
	printf("释放指针(%d):%p\n", --ptrCount, Q);
	return OK;
}