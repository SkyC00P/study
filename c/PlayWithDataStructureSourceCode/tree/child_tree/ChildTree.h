/*
 孩子表示法的关键点用一维数组保存所有的结点，跟双亲表示法一样，结点保存了双亲的域，但同时保存了一个指向所有该结点的孩子的链表的头指针
 链表的实现采用双向循环列表的实现
 树的关键API设计是用什么来定位结点
 根结点是否要直接暴露出去，设计成是固定下标为根结点还是可以指定。
 如果构建一棵树，这个API要怎么设计？
 
 层序在树的应用中是否有价值，暴露层序给用户有什么好处？如果需要维护，用数组的下标来维护好吗？
 层序是否只有在有序树里才能体现，层序是否可以作为排序的依据。

 暴露树的度和深度好像没什么用

 暴露root根结点出去，好像在GUI里应用得比较多。
*/
#ifndef HAVE_CHILD_TREE_H
#define HAVE_CHILD_TREE_H
#include <stdio.h>
#include "common.h"
#include "double_link_list.h"

#ifndef CHILD_TREE_NODE_TYPE
typedef char ChildNodeType;
#endif // !CHILD_TREE_NODE_TYPE


typedef struct ChildNode{
	ChildNodeType data;
	int parent;
	DuLinkList fristChild;
}ChildNode;

#define MAX_TREE_SIZE 100

typedef struct ChildTree {
	ChildNode nodes[MAX_TREE_SIZE];
	int nodeNum;
} ChildTree;

/* 根据文件初始化树 */
Status ChildTree_init(ChildTree * T, FILE *fp);

/* 清空树 */
Status ChildTree_clear(ChildTree * T);

/* 是否为空树 */
Bool ChildTree_isEmpty(ChildTree T);

/* 返回树的度 */
int ChildTree_degree(ChildTree T);

/* 返回树的深度 */
int ChildTree_depth(ChildTree T);

/* 返回树的根结点值 */
ChildNodeType ChildTree_root(ChildTree T);

/* 按层序返回结点的值 */
ChildNodeType ChildTree_vaule(ChildTree T, int order);

/* 根据值返回在树的层序 */
int ChildTree_order(ChildTree T, ChildNodeType data);

/* 替换结点的值 */
Status ChildTree_assign(ChildTree * T, ChildNodeType old, ChildNodeType new);

/* 返回指定结点的第N个孩子结点的值 */
ChildNodeType ChildTree_findChild(ChildTree T, ChildNodeType e, int order);

/* 返回指定结点的第n个兄弟结点的值 */
ChildNodeType ChildTree_findBrother(ChildTree T, ChildNodeType e, int order);

/* 返回指定结点的孩子结点总数 */
int ChildTree_getChildCount(ChildTree T, ChildNodeType e);

/* 在树T搜索值为e的结点下插入子树t */
Status ChildTree_insertTree(ChildTree * T, ChildNodeType e, int order, ChildTree t);

/* 在树T搜索值为e的结点删除其第i棵子树 */
Status ChildTree_deleteTree(ChildTree * T, ChildNodeType e, int order);

/* 层序遍历树 */
void ChildTree_levelOrderTraverse(ChildTree T, void(Visit)(ChildNodeType));

/* 打印树 */
void ChildTree_print(ChildTree T);

/* 判断树是否相等 */
Bool ChildTree_isTheSame(ChildTree T, ChildTree t);
#endif // !HAVE_CHILD_TREE_H
