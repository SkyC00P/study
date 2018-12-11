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

/* �������T (��ʼ����) */
Status CBTree_init(CBTree * T);

/* ����� */
void CBTree_clear(CBTree * T);

/* ������ */
void CBTree_destroy(CBTree * T);

/* �Ƿ��ǿ��� */
Bool CBTree_isEmpty(CBTree T);

/* ���ļ������� */
Status CBTree_create(FILE *fp, CBTree *T);

/* �������Ķ� */
int CBTree_degree(CBTree T);

/* ����������� */
int CBTree_depth(CBTree T);

/* �������ĸ����ֵ */
CBData CBTree_root(CBTree T);

/* �������е�i�����ֵ������������� */
int CBTree_value(CBTree T, int i);

/* ����ָ����e��ָ�룬NULL�����޴˽�㡣 */
CBNodePtr CBTree_order(CBTree T, CBData e);

/* �滻���e��ֵΪvalue */
Status CBTree_assign(CBTree T, CBData old, CBData new);

/* ���ؽ��e�ĵ�order�����ӵ�ֵ���������Ҽ����� */
CBData CBTree_child(CBTree T, CBData e, int order);

/* ���ؽ��e�ĵ�order���ֵܵ�ֵ���������Ҽ����� */
CBData CBTree_brother(CBTree T, CBData e, int order);

/* ���ؽ��p�ĺ��ӽ�㣨���������������ظ���������p�����ڡ� */
int CBTree_child_count(CBTree T, CBData p);

/* ����t����Ϊ��T��e���ĵ�i�������������������i=0����Ϊ���һ�������� */
Status CBTree_insert(CBTree T, CBData e, int i, CBTree t);

/* ɾ����T��e���ĵ�i�������� */
Status CBTree_delete(CBTree T, CBData e, int i);

/* ����������� */
void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData));

/* ǰ������� */
void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData));

/* ��������� */
void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData));

/* ��ӡ�� */
void CBTree_print(CBTree T);
#endif // !HAVE_CHILD_BROTHER_TREE_H
