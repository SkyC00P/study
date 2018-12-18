#ifndef HAVE_LINK_QUEUE_H
#define HAVE_LINK_QUEUE_H
#include "common.h"

typedef void * LinkQueue_Data_T;
typedef struct LinkQueue * LinkQueue;
typedef void(*LinkQueue_FucPtr_value_free)(void* value);

#define T LinkQueue
#define D LinkQueue_Data_T

LinkQueue LinkQueue_init();

Status LinkQueue_add(T t, D d);

void LinkQueue_destory(T t, LinkQueue_FucPtr_value_free method);

D LinkQueue_remove(T t);

Bool LinkQueue_isEmpty(T t);

#undef T
#undef D

#endif // !HAVE_LINK_QUEUE_H