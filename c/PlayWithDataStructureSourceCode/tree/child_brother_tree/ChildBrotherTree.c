#include "ChildBrotherTree.h"
#include <ctype.h>
#include <string.h>
#include "help/HashMap.h"
static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key);
static void CBNodePtr_free(CBNodePtr value);

Status CBTree_init(CBTree * T)
{
	if (*T) { return ERROR; }
	*T = NULL;
	return OK;
}

void CBTree_clear(CBTree * T)
{
}

void CBTree_destroy(CBTree * T)
{
}

Bool CBTree_isEmpty(CBTree T)
{
	return T == NULL ? TRUE : FALSE;
}
/*
 ?如何根据文件的定义来生成树也是主要的API
 ?例如如何把html解析成dom树，如何将代码解析成表达式树

解法:每个树结点都保存数据，大儿子，大兄弟三个值，如果按层序将结点依次排列。如下
	R	A	^
	A	D	B
	B	^	C
	C	F	^
	D	^	E
	E	^	^
	F	G	^
	G	^	H
	H	^	K
	K	^	^
	测试数据里的是 RA#ADBB#CCF#D#EE##FG#G#HH#KK##
1. 每次读取三个值，最多产生2个结点，一定让一个结点数据完整，使得不完整的结点数减一，产生新的不完整结点可能值为0，1，2
2. 设总的不完整结点为n，第一次读取时，n为1(根结点)，则每次读取，n的结果可能为 n-1, n, n+1
3. 每一个叶子结点都会使n-1, 也就是说当树初始化OK时，n为0，即最后一个叶子结点也被读取完整。
在这里我需要一个查找结构。Key - Value的Map

解题步骤:
	1. 读取文件并将里面的内容作为字符串处理,一行字符串等于一棵树
	2. 每次处理从字符串中取3个值，判断这3个值是否已经在缓存里，如果不在生成一个新的结点，如果在，则从缓存里获取结点，通过第二和第三位的结点使得第一个结点的数据完整，未完整的结点保存到缓存里
	3. 重复第二步直到字符串结束
*/
Status CBTree_create(FILE * fp, CBTree * T)
{
	CheckPtr(fp);
	CheckPtr(T);

	char str[255];
	fgets(str, sizeof(str), fp); // 不考虑Buffer溢出的情况，不会弄一个超大树文件
	if (!feof(fp)) {
		fprintf(stderr, "more than one line\n");
		return ERROR;
	}

	int len = strlen(str);
	if (len % 3 != 0) {
		fprintf(stderr, "The content is Non-conformity\n");
		return ERROR;
	}
	HashMap cache = HashTable_init();
	for (int i = 0; i < len; i += 3) {
		char c1 = str[i];
		char c2 = str[i + 1];
		char c3 = str[i + 2];

		CBNodePtr cp1, cp2, cp3;
		cp1 = get_node_from_cache(cache, c1);
		cp2 = cp3 = NULL;

		if (c2 != '#') {
			cp2 = get_node_from_cache(cache, c2);
		}
		if (c3 != '#') {
			cp3 = get_node_from_cache(cache, c3);
		}

		cp1->fristChild = cp2;
		cp1->nextBrother = cp3;

		if (HashMap_contain(cache, cp1->data)) {
			HashMap_remove(cache, cp1->data);
		}

		if (cp2) {
			HashMap_put(cache, c2, cp2);
		}

		if (cp3) {
			HashMap_put(cache, c3, cp3);
		}
	}

	Status status = HashMap_isEmpty(cache) ? ERROR : OK;
	HashMap_destory(cache, CBNodePtr_free);
	return status;
}

static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key) {
	CBNodePtr node = NULL;
	if (HashMap_contain(cache, key)) {
		node = malloc(sizeof(CBNode));
		if (!node) {
			fprintf(stderr, "[get_node_from_cache] Error malloc.\n");
			return NULL;
		}
		node->data = key;
	}
	else {
		node = HashMap_get(cache, key);
	}
	return node;
}

int CBTree_degree(CBTree T)
{
	return 0;
}

int CBTree_depth(CBTree T)
{
	return 0;
}

CBData CBTree_root(CBTree T)
{
	return 0;
}

int CBTree_value(CBTree T, int i)
{
	return 0;
}

CBNodePtr CBTree_order(CBTree T, CBData e)
{
	return NULL;
}

Status CBTree_assign(CBTree T, CBData old, CBData new)
{
	return OK;
}

CBData CBTree_child(CBTree T, CBData e, int order)
{
	return 0;
}

CBData CBTree_brother(CBTree T, CBData e, int order)
{
	return 0;
}

int CBTree_child_count(CBTree T, CBData p)
{
	return 0;
}

Status CBTree_insert(CBTree T, CBData e, int i, CBTree t)
{
	return OK;
}

Status CBTree_delete(CBTree T, CBData e, int i)
{
	return OK;
}

void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_print(CBTree T)
{
}

static void CBNodePtr_free(CBNodePtr value) {

}