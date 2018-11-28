#include "ParentTree.h"
Status ParentTree_init(PTree * T)
{
	T->n = 0;
	return OK;
}

void ParentTree_clear(PTree * T)
{
	T->n = 0;
}

void ParentTree_destory(PTree * T)
{

}

Bool ParentTree_isEmpty(PTree T)
{
	return T.n == 0 ? TRUE : FALSE;
}

#include "Scanf.c"
/* 这构建的是个有序树 */
Status ParentTree_create(FILE * fp, PTree * T)
{
	TElemType ch, p, tmp;
	int i, j;

	Scanf(fp, "%c", &ch);
	printf("录入树的根结点 %c \n", ch);
	Scanf(fp, "%c", &tmp);
	if (ch != '^')
	{
		i = 0;										//根结点起点设为0
		(*T).nodes[i].data = ch;
		(*T).nodes[i].parent = -1;

		j = -1;
		while (!feof(fp))
		{
			Scanf(fp, "%c", &p);
			printf("依次录入 %c 的孩子结点：", p);
			j++;
			while (1)
			{
				Scanf(fp, "%c", &ch);
				if (ch == '^' || ch == '\n')
				{
					if (ch == '^')
					{
						printf("%c", ch);
						Scanf(fp, "%c", &tmp);		//跳过换行符 
					}

					break;
				}
				else
				{
					printf("%c", ch);
					i++;
					(*T).nodes[i].data = ch;
					(*T).nodes[i].parent = j;
				}
			}

			printf("\n");
		}

		(*T).n = i + 1;
	}
	return OK;
}

/* 树的度就是树的结点的最大度，也就是拥有最多孩子的结点，
  那只能遍历数组获得每个结点的度再进行比较。
 */
int ParentTree_degree(PTree T)
{
	int max, count, index;
	max = count = index = 0;
	while (index < T.n) {
		count = 0;
		for (int i = 1; i < T.n; i++) {
			if (T.nodes[i].parent == index) {
				count++;
			}
		}

		if (count > max) {
			max = count;
		}
		index++;
	}
	return max;
}

/*
 树的深度(高度)就是根结点到叶子结点的路径最长时候的路径长度
 由于按层序排序，所以最后一个结点肯定在最大层。
*/
int ParentTree_depth(PTree T)
{
	int k, level;

	k = T.n - 1;
	level = 0;

	if (T.n != 0)
	{
		while (k != -1)
		{
			level++;
			k = T.nodes[k].parent;
		}

	}
	return level;
}

TElemType ParentTree_root(PTree T)
{
	return ParentTree_isEmpty(T) ? '\0' : T.nodes[0].data;
}

TElemType ParentTree_value(PTree T, int i)
{
	return ParentTree_isEmpty(T) ? '\0' : T.nodes[i - 1].data;
}

int ParentTree_order(PTree T, TElemType data)
{
	int i;
	int k = -1;

	for (i = 0; i < T.n; i++)
	{
		if (T.nodes[i].data == data)
		{
			k = i;
			break;
		}
	}

	return k;
}

Status ParentTree_assign(PTree * T, TElemType e, TElemType value)
{
	if (ParentTree_isEmpty(*T)) {
		return ERROR;
	}

	for (int i = 0; i < T->n; i++) {
		if (e == T->nodes[i].data) {
			T->nodes[i].data = value;
			break;
		}
	}
	return OK;
}

TElemType ParentTree_childVaule(PTree T, TElemType e, int order)
{
	int p,count = 0;
	for (int i = 0; i < T.n; i++)
	{
		p = T.nodes[i].parent;
		if (T.nodes[p].data == e) {
			count++;
			if (count == order) {
				return T.nodes[i].data;
			}
		}
	}
		return '\0';
}

TElemType ParentTree_siblingVaule(PTree T, TElemType e, int order)
{
	int p = 0;
	for (int i = 0; i < T.n; i++) {
		if (T.nodes[i].data == e) {
			p = T.nodes[i].parent;
			break;
		}
	}

	int count = 0;
	for (int i = 0; i < T.n; i++) {
		if (p == T.nodes[i].parent && T.nodes[i].data != e) {
			count++;
			if (count == order) {
				return T.nodes[i].data;
			}
		}
	}
	return '\0';
}

int ParentTree_ChildCount(PTree T, TElemType p)
{
	int k1, k2, count;

	if (ParentTree_isEmpty(T))						//空树 
		return -1;

	k1 = ParentTree_order(T, p);

	if (k1 < 0)								//p结点不存在 
		return -2;

	k2 = k1 + 1;
	count = 0;
	while (k2 < T.n)							//统计孩子个数 
	{
		if (T.nodes[k2].parent == k1)
			count++;
		if (T.nodes[k2].parent > k1)
			break;
		k2++;
	}

	return count;
}

int ParentTree_seat(PTree T, TElemType p, int i)
{
	int k0, k1, k2, count;

	if (ParentTree_isEmpty(T))							//空树 
		return -1;

	k0 = ParentTree_ChildCount(T, p);		//k0标记孩子个数 

	if (i < 0 || k0<0 || i>k0 + 1)		//插入位置不正确 
		return -2;

	k1 = ParentTree_order(T, p);

	k2 = k1 + 1;
	if (i == 0)						//此时i为p最后一个结点的下一个位置
	{
		while (k2 < T.n)
		{
			if (T.nodes[k2].parent > k1)
				break;
			k2++;
		}
	}
	else
	{
		count = 0;

		while (k2 < T.n)
		{
			if (T.nodes[k2].parent >= k1)
			{
				if (count == i)
					break;
				count++;
			}

			k2++;
		}
	}

	return k2;
}

