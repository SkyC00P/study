/*
 ���������� - ��Ҫ��������������ҽ���ǰ���ͺ��
*/
#ifndef HAVE_THREAD_BINARY_TREE_H
#define HAVE_THREAD_BINARY_TREE_H

#include "common.h"

typedef char TBData;
typedef enum {Link, Thread} PointerTag;
typedef struct TBNode {
	TBData data;
	PointerTag ltag, rtag;
	struct TBNode * lchild;
	struct TBNode * rchild;
}TBNode, *TBTree;

/*���������й�������������������ӱ�־(��������)*/
Status TBTree_create(FILE * fp, TBTree * t);

/*����ȫ��������*/
void TBTree_inThreading(TBTree t);

/*�������������T��������ȫ������*/
Status TBTree_inorder_Threading(TBTree * T, TBTree t);

/*�����������ȫ�������������ǵݹ��㷨��*/
Status TBTree_inOrder_traverse(TBTree T, void(Visit)(TBData));

/*��������������*/
void TBTree_preThreading(TBTree t);

/*�������������T������������������*/
Status TBTree_preorder_Threading(TBTree * T, TBTree t);

/*�������ǰ�����������������ǵݹ��㷨����*/
Status TBTree_preOrder_traverse(TBTree T, void(Visit)(TBData));

/*��������������*/
void TBTree_postThreading(TBTree t);

/*�������������T������������������*/
Status TBTree_postorder_Threading(TBTree * T, TBTree t);

/*��������������������������ǵݹ��㷨��*/
Status TBTree_postOrder_traverse(TBTree T, void(Visit)(TBData));

/*�����������������������˫�׽��ָ�롣*/
void TBTree_parent(TBTree T);

/*�ں����������������������ʱ��Ѱ�ҽ��p�ĺ�̡�*/
TBTree TBTree_post_next(TBTree t, TBTree p);

#endif // !HAVE_THREAD_BINARY_TREE_H