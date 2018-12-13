#include "HashMap.h"
#include <stdlib.h>

static int _hashmap_hash(HashMap in, HashMap_Key_T key);

HashMap HashTable_init()
{
	HashMap map = malloc(sizeof(struct HashMap));
	if (!map) {
		return NULL;
	}
	map->length = 0;
	map->tablesize = 101;
	map->elem = (Entry *)calloc(map->tablesize, sizeof(Entry));

	if (!map->elem) {
		free(map);
		map = NULL;
	}
	for (int i = 0; i < map->tablesize; i++) {
		map->elem[i].used = hashmap_unused_0;
		map->elem[i].value = NULL;
	}

	return map;
}

Bool HashMap_contain(HashMap map, HashMap_Key_T key)
{
	CheckPtr(map);
	int index = _hashmap_hash(map, key);
	return map->elem[index].used && map->elem[index].key == key ? TRUE : FALSE;
}

HashMap_Vaule_T HashMap_get(HashMap map, HashMap_Key_T key)
{
	CheckPtr(map);
	int index = _hashmap_hash(map, key);
	if (HashMap_contain(map, key)) {
		return map->elem[index].value;
	}
	return NULL;
}

HashMap_Vaule_T HashMap_remove(HashMap map, HashMap_Key_T key)
{
	CheckPtr(map);
	int index = _hashmap_hash(map, key);
	Entry * entry = &(map->elem[index]);
	if (entry->used && entry->key != key) {
		fprintf(stderr, "[HashMap_remove] : Entry's Key[%c] mismatching real key[%c]\n", entry->key, key);
		return NULL;
	}

	HashMap_Vaule_T val = entry->value;
	map->elem[index].used = hashmap_unused_0;
	map->elem[index].value = NULL;
	map->length--;
	return val;
}

Status HashMap_put(HashMap map, HashMap_Key_T key, HashMap_Vaule_T value)
{
	CheckPtr(map);
	int index = _hashmap_hash(map, key);
	if (map->elem[index].used && map->elem[index].key != key) {
		fprintf(stderr, "Duplicate value conflict\n");
		return ERROR;
	}
	if (!map->elem[index].used) {
		map->elem[index].used = hashmap_used_1;
		map->length++;
	}
	
	map->elem[index].key = key;
	map->elem[index].value = value;
	
	return OK;
}

Bool HashMap_isEmpty(HashMap map)
{
	CheckPtr(map);
	return map->length == 0 ? TRUE : FALSE;
}

void HashMap_destory(HashMap map, HashMap_FucPtr_value_free method)
{
	if (map) {
		for (int i = 0; i < map->tablesize; i++) {
			if (map->elem[i].value) {
				method(map->elem[i].value);
			}
		}
		free(map->elem);
		free(map);
	}
}

int HashMap_size(HashMap map)
{
	CheckPtr(map);
	return map->length;
}

static int _hashmap_hash(HashMap in, HashMap_Key_T key) {
	CheckPtr(in);
	return (int)key % in->tablesize;
}