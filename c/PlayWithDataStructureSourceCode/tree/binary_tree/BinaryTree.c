#include "BinaryTree.h"
#include <math.h>
#include "help/stack.h"
/* �ݹ�ⷨ */
void BiTree_clear(BiTree * T)
{
	if (*T) {
		BiTree_clear(&((*T)->lchild));
		BiTree_clear(&((*T)->rchild));
		free(*T);
		*T = NULL;
	}

}

Bool BiTree_isEmpty(BiTree T)
{
	return T == NULL ? TRUE : FALSE;
}

/* �ݹ�ⷨ */
Status BiTree_create(FILE * fp, BiTree * T)
{
	CheckPtr(fp);
	char ch;
	fscanf(fp, "%c", &ch);
	if (ch == '^') {
		*T = NULL;
		return OK;
	}
	*T = malloc(sizeof(BiTNode));
	if (!(*T)) {
		exit(OVERFLOW);
	}
	(*T)->data = ch;
	BiTree_create(fp, &(*T)->lchild);
	BiTree_create(fp, &(*T)->rchild);
	return OK;
}

/*
 �ݹ�ⷨ
*/
int BiTree_depth(BiTree T)
{
	int LD, RD;
	if (T == NULL) {
		return 0;
	}

	LD = BiTree_depth(T->lchild);
	RD = BiTree_depth(T->rchild);
	return (LD >= RD ? LD : RD) + 1;
}

/* �ݹ�ⷨ */
BiTNode * BiTree_parent(BiTree T, BiTData data)
{

	if (!T) {
		return NULL;
	}
	else if (T->lchild && T->lchild->data == data)
	{
		return T;
	}
	else if (T->rchild && T->rchild->data == data) {
		return T;
	}

	BiTNode * node = NULL;
	node = BiTree_parent(T->lchild, data);
	if (!node) {
		node = BiTree_parent(T->rchild, data);
	}

	return node;
}

BiTNode * BiTree_left_child(BiTree T, BiTData data)
{
	BiTNode * node = BiTree_locate(T, data);
	if (node) {
		return node->lchild;
	}
	return node;
}

BiTNode * BiTree_right_child(BiTree T, BiTData data)
{
	BiTNode * node = BiTree_locate(T, data);
	if (node) {
		return node->rchild;
	}
	return node;
}

BiTNode * BiTree_left_brother(BiTree T, BiTData data)
{
	if (!T) {
		return NULL;
	}
	BiTNode * node = BiTree_parent(T, data);
	if (node && node->lchild && node->lchild->data != data)
	{
		return node->lchild;
	}
	return NULL;
}

BiTNode * BiTree_right_brother(BiTree T, BiTData data)
{
	if (!T) {
		return NULL;
	}
	BiTNode * node = BiTree_parent(T, data);
	if (node && node->rchild && node->rchild->data != data)
	{
		return node->rchild;
	}
	return NULL;
}

/* �ݹ�ⷨ */
BiTNode * BiTree_locate(BiTree T, BiTData data)
{
	if (T && T->data == data) {
		return T;
	}
	if (T) {
		BiTNode * node = BiTree_locate(T->lchild, data);
		if (!node) {
			node = BiTree_locate(T->rchild, data);
		}
		return node;
	}
	return NULL;
}

Status BiTree_insert(BiTree T, BiTData data, BiTree t, bitree_direction direction)
{
	BiTNode * node = BiTree_locate(T, data);
	if (!node) {
		return ERROR;
	}

	if (direction == bitree_direction_left_0) {
		if (node->lchild) {
			BiTree_clear(&(node->lchild));
		}
		node->lchild = t;
	}
	else if (direction == bitree_direction_right_1) {
		if (node->rchild) {
			BiTree_clear(&(node->rchild));
		}
		node->rchild = t;
	}
	return OK;
}

Status BiTree_delete(BiTree T, BiTData data, bitree_direction direction)
{
	BiTNode * node = BiTree_locate(T, data);
	if (node) {
		switch (direction) {
		case bitree_direction_left_0: BiTree_clear(&(node->lchild)); break;
		case bitree_direction_right_1:BiTree_clear(&(node->rchild)); break;
		default:break;
		}
		return OK;
	}
	return ERROR;
}

/* ���������䵱���� */
void BiTree_level_order_traverse(BiTree T, void(Visit)(BiTData))
{
	int i, j;
	BiTree p[100];

	i = j = 0;

	if (T)
		p[j++] = T;

	while (i < j)
	{
		Visit(p[i]->data);
		if (p[i]->lchild)
			p[j++] = p[i]->lchild;
		if (p[i]->rchild)
			p[j++] = p[i]->rchild;
		i++;
	}
}

