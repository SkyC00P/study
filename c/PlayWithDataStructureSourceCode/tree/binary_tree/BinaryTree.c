#include "BinaryTree.h"

void BiTree_clear()
{
}

void BiTree_destroy()
{
}

Bool BiTree_isEmpty()
{
	return TRUE;
}

Status BiTree_create(FILE * fp, BiTree * T)
{
	return OK;
}

int BiTree_length(BiTree T)
{
	return 0;
}

int BiTree_depth(BiTree T)
{
	return 0;
}

BiTNode BiTree_parent(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode BiTree_left_child(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode BiTree_right_child(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode BiTree_left_brother(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode BiTree_right_brother(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode BiTree_locate(BiTree T, BiTData data)
{
	return NULL;
}

Status BiTree_insert(BiTree T, BiTData data, BiTree t, bitree_direction direction)
{
	return OK;
}

Status BiTree_delete(BiTree T, BiTData data, bitree_direction direction)
{
	return OK;
}

void BiTree_level_order_traverse(BiTree T, void(Visit))
{
}

void BiTree_in_order_traverse(BiTree T, void(Visit))
{
}

void BiTree_pre_order_traverse(BiTree T, void(Visit))
{
}

void BiTree_post_order_traverse(BiTree T, void(Visit))
{
}

void BiTree_print(BiTree T)
{
}
