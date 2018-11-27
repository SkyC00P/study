#ifndef HAVE_PARENT_TREE_H
#define HAVE_PARENT_TREE_H
#include <stdio.h>
#include "common.h"
#define MAX_TREE_NODE 100

#ifndef TELEM_TYPE
	typedef char TElemType;
#endif // !TELEM_TYPE

typedef struct PNode {
	TElemType data;
	int parent;
}PNode;

typedef struct PTree {
	PNode nodes[MAX_TREE_NODE];
	int n;
}PTree;

/* 初始化树 */
Status ParentTree_init(PTree * T);

/* 清空树 */
void ParentTree_clear(PTree * T);

/* 销毁树 */
void ParentTree_destory(PTree * T);

/* 判断树是否为空 */
Bool ParentTree_isEmpty(PTree T);

/* 按文件的层序序列构造树 */
Status ParentTree_create(FILE *fp, PTree *T);

/* 返回树的度 */
int ParentTree_degree(PTree T);

/* 返回树的深度 */
int ParentTree_depth(PTree T);

/* 返回根结点值 */
TElemType ParentTree_root(PTree T);

/* 返回树中第i个结点的值（按层序计数） */
TElemType ParentTree_value(PTree T, int i);

/* 返回结点e的值位置(在数组中位置)，-1代表无此结点 */
int ParentTree_order(PTree T, int i);

/* 换结点e的值为value */
Status ParentTree_assign(PTree *T, TElemType e, TElemType value);

/* 返回结点e的第order个孩子的值（从左至右计数） */
TElemType ParentTree_childVaule(PTree T, TElemType e, int order);

/* 返回结点e的第order个兄弟的值（从左至右计数） */
TElemType ParentTree_siblingVaule(PTree T, TElemType e, int order);

/* 返回结点p的孩子结点（子树）个数，返回负数代表结点p不存在 */
int ParentTree_ChildCount(PTree T, TElemType p);

/* 返回树T中p结点的第i个孩子（层序计数）的位置，i=0定义为最后一个孩子。 */
int ParentTree_seat(PTree T, TElemType p, int i);

/* 将结点e插入为树T中p结点的第i个孩子（层序计数），i=0定义为最后一个孩子。 */
Status ParentTree_insertChild(PTree T, TElemType p, int i, TElemType e);

/* 将树t插入为树T中p结点的第i棵子树（层序计数），i=0定义为最后一棵子树。 */
Status ParentTree_insertTree(PTree *T, TElemType p, int i, PTree t);

/* 删除树T中p结点的第i棵子树。 */
Status ParentTree_delteTree(PTree *T, TElemType p, int i);

/* 层序遍历树。 */
void ParentTree_levelOrderTraverse_P(PTree T, void(Visit)(TElemType));

/* 打印树 */
void ParentTree_print(PTree T);
#endif // !HAVE_PARENT_TREE_H
