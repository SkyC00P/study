#include "HuffmanTree.h"
#include "help/OrderLinkList.h"
#include <math.h>

static int _compare(void * v1, void * v2);
static void _destroy(void * val);
static int _depth(HuffmanTree T);
void list_show(OrderLinkList list);

/*
 1. 根据给定的n个权值{w1,w2,w3,...,wn}构成n棵二叉树的集合F={T1,T2,T3,...,Tn},其中每棵二叉树Ti中只有一个带权为wi的根结点，其左右子树为空
 2. 在F中选取两棵根结点的权值最小的树作为左右子树构造一棵新的二叉树，且置新的二叉树的根结点的权值为其左右子树上根结点的权值之和。
 3. 在F中删除这两棵树，同时将新得到的二叉树加入到F中。
 4. 重复2，3步骤，直到F只含一棵树为止

 ？ F为什么数据结构比较合适呢，数组不合适，要频繁删除增加元素，那就用链表，而且还是有序的链表，无论增删都维持顺序
*/
HuffmanTree HuffmanTree_create(FILE * fp)
{
	CheckPtr(fp);
	HuffmanTree tree = NULL;
	int num, count = fscanf(fp, "%d,", &num);
	if (count == 0 || feof(fp)) {
		return NULL;
	}

	OrderLinkList list = OrderLinkList_init(_compare);
	int weight;
	count = fscanf(fp, "%d,", &weight);
	while (count != 0 && !feof(fp)) {
		HTNodePtr ptr = malloc(sizeof(HTNode));
		if (!ptr) {
			exit(OVERFLOW);
		}
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->parent = NULL;
		ptr->weight = weight;
		printf("add:%p, weight:%d\n", ptr, ptr->weight);
		OrderLinkList_add(list, ptr);
		count = fscanf(fp, "%d,", &weight);
	}
	list_show(list);
	if (OrderLinkList_size(list) != num) {
		fprintf(stderr, "[HuffmanTree_create] Error\n");
		OrderLinkList_destroy(list, _destroy);
		return NULL;
	}
	
	while (OrderLinkList_size(list) != 1) {
		HTNodePtr ptr = malloc(sizeof(HTNode));
		if (!ptr) {
			exit(OVERFLOW);
		}

		HTNodePtr p1 = OrderLinkList_remove_frist(list);
		HTNodePtr p2 = OrderLinkList_remove_frist(list);

		printf("p1:%d,p2:%d", p1 ? p1->weight : -1, p2 ? p2->weight : -1);
		int wp1, wp2;

		if (p1) {
			ptr->lchild = p1;
			wp1 = p1->weight;
			p1->parent = ptr;
		}
		else {
			ptr->lchild = NULL;
			wp1 = 0;
		}

		if (p2) {
			ptr->rchild = p2;
			wp2 = p2->weight;
			p2->parent = ptr;
		}
		else {
			ptr->rchild = NULL;
			wp2 = 0;
		}

		ptr->parent = NULL;
		ptr->weight = wp1 + wp2;
		OrderLinkList_add(list, ptr);
	}

	tree = OrderLinkList_remove_frist(list);
	OrderLinkList_destroy(list, NULL);
	return tree;
}

void HuffmanTree_show(HuffmanTree T)
{
	CheckPtr(T);
	HTNode a[100][100] = {};

	int row = _depth(T);
	int col = pow(2, row) - 1;
	int i, j, m, l, r;
	for (i = 1; i <= row - 1; i++)
	{
		for (j = 1; j <= pow(2, i - 1); j++)
		{
			m = (2 * j - 1)*pow(2, row - i);		//当前行结点相对位序 
			l = (4 * j - 3)*pow(2, row - i - 1);	//下一行结点相对位序 
			r = (4 * j - 1)*pow(2, row - i - 1);

			if (i == 1)						//初始化 
				a[i][m] = *T;

			if (a[i][m].lchild)				//下一行 
				a[i + 1][l] = *(a[i][m].lchild);

			if (a[i][m].rchild)				//下一行 
				a[i + 1][r] = *(a[i][m].rchild);
		}
	}

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (a[i][j].weight)
				printf("%c", a[i][j].weight);
			else
				printf(" ");
		}
		printf("\n");
	}
}

/* 0：相等 >0 大于 <0 小于 */
static int _compare(void * v1, void * v2) {
	CheckPtr(v1);
	CheckPtr(v2);

	HTNodePtr p1 = v1;
	HTNodePtr p2 = v2;

	return p1->weight - p2->weight;
}

static void _destroy(void * val) {
	if (val) {
		free(val);
	}
}

static int _depth(HuffmanTree T) {
	int LD, RD;
	if (T == NULL) {
		return 0;
	}

	LD = _depth(T->lchild);
	RD = _depth(T->rchild);
	return (LD >= RD ? LD : RD) + 1;
}

extern void list_show(OrderLinkList list) {
	CheckPtr(list);
	OrderLinkListNodePtr ptr = list->head;
	while (ptr) {
		HTNodePtr val = ptr->data;
		if (val) {
			printf("HTNodePtr:%p,weight:%d\n", val, val->weight);
		}
		else {
			printf("HTNodePtr:%p,weight:%d\n", val, -1);
		}
		ptr = ptr->next;
	}
}