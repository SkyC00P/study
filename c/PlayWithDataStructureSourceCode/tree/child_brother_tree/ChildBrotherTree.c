#include "ChildBrotherTree.h"

Status CBTree_init(CBTree * T)
{
	if (*T) { return ERROR; }
	*T = malloc(sizeof(CBNode));
	if (!(*T)) {
		return ERROR;
	}
	(*T)->brotherList = NULL;
	(*T)->childList = NULL;
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
	return OK;
}

Status CBTree_create(FILE * fp, CBTree * T)
{
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
