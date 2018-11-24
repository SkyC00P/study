#ifndef HAVE_TREE_H
#define HAVE_TREE_H
#include "common.h"

typedef struct TreeNode * TreeNode;
typedef struct Tree * Tree;

/* 构造空树T */
Tree Tree_Init();

/* 销毁树T */
Status Tree_Destroy(Tree t);

/* 若树存在，则将树请为空树 */
Status Tree_Clear(Tree t);

/* 若T为空树，返回true,否则返回false */
Bool Tree_Empty(Tree t);

/* 返回T的深度 */
int Tree_Depth(Tree t);

/* 返回T的根结点 */
Status Tree_Root(Tree t, TreeNode root);

/* 返回该结点的值 */
int Tree_GetValue(TreeNode node);

Status Tree_S
Status Tree_Assign(TreeNode cur_e, int value);

Status Tree_Parent(TreeNode cur_e, TreeNode * parent);

Status Tree_LeftChild(TreeNode cur_e, TreeNode * leftChild);

Status Tree_RightBrother(TreeNode cur_e, TreeNode * rightBrother);

#endif // !HAVE_TREE_H
