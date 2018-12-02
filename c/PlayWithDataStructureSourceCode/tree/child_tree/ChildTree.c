#include "ChildTree.h"
static int findIndex(ChildTree * T, char c) {
	if (T->nodeNum == 0) {
		return 0;
	}

	for (int i = 1; i < T->nodeNum; i++) {
		if (T->nodes[i].data == c) {
			return i;
		}
	}
	return -1;
}
Status ChildTree_init(ChildTree * T, FILE *fp) {
	ChildNodeType ch;
	T->nodeNum = 0;

	while (!feof(fp)) {

		// 获得子树的根结点
		fscanf(fp, "%c", &ch);
		// 找到该字符在数组的下标，0表示根结点
		int index = findIndex(T, ch);
		ChildNode * root;
		if (index == 0) {
			root = &(T->nodes[T->nodeNum]);
			root->data = ch;
			root->parent = -1;
			root->fristChild = NULL;
			T->nodeNum++;
		}
		else {
			root = &(T->nodes[index]);
			root->fristChild = NULL;
		}

		ch = fgetc(fp);
		if (ch != '=') {
			fprintf(stderr, "File Read Error, expect is '='\n");
			return ERROR;
		}
		
		while (1) {
			ch = fgetc(fp);
			if (ch == '\n' || ch == EOF) {
				break;
			}
			ChildNode * node = &(T->nodes[T->nodeNum]);
			node->data = ch;
			node->parent = index;
			if (!root->fristChild) {
				InitList(&root->fristChild);
			}

			ListInsert(&root->fristChild, ListLength(root->fristChild) + 1, T->nodeNum);
			T->nodeNum++;
		}
	}

	return OK;
}

/* 1. 数组长度重置为0
   2. 清掉孩子链表
 */
Status ChildTree_clear(ChildTree * T)
{
	if (!T) {
		return ERROR;
	}
	if (T->nodeNum == 0) {
		return OK;
	}

	for (int i = 0; i < T->nodeNum; i++)
	{
		if (T->nodes[i].fristChild) {
			ClearList(&(T->nodes[i].fristChild));
		}
		T->nodes[i].data = 0;
		T->nodes[i].parent = 0;
	}
	T->nodeNum = 0;
	return OK;
}

Bool ChildTree_isEmpty(ChildTree T)
{
	return T.nodeNum == 0 ? TRUE : FALSE;
}

/* 遍历所有的结点的孩子链表，取最长 */
int ChildTree_degree(ChildTree T)
{
	if (T.nodeNum == 0) {
		return 0;
	}
	
	int max = 0;
	for (int i = 0; i < T.nodeNum; i++) {
		if (T.nodes[i].fristChild) {
			int len = ListLength(T.nodes[i].fristChild);
			if (len > max) {
				max = len;
			}
		}
	}
	return max;
}

/* 我这里的实现是有序树，所以可以追踪数组的最后一位到根结点的距离来算出树的深度 */
int ChildTree_depth(ChildTree T)
{
	int depth = 0;
	if (T.nodeNum) {
		ChildNode tail = T.nodes[T.nodeNum - 1];
		while (tail.parent != -1)
		{
			depth++;
			tail = T.nodes[tail.parent];
		}
		depth += 1;
	}
	return depth;
}

ChildNodeType ChildTree_root(ChildTree T)
{
	return T.nodeNum ? T.nodes[0].data : '\0';
}

ChildNodeType ChildTree_vaule(ChildTree T, int order)
{
	return T.nodeNum == 0 ? '\0' : T.nodes[order].data;
}

int ChildTree_order(ChildTree T, ChildNodeType data)
{
	if (T.nodeNum == 0) {
		return -1;
	}
	for (int i = 0; i < T.nodeNum; i++) {
		if (T.nodes[i].data == data) {
			return i;
		}
	}
	return -1;
}

Status ChildTree_assign(ChildTree * T, ChildNodeType old, ChildNodeType new)
{
	int order = ChildTree_order(*T, old);
	if (order != -1) {
		T->nodes[order].data = new;
		return OK;
	}
	return ERROR;
}

ChildNodeType ChildTree_findChild(ChildTree T, ChildNodeType e, int corder)
{
	int order = ChildTree_order(T, e);
	if (order != -1) {
		DuLinkList list = T.nodes[order].fristChild;
		if (list) {
			ElemType e;
			GetElem(list, corder, &e);
			return T.nodes[e].data;
		}
	}
	return '\0';
}

ChildNodeType ChildTree_findBrother(ChildTree T, ChildNodeType e, int corder)
{
	int order = ChildTree_order(T, e);

	if (order < 0) {
		return '\0';
	}

	int parent = T.nodes[order].parent;
	ChildNode * pNode = &(T.nodes[parent]);
	DuLinkList list = pNode->fristChild;

	if (!list) {
		return '\0';
	}

	int count = 0;
	int len = ListLength(list);

	for (int i = 0; i < len; i++) {
		if (list->data != e) {
			count++;
		}

		if (count == corder) {
			return list->data;
		}

		list = list->next;
	}

	return '\0';
}

int ChildTree_getChildCount(ChildTree T, ChildNodeType e)
{
	int order = ChildTree_order(T, e);
	if (order < 0) {
		return -1;
	}
	if (T.nodes[order].fristChild) {
		return ListLength(T.nodes[order].fristChild);
	}
	return 0;
}

Status ChildTree_insertTree(ChildTree * T, ChildNodeType e, ChildTree t)
{
	return OK;
}

Status ChildTree_deleteTree(ChildTree * T, ChildNodeType e, int order)
{
	return OK;
}

/* 这里的层序直接按数组的下标来就行了 */
void ChildTree_levelOrderTraverse(ChildTree T, void(Visit)(ChildNodeType))
{
	if (T.nodeNum == 0) {
		return;
	}
	for (int i = 0; i < T.nodeNum; i++) {
		Visit(T.nodes[i].data);
	}
	printf("\n");
}

void ChildTree_print(ChildTree T)
{
	printf("| %-3s | %-4s | %6s | child\n", "i", "data", "parent");
	if (T.nodeNum) {
		for (int i = 0; i < T.nodeNum; i++) {
			ChildNode node = T.nodes[i];
			printf("| %-3.1d |  %-3c |    %-3d | ", i, node.data, node.parent);
			if (node.fristChild) {
				int len = ListLength(node.fristChild);
				if (len == 0) {
					printf("ERR:O\n");
				}
				else
				{
					for (int j = 1; j <= len; j++) {
						ElemType e;
						GetElem(node.fristChild, j, &e);
						printf("%d ", e);
					}
					printf("\n");
				}

			}
			else
			{
				printf("null\n");
			}
		}
		printf("\n");
	}
}
