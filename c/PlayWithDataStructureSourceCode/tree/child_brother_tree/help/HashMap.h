#ifndef HAVE_HASH_MAP_H
#define HAVE_HASH_MAP_H
#include "common.h"

typedef char HashMap_Key_T;
typedef void * HashMap_Vaule_T;

typedef struct Entry
{
	HashMap_Key_T key;
	HashMap_Vaule_T value;
}Entry;

typedef struct HashMap
{
	Entry * elem;
	int length;
}*HashMap;

HashMap HashTable_init();

Bool HashMap_contain(HashMap map, HashMap_Key_T key);

HashMap_Vaule_T HashMap_get(HashMap map, HashMap_Key_T key);

HashMap_Vaule_T HashMap_remove(HashMap map, HashMap_Key_T key);

void HashMap_put(HashMap map, HashMap_Key_T key, HashMap_Vaule_T value);

Bool HashMap_isEmpty(HashMap map);

void HashMap_destory(HashMap map);

#endif // !HAVE_HASH_MAP_H
