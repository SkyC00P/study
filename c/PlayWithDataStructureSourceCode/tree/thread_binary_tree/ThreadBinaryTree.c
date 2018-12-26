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
	
	if (!*T){
		exit(OVERFLOW);
	}
	(*T)->data = '\0';
	(*T)->lchild = t;
	(*T)->ltag = Link;

	return OK;
}

Status TBTree_inOrder_traverse(TBTree T, void(Visit)(TBData))
{
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

	return OK;
}

void TBTree_postThreading(TBTree t)
{
}

Status TBTree_postorder_Threading(TBTree * T, TBTree t)
{
	return OK;
}

Status TBTree_postOrder_traverse(TBTree T, void(Visit)(TBData))
{
	return OK;
}

void TBTree_parent(TBTree T)
{
}

TBTree TBTree_post_next(TBTree t, TBTree p)
{
	return NULL;
}
