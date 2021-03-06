#include "ChildBrotherTree.h"
#include <ctype.h>
#include <string.h>
#include "help/HashMap.h"
#include "help/link_queue.h"

static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key);
static void CBNodePtr_free(void * value);
static void printNode(CBNodePtr ptr);

Status CBTree_init(CBTree * T)
{
	if (*T) { return ERROR; }
	*T = NULL;
	return OK;
}

void CBTree_clear(CBTree * T)
{
	if (*T) {
		LinkQueue queue = LinkQueue_init();
		LinkQueue_add(queue, *T);
		CBNodePtr freeNode;
		while (1) {
			freeNode = (CBNodePtr)LinkQueue_remove(queue);
			if (freeNode == NULL) {
				LinkQueue_destory(queue, CBNodePtr_free);
				break;
			}
			if (freeNode->fristChild) {
				LinkQueue_add(queue, freeNode->fristChild);
			}
			if (freeNode->nextBrother) {
				LinkQueue_add(queue, freeNode->nextBrother);
			}
			CBNodePtr_free(freeNode);
		}
	}
	*T = NULL;
}

void CBTree_destroy(CBTree * T)
{
	CBTree_clear(T);
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
	if (len == 0 || len % 3 != 0) {
		fprintf(stderr, "The content is Non-conformity\n");
		return ERROR;
	}

	HashMap cache = HashMap_init();
	*T = get_node_from_cache(cache, str[0]);
	HashMap_put(cache, (*T)->data, *T);

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
	Status status = HashMap_isEmpty(cache) ? OK : ERROR;
	HashMap_destory(cache, NULL);

	return status;
}

static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key) {
	CBNodePtr node = NULL;
	if (HashMap_contain(cache, key)) {
		node = HashMap_get(cache, key);
	}
	else {
		node = malloc(sizeof(CBNode));
		if (!node) {
			fprintf(stderr, "[get_node_from_cache] Error malloc.\n");
			return NULL;
		}
		node->data = key;
	}
	return node;
}

int CBTree_degree(CBTree T)
{
	if (!T || !T->fristChild) {
		return 0;
	}

	int max = 0;
	LinkQueue queue = LinkQueue_init();
	LinkQueue_add(queue, T->fristChild);
	CBNodePtr node, tmp;
	while (1) {
		node = LinkQueue_remove(queue);
		if (node == NULL) {
			LinkQueue_destory(queue, CBNodePtr_free);
			break;
		}
		int count = 0;
		tmp = node;
		while (tmp) {
			count++;
			if (tmp->fristChild) {
				LinkQueue_add(queue, tmp->fristChild);
			}
			tmp = tmp->nextBrother;
		}
		if (count > max) {
			max = count;
		}
	}
	return max;
}

/*
 求树的深度可不可以等价于求解与图的关键路径，把树当成特殊的图
 ？ 或者利用转变为二叉树利用二叉树的性质可以解决什么问题吗？

 已知存在孩子结点的树结点，其树的深度必然大于树结点所在的层数。
 目标: 寻找是否存在某i层，使得第i层所有的结点都为叶子结点，如若存在，则i为树的深度

 解题步骤:
  1. 获得第i层所有结点
  2. 判断是否所有结点都无孩子结点 Y->3, N->4
  3. 返回i
  4. i++, 记录所有结点的孩子结点，重复1
*/
int CBTree_depth(CBTree T)
{
	if (!T) {
		return 0;
	}

	int level = 1;
	LinkQueue curLevelNodes = LinkQueue_init();
	LinkQueue nextLevelNodes = LinkQueue_init();
	LinkQueue_add(curLevelNodes, T);
	CBNodePtr node;
	while (1) {
		node = LinkQueue_remove(curLevelNodes);
		while (node) {
			CBNodePtr ptr = node;
			while (ptr) {
				if (ptr->fristChild) {
					LinkQueue_add(nextLevelNodes, ptr->fristChild);
				}
				ptr = ptr->nextBrother;
			}
			node = LinkQueue_remove(curLevelNodes);
		}

		if (LinkQueue_isEmpty(nextLevelNodes)) {
			LinkQueue_destory(curLevelNodes, CBNodePtr_free);
			LinkQueue_destory(nextLevelNodes, CBNodePtr_free);
			return level;
		}
		else {
			level++;
			LinkQueue tmp = curLevelNodes;
			curLevelNodes = nextLevelNodes;
			nextLevelNodes = tmp;
		}
	}

}

