#include "ThreadBinaryTree.h"

Status TBTree_create(FILE * fp, TBTree * T)
{
	CheckPtr(fp);
	char ch;
	fscanf(fp, "%c", &ch);
	if (ch == '^') {
		*T = NULL;
		return OK;
	}
	*T = malloc(sizeof(TBNode));
	if (!(*T)) {
		exit(OVERFLOW);
	}
	(*T)->data = ch;

	TBTree_create(fp, &(*T)->lchild);
	(*T)->ltag = (*T)->lchild ? Link : Thread;

	TBTree_create(fp, &(*T)->rchild);
	(*T)->rtag = (*T)->rchild ? Link : Thread;

	return OK;
}

void TBTree_inThreading(TBTree t)
{
	if (t) {
		TBTree_inThreading(t->lchild);
		if (!t->lchild) {
			t->ltag = Thread;
			t->lchild = pre;
		}
		if (!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = t;
		}
		pre = t;
		TBTree_inThreading(t->rchild);
	}
}

Status TBTree_inorder_Threading(TBTree * T, TBTree t)
{
	*T = malloc(sizeof(TBNode));

	if (!*T) {
		exit(OVERFLOW);
	}
	(*T)->data = '\0';
	(*T)->ltag = Link;
	(*T)->rtag = Thread;
	(*T)->rchild = *T;

	if (!t) {
		(*T)->lchild = (*T);
	}
	else {
		(*T)->lchild = t;
		pre = (*T);

		TBTree_inThreading(t);

		pre->rchild = *T;
		pre->rtag = Thread;
		(*T)->rchild = pre;
	}

	return OK;
}

Status TBTree_inOrder_traverse(TBTree T, void(Visit)(TBData))
{
	TBTree node = T->lchild;
	while (node != T)
	{
		while (node->ltag == Link) {
			node = node->lchild;
		}
		Visit(node->data);
		while (node->rtag == Thread && node->rchild != T) {
			node = node->rchild;
			Visit(node->data);
		}
		node = node->rchild;
	}
	return OK;
}

void TBTree_preThreading(TBTree t)
{
	if (t) {
		if (!pre->rchild) {
			pre->rtag = Thread;
			pre->rchild = t;
		}
		pre = t;
		TBTree_preThreading(t->lchild);

		if (t->rchild && t->rtag == Link) {
			TBTree_preThreading(t->rchild);
		}
	}
}

Status TBTree_preorder_Threading(TBTree * T, TBTree t)
{
	*T = malloc(sizeof(TBNode));
	if (!*T) {
		exit(OVERFLOW);
	}

	(*T)->data = '\0';
	(*T)->ltag = Link;
	(*T)->rtag = Thread;
	(*T)->rchild = NULL;

	if (!t) {
		(*T)->lchild = (*T)->rchild = (*T);
	}
	else {
		(*T)->lchild = t;
		pre = (*T);

		TBTree_preThreading(t);

		pre->rchild = *T;
		pre->rtag = Thread;
	}
	return OK;
}

Status TBTree_preOrder_traverse(TBTree T, void(Visit)(TBData))
{
	TBNode * p = T;
	while (p->rchild != T) {
		while (p->lchild) {
			p = p->lchild;
			Visit(p->data);
		}
		if (p->rchild != T) {
			p = p->rchild;
			Visit(p->data);
		}
	}
	return OK;
}
