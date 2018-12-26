/*
 线索二叉树 - 需要经常遍历或需查找结点的前驱和后继
*/
#ifndef HAVE_THREAD_BINARY_TREE_H
#define HAVE_THREAD_BINARY_TREE_H

#include "common.h"

typedef char TBData;
typedef enum {Link, Thread} PointerTag;
typedef struct TBNode {
	TBData data;
	PointerTag ltag, rtag;
	struct TBNode * lchild;
	struct TBNode * rchild;
}TBNode, *TBTree;

TBTree pre;

/*按先序序列构造二叉树，并建立孩子标志(无线索化)*/
Status TBTree_create(FILE * fp, TBTree * t);

/*中序全线索化。*/
void TBTree_inThreading(TBTree t);

/*中序遍历二叉树t，并将其全线索化*/
Status TBTree_inorder_Threading(TBTree * T, TBTree t);

/*中序遍历中序全线索二叉树（非递归算法）*/
Status TBTree_inOrder_traverse(TBTree T, void(Visit)(TBData));

/*先序后继线索化。*/
void TBTree_preThreading(TBTree t);

/*先序遍历二叉树T，并将其后继线索化。*/
Status TBTree_preorder_Threading(TBTree * T, TBTree t);

/*先序遍历前序后继线索二叉树（非递归算法）。*/
Status TBTree_preOrder_traverse(TBTree T, void(Visit)(TBData));

#endif // !HAVE_THREAD_BINARY_TREE_H