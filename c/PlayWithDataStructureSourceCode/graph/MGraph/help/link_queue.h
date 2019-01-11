#ifndef HAVE_LINK_QUEUE_H
#define HAVE_LINK_QUEUE_H
#include "common.h"

typedef int LinkQueue_Data_T;
typedef struct LinkQueue * LinkQueue;

#define T LinkQueue
#define D LinkQueue_Data_T

LinkQueue LinkQueue_init();

Status LinkQueue_add(T t, D d);

void LinkQueue_destory(T t);

D LinkQueue_remove(T t);

Bool LinkQueue_isEmpty(T t);

#undef T
#undef D

#endif // !HAVE_LINK_QUEUE_H