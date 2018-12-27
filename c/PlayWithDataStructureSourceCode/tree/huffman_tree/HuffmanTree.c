#include "HuffmanTree.h"
#include "help/OrderLinkList.h"

static int _compare(void * v1, void * v2);
static void _destroy(void * val);

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
	int num;
	if (!fscanf(fp, "%d,", &num)) {
		return NULL;
	}

	OrderLinkList list = OrderLinkList_init(_compare);
	int weight;
	while (fscanf(fp, "%d,", &weight)) {
		HTNodePtr ptr = malloc(sizeof(HTNode));
		if (!ptr) {
			exit(OVERFLOW);
		}
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->parent = NULL;
		ptr->weight = weight;

		OrderLinkList_add(list, ptr);
	}

	if (!feof(fp) || OrderLinkList_size(list) != num) {
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
	OrderLinkList_destroy(list, _destroy);
	return tree;
}

static int _compare(void * v1, void * v2) {

}

static void _destroy(void * val) {

}