/* 插入孩子结点的弊端在于要数组都要后移一位，而且要保证层序号一致 */
Status ParentTree_insertChild(PTree * T, TElemType p, int i, TElemType e)
{
	int k0, start, end;

	if (ParentTree_isEmpty(*T) || !e) {
		return ERROR;
	}

	k0 = 0;									//k0标记p的位置 
	while (k0 < (*T).n)
	{
		if ((*T).nodes[k0].data == p)
			break;
		k0++;
	}

	if (k0 == (*T).n)							//p不存在 
		return ERROR;

	start = ParentTree_seat(*T, p, i);			//e结点的插入位置
	printf("[ParentTree_insertChild] 插入的位置:%d\n", start);
	if (start <= 0)							//插入位置不正确 
		return ERROR;

	end = (*T).n;
	while (end > start)
	{
		(*T).nodes[end].data = (*T).nodes[end - 1].data;
		if ((*T).nodes[end - 1].parent < start)
			(*T).nodes[end].parent = (*T).nodes[end - 1].parent;
		else
			(*T).nodes[end].parent = (*T).nodes[end - 1].parent + 1;
		end--;
	}

	(*T).nodes[start].data = e;
	(*T).nodes[start].parent = k0;
	(*T).n++;

	return OK;
}

/* 
 插入子树有个特殊的要求：插入的子树里的结点跟原来被插的树结点不能重合
*/
Status ParentTree_insertTree(PTree * T, TElemType p, int i, PTree t)
{
	if (ParentTree_isEmpty((*T)) || ParentTree_isEmpty(t))				//空树 
		return ERROR;
	for (int k = 0; k < t.n; k++)
	{
		if (k == 0)
			// 在树T的p结点的第i个位置插入孩子结点 t的根结点
			ParentTree_insertChild(T, p, i, t.nodes[k].data);
		else
			// 在树T的上一个以插好的父节点追加孩子结点
			ParentTree_insertChild(T, t.nodes[t.nodes[k].parent].data, 0, t.nodes[k].data);
	}

	return OK;
}

Status ParentTree_delteTree(PTree * T, TElemType p, int i)
{
	int k1;											//k1标记p的位置 
	int k2, count;									//k2标记第i棵子树起点 
	int k3;
	int stack[MAX_TREE_NODE], m, n;
	int k4, k5, order[MAX_TREE_NODE] = {};

	// 找到p的位置 k1
	for (k1 = 0; k1 < (*T).n; k1++)
	{
		if ((*T).nodes[k1].data == p)
			break;
		if (k1 == (*T).n - 1)
			return ERROR;
	}
	// --
	// 找p位置下要删除的子树结点 k2
	count = 0;
	for (k2 = k1 + 1; k2 < (*T).n; k2++)
	{
		if ((*T).nodes[k2].parent == k1)
		{
			count++;
			if (count == i)
				break;
		}
		if (k2 == (*T).n - 1)
			return ERROR;
	}
	// --

	m = n = 0;
	stack[n] = k2;
	n++;
	(*T).nodes[k2].data = '\0';					//抹掉此处的值

	k3 = k2 + 1;
	while (k3 < (*T).n && m < n)
	{
		if ((*T).nodes[k3].parent < stack[m])
			k3++;
		else if ((*T).nodes[k3].parent > stack[m])
			m++;
		else		//(*T).nodes[k3].parent==stack[m]
		{
			(*T).nodes[k3].data = '\0';					//抹掉此处的值
			stack[n] = k3;
			n++;
			k3++;
		}
	}

	k5 = 0;
	for (k4 = 0; k4 < (*T).n; k4++)							//遍历树，找出各结点现在的实际位置 
	{
		if ((*T).nodes[k4].data)
		{
			order[k4] = k5;
			k5++;

			if (k4)										//不为头结点 
				(*T).nodes[k4].parent = order[(*T).nodes[k4].parent];	//当前结点双亲结点位置发生变化 
		}
	}

	k4 = -1;
	k5 = 0;
	while (k5 < (*T).n)										//遍历，去掉删除的结点 
	{
		if ((*T).nodes[k5].data)
		{
			k4++;
			(*T).nodes[k4].data = (*T).nodes[k5].data;
			(*T).nodes[k4].parent = (*T).nodes[k5].parent;
		}

		k5++;
	}

	(*T).n = k4 + 1;

	return OK;
}

void ParentTree_levelOrderTraverse(PTree T, void(Visit)(TElemType))
{
	for (int i = 0; i < T.n; i++) {
		Visit(T.nodes[i].data);
	}
}

void ParentTree_print(PTree T)
{
	printf("Node size is %d\n", T.n);
	printf("%-2c %s %-6s\n", 'i', "data", "parent");
	for (int i = 0; i < T.n; i++) {
		printf("%-2d   %c    %d\n", i, T.nodes[i].data, T.nodes[i].parent);
	}
	printf("\n");
}
