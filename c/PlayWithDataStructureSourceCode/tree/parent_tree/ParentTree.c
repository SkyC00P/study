#include "ParentTree.h"

Status ParentTree_init(PTree * T)
{
	T->n = 0;
	return OK;
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
	if (ParentTree_isEmpty(T)) {
		return -1;
	}

	for (int i = 0; i < T.n; i++) {
		if (data == T.nodes[i].data) {
			return i + 1;
		}
	}
	return -1;
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
	int count = 0;
	for (int i = 0; i < T.n; i++) {
		if (p == T.nodes[i].data) {
			for (int j = i + 1; j < T.n; j++) {
				if (T.nodes[j].parent == i) {
					count++;
				}
			}
		}
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
				count++;
				if (count == i)
					break;
			}

			k2++;
		}
	}

	return k2;
}

Status ParentTree_insertChild(PTree * T, TElemType p, int i, TElemType e)
{
	int k0, start, end;

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

/* */
Status ParentTree_insertTree(PTree * T, TElemType p, int i, PTree t)
{
	int k;
	if (ParentTree_isEmpty((*T)) || ParentTree_isEmpty(t))				//空树 
		return ERROR;
	for (k = 0; k < t.n; k++)
	{
		if (k == 0)
			ParentTree_insertChild(T, p, i, t.nodes[k].data);
		else
			ParentTree_insertChild(T, t.nodes[t.nodes[k].parent].data, 0, t.nodes[k].data);
	}

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
