#include "ChildBrotherTree.h"
#include <ctype.h>

Status CBTree_init(CBTree * T)
{
	if (*T) { return ERROR; }
	*T = NULL;
	return OK;
}

void CBTree_clear(CBTree * T)
{
}

void CBTree_destroy(CBTree * T)
{
}

Bool CBTree_isEmpty(CBTree T)
{
	return T == NULL ? TRUE : FALSE;
}
/*
 ?��θ����ļ��Ķ�����������Ҳ����Ҫ��API
 ?������ΰ�html������dom������ν���������ɱ��ʽ��

�ⷨ:ÿ������㶼�������ݣ�����ӣ����ֵ�����ֵ����������򽫽���������С�����
	R	A	^
	A	D	B
	B	^	C
	C	F	^
	D	^	E
	E	^	^
	F	G	^
	G	^	H
	H	^	K
	K	^	^
1. ÿ�ζ�ȡ����ֵ��������2����㣬һ����һ���������������ʹ�ò������Ľ������һ�������µĲ�����������ֵΪ0��1��2
2. ���ܵĲ��������Ϊn����һ�ζ�ȡʱ��nΪ1(�����)����ÿ�ζ�ȡ��n�Ľ������Ϊ n-1, n, n+1
3. ÿһ��Ҷ�ӽ�㶼��ʹn-1, Ҳ����˵������ʼ��OKʱ��nΪ0�������һ��Ҷ�ӽ��Ҳ����ȡ������
����������Ҫһ�����ҽṹ��Key - Value��Map
*/
Status CBTree_create(FILE * fp, CBTree * T)
{
	CheckPtr(fp);
	CheckPtr(T);

	CBTree tree = *T;
	CBData ch;
	// ��ø����
	fscanf(fp, "%c", &ch);
	if (!CBTree_isEmpty(tree) || isspace(ch)) {
		return ERROR;
	}

	tree = malloc(sizeof(CBNode));
	tree->nextBrother = NULL;
	tree->fristChild = NULL;
	tree->data = ch;

	CBTree root = tree;
	CBTree child, brother;
	while (!feof(fp)){
		// ����=��
		ch = fgetc(fp);
		if (ch != '=') {
			fprintf(stderr, "File Read Error, expect is '='\n");
			return ERROR;
		}
		// ��ȡ���ӽ��
		while (1){
			ch = fgetc(fp);
			if (ch == '\n' || ch == EOF) {
				break;
			}
			CBNodePtr node = malloc(CBNode);
			node->data = ch;
			if (!root->fristChild) {
				root->fristChild = node;
			}
		}
	}
	return OK;
}

int CBTree_degree(CBTree T)
{
	return 0;
}

int CBTree_depth(CBTree T)
{
	return 0;
}

CBData CBTree_root(CBTree T)
{
	return 0;
}

int CBTree_value(CBTree T, int i)
{
	return 0;
}

CBNodePtr CBTree_order(CBTree T, CBData e)
{
	return NULL;
}

Status CBTree_assign(CBTree T, CBData old, CBData new)
{
	return OK;
}

CBData CBTree_child(CBTree T, CBData e, int order)
{
	return 0;
}

CBData CBTree_brother(CBTree T, CBData e, int order)
{
	return 0;
}

int CBTree_child_count(CBTree T, CBData p)
{
	return 0;
}

Status CBTree_insert(CBTree T, CBData e, int i, CBTree t)
{
	return OK;
}

Status CBTree_delete(CBTree T, CBData e, int i)
{
	return OK;
}

void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_print(CBTree T)
{
}
