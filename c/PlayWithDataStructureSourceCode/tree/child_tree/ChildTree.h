/*
 孩子表示法的关键点用一维数组保存所有的结点，跟双亲表示法一样，结点保存了双亲的域，但同时保存了一个指向所有该结点的孩子的链表的头指针
 链表的实现采用双向循环列表的实现
 树的关键API设计是用什么来定位结点
*/
#ifndef HAVE_CHILD_TREE_H
#define HAVE_CHILD_TREE_H
#include <stdio.h>
#include "common.h"
#include "double_link_list.h"

#ifndef CHILD_TREE_NODE_TYPE
typedef char ChildNodeType;
#endif // !CHILD_TREE_NODE_TYPE


typedef strcut ChildNode{
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
Status ChildTree_Assign(ChildTree T, ChildNodeType old, ChildNodeType new);

ChildNodeType 

#endif // !HAVE_CHILD_TREE_H
