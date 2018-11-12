#include "../queue.h"
#define MAXSIZE 10
struct Queue
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue, * SqQueuePtr;

Status InitQueue(Queue * Q)
{
	return OK;
}

Status ClearQueue(Queue Q)
{
	return OK;
}

Bool QueueEmpty(Queue Q)
{
	return TRUE;
}

Status GetHead(Queue Q, int * e)
{
	return OK;
}

Status EnQueue(Queue Q, int e)
{
	return OK;
}

Status DeQueue(Queue Q, int * e)
{
	return OK;
}

Status QueueTraverse(Queue Q)
{
	return OK;
}

Status DestroyQueue(Queue Q)
{
	return OK;
}
