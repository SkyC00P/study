#include "BinaryTree.h"
#include <math.h>

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

BiTNode * BiTree_parent(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode * BiTree_left_child(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode * BiTree_right_child(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode  * BiTree_left_brother(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode * BiTree_right_brother(BiTree T, BiTData data)
{
	return NULL;
}

BiTNode * BiTree_locate(BiTree T, BiTData data)
{
	return NULL;
}

Status BiTree_insert(BiTree T, BiTData data, BiTree t, bitree_direction direction)
{
	return OK;
}

Status BiTree_delete(BiTree T, BiTData data, bitree_direction direction)
{
	return OK;
}

void BiTree_level_order_traverse(BiTree T, void(Visit)(BiTData))
{
}

void BiTree_in_order_traverse(BiTree T, void(Visit)(BiTData))
{
}

void BiTree_pre_order_traverse(BiTree T, void(Visit)(BiTData))
{
}

void BiTree_post_order_traverse(BiTree T, void(Visit)(BiTData))
{
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
