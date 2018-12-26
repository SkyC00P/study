#include "BinaryTree.h"
#include <math.h>
#include "help/stack.h"
/* 递归解法 */
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

/* 递归解法 */
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
 递归解法
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

/* 递归解法 */
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

/* 递归解法 */
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

/* 用数组来充当队列 */
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
  非递归版本 - 中序遍历 
	1 申请一个新栈，记为stack，申请一个变量cur，初始时令cur为头节点；
	2 先把cur节点压入栈中，对以cur节点为头的整棵子树来说，依次把整棵树的左子树压入栈中，即不断令cur=cur.left，然后重复步骤2；
	3 不断重复步骤2，直到发现cur为空，此时从stack中弹出一个节点记为node，打印node的值，并让cur = node.right，然后继续重复步骤2；
	4 当stack为空并且cur为空时结束。

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
 非递归版本 - 前序遍历
	1 首先申请一个新的栈，记为stack；
	2 将头结点head压入stack中；
	3 每次从stack中弹出栈顶节点，记为cur，然后打印cur值，如果cur右孩子不为空，则将右孩子压入栈中；如果cur的左孩子不为空，将其压入stack中；
	4 重复步骤3，直到stack为空
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

/* 非递归版本 - 后序遍历
	1 申请两个栈stack1，stack2，然后将头结点压入stack1中；
	2 从stack1中弹出的节点记为cur，然后先把cur的左孩子压入stack1中，再把cur的右孩子压入stack1中；
	3 在整个过程中，每一个从stack1中弹出的节点都放在第二个栈stack2中；
	4 不断重复步骤2和步骤3，直到stack1为空，过程停止；
	5 从stack2中依次弹出节点并打印，打印的顺序就是后序遍历的顺序；
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
			m = (2 * j - 1)*pow(2, row - i);		//当前行结点相对位序 
			l = (4 * j - 3)*pow(2, row - i - 1);	//下一行结点相对位序 
			r = (4 * j - 1)*pow(2, row - i - 1);

			if (i == 1)						//初始化 
				a[i][m] = *T;

			if (a[i][m].lchild)				//下一行 
				a[i + 1][l] = *(a[i][m].lchild);

			if (a[i][m].rchild)				//下一行 
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
