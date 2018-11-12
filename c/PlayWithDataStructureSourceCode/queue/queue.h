/*
ADT ����(Queue)
Data
  ͬ���Ա�Ԫ�ؾ�����ͬ�����ͣ�����Ԫ�ؾ���ǰ���ͺ�̹�ϵ��
Operation
  InitQueue(*Q):��ʼ������������һ���ն���Q
  DestroyQueue(*Q):������Q���ڣ���������
  ClearQueue(*Q):������Q���
  QueueEmpty(*Q):������QΪ�գ��򷵻�TRUE,���򷵻�FALSE
  GetHead(Q, *e):������Q�����ҷǿ�, ��e���ض���Q�Ķ�ͷԪ��
  EnQueue(*Q, e):������Q���ڣ�������Ԫ��e������Q�в���Ϊ��βԪ�ء�
  DeQueue(*Q, *e):ɾ������Q�ж�ͷԪ�أ�����e������ֵ
  QueueLength(Q):���ض���Q��Ԫ�ظ���
endADT
*/
#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

typedef struct Queue * Queue;

Status InitQueue(Queue *Q);

Status ClearQueue(Queue Q);

Bool QueueEmpty(Queue Q);

Status GetHead(Queue Q, int *e);

Status EnQueue(Queue Q, int e);

Status DeQueue(Queue Q, int *e);

Status QueueTraverse(Queue Q);

Status DestroyQueue(Queue Q);
#endif // !QUEUE_H

