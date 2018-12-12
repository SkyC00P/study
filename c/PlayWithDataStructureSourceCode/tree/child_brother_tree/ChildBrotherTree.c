#include "ChildBrotherTree.h"
#include <ctype.h>

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
1. 每次读取三个值，最多产生2个结点，一定让一个结点数据完整，使得不完整的结点数减一，产生新的不完整结点可能值为0，1，2
2. 设总的不完整结点为n，第一次读取时，n为1(根结点)，则每次读取，n的结果可能为 n-1, n, n+1
3. 每一个叶子结点都会使n-1, 也就是说当树初始化OK时，n为0，即最后一个叶子结点也被读取完整。
在这里我需要一个查找结构。Key - Value的Map
*/
Status CBTree_create(FILE * fp, CBTree * T)
{
	CheckPtr(fp);
	CheckPtr(T);

	CBTree tree = *T;
	CBData ch;
	// 获得根结点
	fscanf(fp, "%c", &ch);
	if (!CBTree_isEmpty(tree) || isspace(ch)) {
		return ERROR;
	}

	tree = malloc(sizeof(CBNode));
	tree->nextBrother = NULL;
	tree->fristChild = NULL;
	tree->data = ch;

	CBTree root = tree;
	CBTree child, brother;
	while (!feof(fp)){
		// 跳过=号
		ch = fgetc(fp);
		if (ch != '=') {
			fprintf(stderr, "File Read Error, expect is '='\n");
			return ERROR;
		}
		// 读取孩子结点
		while (1){
			ch = fgetc(fp);
			if (ch == '\n' || ch == EOF) {
				break;
			}
			CBNodePtr node = malloc(CBNode);
			node->data = ch;
			if (!root->fristChild) {
				root->fristChild = node;
			}
		}
	}
	return OK;
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