CBData CBTree_root(CBTree T)
{
	CheckPtr(T);
	return T->data;
}

CBData CBTree_value(CBTree T, int i)
{
	CheckPtr(T);

	int index = 0;
	LinkQueue queue = LinkQueue_init();
	CBNodePtr ptr = T;
	while (ptr) {
		i++;
		if (i == index) {
			break;
		}

		if (ptr->fristChild) {
			LinkQueue_add(queue, ptr->fristChild);
		}

		if (ptr->nextBrother) {
			ptr = ptr->nextBrother;
		}
		else {
			ptr = LinkQueue_remove(queue);
		}
	}

	LinkQueue_destory(queue, CBNodePtr_free);
	return i == index ? ptr->data : -1;
}

CBNodePtr CBTree_order(CBTree T, CBData e)
{
	LinkQueue queue = LinkQueue_init();
	CBNodePtr ptr = T;
	while (ptr) {
		if (ptr->data == e) {
			break;
		}

		if (ptr->fristChild) {
			LinkQueue_add(queue, ptr->fristChild);
		}

		if (ptr->nextBrother) {
			ptr = ptr->nextBrother;
		}
		else {
			ptr = LinkQueue_remove(queue);
		}
	}
	LinkQueue_destory(queue, CBNodePtr_free);
	return ptr;
}

Status CBTree_assign(CBTree T, CBData old, CBData new)
{
	CBNodePtr ptr = CBTree_order(T, old);
	if (ptr) {
		ptr->data = new;
		return OK;
	}
	return ERROR;
}

CBData CBTree_child(CBTree T, CBData e, int order)
{
	CBNodePtr ptr = CBTree_order(T, e);

	int index = 1;
	CBNodePtr cNode = ptr ? ptr->fristChild : NULL;
	while (cNode)
	{
		if (index == order) {
			break;
		}
		cNode = cNode->nextBrother;
		index++;
	}
	return cNode ? cNode->data : -1;
}

CBData CBTree_brother(CBTree T, CBData e, int order)
{
	CheckPtr(T);
	if (T->data == e || !T->fristChild || order <= 0) {
		return -1;
	}
	// 找到父结点
	CBNodePtr parentNode;
	int find_it = 0;
	LinkQueue nodes = LinkQueue_init();
	LinkQueue_add(nodes, T);
	while (1) {
		parentNode = LinkQueue_remove(nodes);
		if (!parentNode) {
			break;
		}
		CBNodePtr fcNode = parentNode->fristChild;
		while (fcNode) {
			if (fcNode->data == e) {
				find_it = 1;
				break;
			}
			if (fcNode->fristChild) {
				LinkQueue_add(nodes, fcNode);
			}
			fcNode = fcNode->nextBrother;
		}

		if (find_it) {
			LinkQueue_destory(nodes, NULL);
			break;
		}
	}
	printf("parent node is %c\n ", parentNode ? parentNode->data : '-');

	CBNodePtr ptr = parentNode->fristChild;
	int index = 1;
	find_it = 0;
	while (1) {
		if (index == order) {
			find_it = 1;
			break;
		}
		index++;
		ptr = ptr->nextBrother;
	}
	if (find_it && ptr) {
		return ptr->data;
	}
	return -1;
}

int CBTree_child_count(CBTree T, CBData p)
{
	CBNodePtr ptr = CBTree_order(T, p);
	int index = -1;
	while (ptr) {
		index++;
		ptr = ptr->nextBrother;
	}
	return index;
}

Status CBTree_insert(CBTree T, CBData e, int i, CBTree t)
{
	CheckPtr(T);
	CheckPtr(t);

	CBNodePtr parentNode = CBTree_order(T, e);
	if (!parentNode || !parentNode->fristChild || i < 0) {
		return ERROR;
	}
	if (i == 0) {
		CBNodePtr cNode = parentNode->fristChild;
		while (cNode->nextBrother) {
			cNode = cNode->nextBrother;
		}
		cNode->nextBrother = t;
		return OK;
	}
	if (i == 1) {
		t->nextBrother = parentNode->fristChild;
		parentNode->fristChild = t;
		return OK;
	}
	else {
		CBData data = CBTree_child(T, e, i - 1);
		CBNodePtr cNode = CBTree_order(T, data);
		if (cNode) {
			t->nextBrother = cNode->nextBrother;
			cNode->nextBrother = t;
			return OK;
		}
		return ERROR;
	}

}

