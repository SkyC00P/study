#include "ChildTree.h"

Status ChildTree_init(ChildTree * T, FILE *fp) {
	return OK;
}

Status ChildTree_clear(ChildTree * T)
{
	return OK;
}

Bool ChildTree_isEmpty(ChildTree T)
{
	return TRUE;
}

int ChildTree_degree(ChildTree T)
{
	return 0;
}

int ChildTree_depth(ChildTree T)
{
	return 0;
}

ChildNodeType ChildTree_root(ChildTree T)
{
	return '\0';
}

ChildNodeType ChildTree_vaule(ChildTree T, int order)
{
	return '\0';
}

int ChildTree_order(ChildTree T, ChildNodeType data)
{
	return 0;
}

Status ChildTree_assign(ChildTree T, ChildNodeType old, ChildNodeType new)
{
	return OK;
}

ChildNodeType ChildTree_findChild(ChildTree T, ChildNodeType e, int order)
{
	return '\0';
}

ChildNodeType ChildTree_findBrother(ChildTree T, ChildNodeType e, int order)
{
	return '\0';
}

int ChildTree_getChildCount(ChildNode T, ChildNodeType e)
{
	return 0;
}

Status ChildTree_insertTree(ChildTree * T, ChildNodeType e, ChildTree t)
{
	return OK;
}

Status ChildTree_deleteTree(ChildTree * T, ChildNodeType e, int order)
{
	return OK;
}

void ChildTree_levelOrderTraverse(ChildTree T, void(Visit))
{
}

void ChildTree_print(ChildTree T)
{
}
