#ifndef HAVE_HASH_TABLE_H
#define HAVE_HASH_TABLE_H

typedef char HashTable_Key_T;
typedef void * HashTable_Vaule_T;

typedef struct Entry
{
	HashTable_Key_T key;
	HashTable_Vaule_T value;
}Entry;

typedef struct HashTable
{
	Entry * elem;
	int length;
}HashTable;
#endif // !HAVE_HASH_TABLE_H
