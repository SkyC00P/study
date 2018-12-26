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

void TBTree_postThreading(TBTree p)
{
	if (p)
	{
		if (!p->rchild)						//为当前结点右子树建立后继线索 
		{
			p->rtag = Thread;
			p->rchild = pre;
		}

		pre = p;							//pre在正常顺序中为后一个结点 

		if (p->rtag != Thread)
			TBTree_postThreading(p->rchild);		//线索化右子树 

		TBTree_postThreading(p->lchild);			//线索化左子树 
	}
}

Status TBTree_postorder_Threading(TBTree * Thrt, TBTree T)
{
	*Thrt = malloc(sizeof(TBNode));
	if (!*Thrt)
		exit(OVERFLOW);

	(*Thrt)->data = '\0';
	(*Thrt)->ltag = Link;
	(*Thrt)->rtag = Thread;
	(*Thrt)->rchild = *Thrt;

	if (!T)
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = *Thrt;							//指向头结点 

		TBTree_postThreading(T);						//开始线索化

		(*Thrt)->rchild = T;					//头结点回指 
	}

	return OK;
}

Status TBTree_postOrder_traverse(TBTree Thrt, void(Visit)(TBData))
{
	TBTree p = Thrt->lchild;					//p指向二叉树根结点

	if (p != Thrt)									//树不为空 
	{
		while (1)								//寻找遍历起点 
		{
			while (p->lchild)
				p = p->lchild;

			if (p->rchild && p->rtag != Thread)
				p = p->rchild;
			else
				break;
		}

		while (p)
		{
			Visit(p->data);
			p = TBTree_post_next(Thrt, p);
		}
	}

	return OK;
}

void TBTree_parent(TBTree T)
{
}

TBTree TBTree_post_next(TBTree Thrt, TBTree p)
{
	
}
