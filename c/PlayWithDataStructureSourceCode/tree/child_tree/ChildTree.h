/*
 ���ӱ�ʾ���Ĺؼ�����һά���鱣�����еĽ�㣬��˫�ױ�ʾ��һ������㱣����˫�׵��򣬵�ͬʱ������һ��ָ�����иý��ĺ��ӵ������ͷָ��
 �����ʵ�ֲ���˫��ѭ���б��ʵ��
 ���Ĺؼ�API�������ʲô����λ���
 ������Ƿ�Ҫֱ�ӱ�¶��ȥ����Ƴ��ǹ̶��±�Ϊ����㻹�ǿ���ָ����
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

/* �����ļ���ʼ���� */
Status ChildTree_init(ChildTree * T, FILE *fp);

/* ����� */
Status ChildTree_clear(ChildTree * T);

/* �Ƿ�Ϊ���� */
Bool ChildTree_isEmpty(ChildTree T);

/* �������Ķ� */
int ChildTree_degree(ChildTree T);

/* ����������� */
int ChildTree_depth(ChildTree T);

/* �������ĸ����ֵ */
ChildNodeType ChildTree_root(ChildTree T);

/* �����򷵻ؽ���ֵ */
ChildNodeType ChildTree_vaule(ChildTree T, int order);

/* ����ֵ���������Ĳ��� */
int ChildTree_order(ChildTree T, ChildNodeType data);

/* �滻����ֵ */
Status ChildTree_assign(ChildTree T, ChildNodeType old, ChildNodeType new);

/* ����ָ�����ĵ�N�����ӽ���ֵ */
ChildNodeType ChildTree_findChild(ChildTree T, ChildNodeType e, int order);

/* ����ָ�����ĵ�n���ֵܽ���ֵ */
ChildNodeType ChildTree_findBrother(ChildTree T, ChildNodeType e, int order);

/* ����ָ�����ĺ��ӽ������ */
int ChildTree_getChildCount(ChildNode T, ChildNodeType e);

/* ����T����ֵΪe�Ľ���²�������t */
Status ChildTree_insertTree(ChildTree * T, ChildNodeType e, ChildTree t);

/* ����T����ֵΪe�Ľ��ɾ�����i������ */
Status ChildTree_deleteTree(ChildTree * T, ChildNodeType e, int order);

/* ��������� */
void ChildTree_levelOrderTraverse(ChildTree T, void(Visit)(ChildNodeType));

/* ��ӡ�� */
void ChildTree_print(ChildTree T);

#endif // !HAVE_CHILD_TREE_H
