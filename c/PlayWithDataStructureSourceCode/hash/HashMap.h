#ifndef HAVE_HASH_MAP_H
#define HAVE_HASH_MAP_H
#include "common.h"

typedef char HashMap_Key_T;
typedef void * HashMap_Vaule_T;
typedef void (*HashMap_FucPtr_value_free)(void* value);

typedef enum _hashmap_use_state {
	hashmap_unused_0 = 0, hashmap_used_1 = 1
} hashmap_use_state;

typedef struct Entry
{
	HashMap_Key_T key;
	HashMap_Vaule_T value;
	hashmap_use_state used; /* unused_0, used_1 */

}Entry;

typedef struct HashMap
{
	Entry * elem;
	int length;
	int tablesize;
}*HashMap;

HashMap HashTable_init();

Bool HashMap_contain(HashMap map, HashMap_Key_T key);

HashMap_Vaule_T HashMap_get(HashMap map, HashMap_Key_T key);

HashMap_Vaule_T HashMap_remove(HashMap map, HashMap_Key_T key);

void HashMap_put(HashMap map, HashMap_Key_T key, HashMap_Vaule_T value);

Bool HashMap_isEmpty(HashMap map);

void HashMap_destory(HashMap map, HashMap_FucPtr_value_free method);

#endif // !HAVE_HASH_MAP_H
