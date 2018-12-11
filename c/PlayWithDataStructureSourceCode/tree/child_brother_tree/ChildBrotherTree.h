#ifndef HAVE_CHILD_BROTHER_TREE_H
#define HAVE_CHILD_BROTHER_TREE_H
#include "common.h"
#include "double_link_list.h"

typedef int CBData;
typedef struct ChildBrotherNode{
	CBData data;
	DuLinkList childList, brotherList;
}CBNode, * CBNodePtr;

typedef CBNode * CBTree;

/* 构造空树T (初始化树) */
Status CBTree_init(CBTree * T);

/* 清空树 */
void CBTree_clear(CBTree * T);

/* 销毁树 */
void CBTree_destroy(CBTree * T);

/* 是否是空树 */
Bool CBTree_isEmpty(CBTree T);

/* 按文件创建树 */
Status CBTree_create(FILE *fp, CBTree *T);

/* 返回树的度 */
int CBTree_degree(CBTree T);

/* 返回树的深度 */
int CBTree_depth(CBTree T);

/* 返回树的根结点值 */
CBData CBTree_root(CBTree T);

/* 返回树中第i个结点值（按层序计数） */
int CBTree_value(CBTree T, int i);

/* 返回指向结点e的指针，NULL代表无此结点。 */
CBNodePtr CBTree_order(CBTree T, CBData e);

/* 替换结点e的值为value */
Status CBTree_assign(CBTree T, CBData old, CBData new);

/* 返回结点e的第order个孩子的值（从左至右计数） */
CBData CBTree_child(CBTree T, CBData e, int order);

/* 返回结点e的第order个兄弟的值（从左至右计数） */
CBData CBTree_brother(CBTree T, CBData e, int order);

/* 返回结点p的孩子结点（子树）个数，返回负数代表结点p不存在。 */
int CBTree_child_count(CBTree T, CBData p);

/* 将树t插入为树T中e结点的第i棵子树（层序计数），i=0定义为最后一棵子树。 */
Status CBTree_insert(CBTree T, CBData e, int i, CBTree t);

/* 删除树T中e结点的第i棵子树。 */
Status CBTree_delete(CBTree T, CBData e, int i);

/* 层序遍历树。 */
void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData));

/* 前序遍历树 */
void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData));

/* 中序遍历树 */
void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData));

/* 打印树 */
void CBTree_print(CBTree T);
#endif // !HAVE_CHILD_BROTHER_TREE_H