/* 
  �ǵݹ�汾 - ������� 
	1 ����һ����ջ����Ϊstack������һ������cur����ʼʱ��curΪͷ�ڵ㣻
	2 �Ȱ�cur�ڵ�ѹ��ջ�У�����cur�ڵ�Ϊͷ������������˵�����ΰ���������������ѹ��ջ�У���������cur=cur.left��Ȼ���ظ�����2��
	3 �����ظ�����2��ֱ������curΪ�գ���ʱ��stack�е���һ���ڵ��Ϊnode����ӡnode��ֵ������cur = node.right��Ȼ������ظ�����2��
	4 ��stackΪ�ղ���curΪ��ʱ������

*/
void BiTree_in_order_traverse(BiTree T, void(Visit)(BiTData))
{
	if (!T) {
		return;
	}
	LinkStack stack = LinkStack_init();
	BiTree cur = T;
	while (!LinkStack_empty(stack) || cur != NULL) {
		while (cur)
		{
			LinkStack_push(stack, cur);
			cur = cur->lchild;
		}
		cur = LinkStack_pop(stack);
		Visit(cur->data);
		cur = cur->rchild;
	}
	LinkStack_destory(stack);
}

/*
 �ǵݹ�汾 - ǰ�����
	1 ��������һ���µ�ջ����Ϊstack��
	2 ��ͷ���headѹ��stack�У�
	3 ÿ�δ�stack�е���ջ���ڵ㣬��Ϊcur��Ȼ���ӡcurֵ�����cur�Һ��Ӳ�Ϊ�գ����Һ���ѹ��ջ�У����cur�����Ӳ�Ϊ�գ�����ѹ��stack�У�
	4 �ظ�����3��ֱ��stackΪ��
*/

void BiTree_pre_order_traverse(BiTree T, void(Visit)(BiTData))
{
	if (!T) {
		return;
	}
	LinkStack stack = LinkStack_init();
	LinkStack_push(stack, T);

	while (!LinkStack_empty(stack)) {
		BiTNode * node = LinkStack_pop(stack);
		if (node) {
			Visit(node->data);
			if (node->rchild) {
				LinkStack_push(stack, node->rchild);
			}
			if (node->lchild) {
				LinkStack_push(stack, node->lchild);
			}
		}
	}
	LinkStack_destory(stack);
}

/* �ǵݹ�汾 - �������
	1 ��������ջstack1��stack2��Ȼ��ͷ���ѹ��stack1�У�
	2 ��stack1�е����Ľڵ��Ϊcur��Ȼ���Ȱ�cur������ѹ��stack1�У��ٰ�cur���Һ���ѹ��stack1�У�
	3 �����������У�ÿһ����stack1�е����Ľڵ㶼���ڵڶ���ջstack2�У�
	4 �����ظ�����2�Ͳ���3��ֱ��stack1Ϊ�գ�����ֹͣ��
	5 ��stack2�����ε����ڵ㲢��ӡ����ӡ��˳����Ǻ��������˳��
*/
void BiTree_post_order_traverse(BiTree T, void(Visit)(BiTData))
{
	if (!T) {
		return;
	}
	LinkStack s1 = LinkStack_init();
	LinkStack s2 = LinkStack_init();
	LinkStack_push(s1, T);
	BiTNode * node;
	while (!LinkStack_empty(s1))
	{
		node = LinkStack_pop(s1);
		LinkStack_push(s2, node);
		if (node->lchild) {
			LinkStack_push(s1, node->lchild);
		}
		if (node->rchild) {
			LinkStack_push(s1, node->rchild);
		}
	}

	while (!LinkStack_empty(s2)) {
		node = LinkStack_pop(s2);
		Visit(node->data);
	}

	LinkStack_destory(s1);
	LinkStack_destory(s2);
}

void BiTree_print(BiTree T)
{
	CheckPtr(T);
	BiTNode a[100][100] = {};

	int row = BiTree_depth(T);
	int col = pow(2, row) - 1;
	int i, j, m, l, r;
	for (i = 1; i <= row - 1; i++)
	{
		for (j = 1; j <= pow(2, i - 1); j++)
		{
			m = (2 * j - 1)*pow(2, row - i);		//��ǰ�н�����λ�� 
			l = (4 * j - 3)*pow(2, row - i - 1);	//��һ�н�����λ�� 
			r = (4 * j - 1)*pow(2, row - i - 1);

			if (i == 1)						//��ʼ�� 
				a[i][m] = *T;

			if (a[i][m].lchild)				//��һ�� 
				a[i + 1][l] = *(a[i][m].lchild);

			if (a[i][m].rchild)				//��һ�� 
				a[i + 1][r] = *(a[i][m].rchild);
		}
	}

	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (a[i][j].data)
				printf("%c", a[i][j].data);
			else
				printf(" ");
		}
		printf("\n");
	}
}
