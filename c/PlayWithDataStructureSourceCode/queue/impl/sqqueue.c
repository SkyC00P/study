#include "../queue.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 10
struct Queue
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue, *SqQueuePtr;

static int ptrCount = 0;

Status InitQueue(Queue * Q)
{
	if (*Q) return ERROR;
	*Q = malloc(sizeof(SqQueue));
	printf("已分配在堆的指针(%d):%p\n", ++ptrCount, *Q);
	if (!(*Q)) return ERROR;
	(*Q)->front = (*Q)->rear = 0;
	return OK;
}

Status ClearQueue(Queue Q)
{
	if (!Q) return ERROR;
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Bool QueueEmpty(Queue Q)
{
	if (!Q) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
	return Q->front == Q->rear ? TRUE : FALSE;
}

int QueueLength(Queue Q)
{
	if (!Q) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}

	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status GetHead(Queue Q, int * e)
{
	if (!Q) return ERROR;
	if (QueueEmpty(Q)) return ERROR;
	*e = Q->data[Q->front];
	return OK;
}

Status EnQueue(Queue Q, int e)
{
	if (!Q) return ERROR;
	if (QueueLength(Q) == MAXSIZE-1) return ERROR;

	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(Queue Q, int * e)
{
	if (!Q) return ERROR;
	if (QueueEmpty(Q)) return ERROR;

	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

Status QueueTraverse(Queue Q)
{
	if (!Q) return ERROR;
	int len = QueueLength(Q);

	printf("Head:%d, Rear:%d, The Data:", Q->front, Q->rear);
	for (int i = 0; i < len; i++) {
		printf("%d ", Q->data[i]);
	}
	printf("\n");
	return OK;
}

Status DestroyQueue(Queue Q)
{
	if (!Q) return ERROR;
	free(Q);
	printf("释放指针(%d):%p\n", --ptrCount, Q);
	return OK;
}