Status CBTree_delete(CBTree T, CBData e, int i)
{
	CheckPtr(T);
	CBNodePtr delTree = NULL;
	CBNodePtr parentNode = CBTree_order(T, e);
	if (!parentNode) {
		return ERROR;
	}
	if (i == 1) {
		delTree = parentNode->fristChild;
		parentNode->fristChild = parentNode->fristChild->nextBrother;
	}
	else
	{
		CBData data = CBTree_child(T, e, i - 1);
		CBNodePtr delBefNode = CBTree_order(T, data);
		delTree = delBefNode ? delBefNode->nextBrother : NULL;
		delBefNode->nextBrother = delTree ? delTree->nextBrother : NULL;
	}
	CBTree_clear(&delTree);
	return OK;
}

void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData))
{
	if (!T) {
		return;
	}

	LinkQueue queue = LinkQueue_init();
	CBNodePtr ptr = T;
	int queue_size = 0;

	Visit(ptr->data);
	if (ptr->fristChild) {
		queue_size = 1;
		LinkQueue_add(queue, ptr->fristChild);
	}

	while (queue_size) {

		ptr = LinkQueue_remove(queue);
		while (ptr) {
			Visit(ptr->data);
			if (ptr->fristChild) {
				queue_size++;
				LinkQueue_add(queue, ptr->fristChild);
			}
			ptr = ptr->nextBrother;
		}
		queue_size--;
	}
	LinkQueue_destory(queue, CBNodePtr_free);
}

/* 根 左 右 */
void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData))
{
	if (!T) {
		return;
	}
	Visit(T->data);
	CBTree_preorder_traverse(T->fristChild, Visit);
	CBTree_preorder_traverse(T->nextBrother, Visit);
}

/* 左 根 右 */
void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData))
{
	if (!T) {
		return;
	}
	CBTree_inorder_traverse(T->fristChild, Visit);
	Visit(T->data);
	CBTree_inorder_traverse(T->nextBrother, Visit);
}

/* 左 右 根 */
void CBTree_postorder_traverse(CBTree T, void(Visit)(CBData))
{
	if (!T) {
		return;
	}
	CBTree_postorder_traverse(T->fristChild, Visit);
	CBTree_postorder_traverse(T->nextBrother, Visit);
	Visit(T->data);
}

/*
  按正常的树结构依层次打印出来，例如如下4层的树打印出来如下:
  R:A-
  A:DB B:FC C:H-
  D:-E E:-- F:-G
  G:-- H:-I I:--
*/
void CBTree_print(CBTree T)
{
	printf("---> print tree <---\n");
	if (!T) {
		printf("Empty Tree");
		goto fuc_end;
	}
	CBNodePtr ptr = T;
	int  nextLevelChildCount, curLevelChildCount;
	LinkQueue queue = LinkQueue_init();

	// 打印根结点
	printNode(ptr);
	if (ptr->fristChild) {
		curLevelChildCount = 0;
		nextLevelChildCount = 1;
		LinkQueue_add(queue, ptr->fristChild);
	}
	else {
		curLevelChildCount = nextLevelChildCount = 0;
	}

	while (1) {
		if (nextLevelChildCount == 0) {
			break;
		}

		curLevelChildCount = nextLevelChildCount;
		nextLevelChildCount = 0;

		printf("\n");

		ptr = LinkQueue_remove(queue);
		if (!ptr) {
			fprintf(stderr, "CBNode is Null\n");
			break;
		}
		do {
			printNode(ptr);

			if (ptr->fristChild) {
				nextLevelChildCount++;
				LinkQueue_add(queue, ptr->fristChild);
			}

			if (ptr->nextBrother) {
				ptr = ptr->nextBrother;
			}
			else {
				curLevelChildCount--;
				if (curLevelChildCount != 0) {
					ptr = LinkQueue_remove(queue);
				}
			}

		} while (curLevelChildCount);

	}
	LinkQueue_destory(queue, NULL);
fuc_end:printf("\n--------------------\n");
}

static void printNode(CBNodePtr ptr) {
	CheckPtr(ptr);
	CBData c1 = ptr->fristChild ? ptr->fristChild->data : '-';
	CBData c2 = ptr->nextBrother ? ptr->nextBrother->data : '-';
	printf("%c:%c%c ", ptr->data, c1, c2);
}

static void CBNodePtr_free(void * value) {
	if (value) {
		free(value);
	}
}