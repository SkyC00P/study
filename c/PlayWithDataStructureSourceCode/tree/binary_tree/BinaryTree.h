/*
 ¶þ²æÁ´±í
*/
#ifndef HAVE_BINARY_TREE_H
#define HAVE_BINARY_TREE_H
#include "common.h"

typedef char BiTData;
typedef struct BiTNode {
	BiTData data;
	struct BiTNode * lchild;
	struct BiTNode * rchild;
}BiTNode, *BiTree;

void BiTree_clear(BiTree * T);

Bool BiTree_isEmpty(BiTree T);

Status BiTree_create(FILE *fp, BiTree *T);

int BiTree_depth(BiTree T);

BiTNode * BiTree_parent(BiTree T, BiTData data);
BiTNode * BiTree_left_child(BiTree T, BiTData data);
BiTNode * BiTree_right_child(BiTree T, BiTData data);
BiTNode * BiTree_left_brother(BiTree T, BiTData data);
BiTNode * BiTree_right_brother(BiTree T, BiTData data);
BiTNode * BiTree_locate(BiTree T, BiTData data);

typedef enum _bitree_direction {
	bitree_direction_left_0 = 0, bitree_direction_right_1 = 1
} bitree_direction;

Status BiTree_insert(BiTree T, BiTData data, BiTree t, bitree_direction direction);

Status BiTree_delete(BiTree T, BiTData data, bitree_direction direction);

void BiTree_level_order_traverse(BiTree T, void(Visit)(BiTData));

void BiTree_in_order_traverse(BiTree T, void(Visit)(BiTData));

void BiTree_pre_order_traverse(BiTree T, void(Visit)(BiTData));

void BiTree_post_order_traverse(BiTree T, void(Visit)(BiTData));

void BiTree_print(BiTree T);

#endif // !HAVE_BINARY_TREE_H
