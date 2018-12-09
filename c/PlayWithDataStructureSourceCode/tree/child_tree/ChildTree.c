#include "ChildTree.h"
#include <stdlib.h>

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

// 这里我忘了我的循环链表是用尾指针来实现的,而且当初没有实现一个遍历链表的方法
// 这里直接操作结构体里的细节了
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
	list = list->next->next;

	ChildNodeType data;
	for (int i = 1; i <= len; i++) {
		data = T.nodes[list->data].data;
		if (data != e) {
			count++;
		}

		if (count == corder) {
			return data;
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

/*
 必须保证order非负数
 1. 如果孩子链表为空，即插入叶子结点时，则插入位置为从父结点开始第一个双亲大于父结点的结点
 2. 如果孩子链表不为空，看order情况
  1. 如果order为0或order大于列表长度，则插入位置为末尾的孩子下标 + 1
  2. 如果 1 <= order <= listLen, 则插入的值为list在order位置的值
*/
static int ChildTree_findInsertIndex(ChildTree T, int parent, int order) {
	if (order < 0) {
		fprintf(stderr, "[ChildTree_findInsertIndex] 非负数\n");
		return -1;
	}

	ChildNode * pNode = &(T.nodes[parent]);
	if (!pNode->fristChild) {
		for (int i = parent + 1; i < T.nodeNum; i++) {
			if (T.nodes[i].parent > parent) {
				return i;
			}
		}
		// 如果没找到，代表插入的是最末尾的叶子结点
		return parent + 1;
	}

	int len = ListLength(pNode->fristChild);
	if (order == 0 || order > len) {
		return pNode->fristChild->data + 1;
	}

	if (order >= 1 && order <= len) {
		ElemType e;
		GetElem(pNode->fristChild, order, &e);
		return e;
	}

	return -1;
}

/* 1. 确定插入的结点的数据:
	1. 插入的下标
	2. 结点的双亲的下标
	3. 孩子链表置空(因为是以叶子结点插入的)
	4. 数据已知
   2. 修改双亲结点的孩子链表
   3. 腾出新的位置，将插入位置下的所有位置下移一位，保持数据不变
   4. 遍历祖父结点到最后的叶节点，修改孩子链表和双亲结点的值
   5. 在腾出的新位置上插入数据
*/
Status ChildTree_insertChild(ChildTree * T, ChildNodeType e, ChildNodeType new, int order) {
	int parent = ChildTree_order(*T, e);
	if (parent < 0) {
		return ERROR;
	}

	int insertIndex = ChildTree_findInsertIndex(*T, parent, order);
	if (insertIndex < 0 || T->nodeNum + 1 > MAX_TREE_SIZE) {
		return ERROR;
	}

	ChildNode * parentNode = &(T->nodes[parent]);
	if (!parentNode->fristChild) {
		InitList(&(parentNode->fristChild));
		ListInsert(&(parentNode->fristChild), 1, insertIndex);
	}
	else {
		int lastIndex = parentNode->fristChild->data;
		ListInsert(&(parentNode->fristChild), ListLength(parentNode->fristChild) + 1, lastIndex + 1);
	}

	for (int i = T->nodeNum; i > insertIndex; i--) {
		T->nodes[i].data = T->nodes[i - 1].data;
		T->nodes[i].parent = T->nodes[i - 1].parent;
		T->nodes[i].fristChild = T->nodes[i - 1].fristChild;
	}

	int grandpa = T->nodes[parent].parent;
	for (int i = grandpa + 1; i <= T->nodeNum; i++) {
		if (i == insertIndex || i == parent) {
			continue;
		}

		ChildNode * node = &(T->nodes[i]);
		if (node->parent >= insertIndex) {
			node->parent = node->parent + 1;
		}

		if (node->fristChild) {
			Node * n; int i;
			for (n = node->fristChild, i = ListLength(node->fristChild); i > 0; i--)
			{
				if (n->data >= insertIndex) {
					n->data = n->data + 1;
				}
				n = n->prior;
			}
		}
	}

	T->nodes[insertIndex].data = new;
	T->nodes[insertIndex].fristChild = NULL;
	T->nodes[insertIndex].parent = parent;
	T->nodeNum++;
	return OK;
}

/* 插入时如果要维护层序，那么数组的实现是否真的好？
   如果需要维护层序，那么需要维护到具体的下标吗？还是只要能判断出任意两个结点的大小即可呢？
   插入子树可以等同于插入一个结点
*/
Status ChildTree_insertTree(ChildTree * T, ChildNodeType e, int order, ChildTree t)
{
	if (T->nodeNum == 0 || t.nodeNum == 0) {
		return ERROR;
	}

	// 插入根结点
	ChildTree_insertChild(T, e, t.nodes[0].data, order);

	// 插入孩子结点
	for (int i = 1; i < t.nodeNum; i++) {
		ChildTree_insertChild(T, t.nodes[t.nodes[i].parent].data, t.nodes[i].data, 0);
	}

	return OK;
}

/*
 1. 找到删除的结点下标 delIndex
 2. 从删除结点开始标记要删除的所有结点
 3. 遍历树，通过删除标记删除给结点孩子链表的值并修正剩余的值
 4. 根据删除标记校正位置
 5. 遍历树，根据各结点的孩子链表修正双亲
 6. 修正树的大小
*/
Status ChildTree_deleteTree(ChildTree * T, ChildNodeType e, int order)
{
	int root = ChildTree_order(*T, e);
	if (root < 0) {
		return ERROR;
	}

	ChildNode * rootPtr = &(T->nodes[root]);
	if (!rootPtr->fristChild) {
		return ERROR;
	}

	int delIndex;
	if (!GetElem(rootPtr->fristChild, order, &delIndex)) {
		return ERROR;
	}

	if (delIndex <= 0 || delIndex >= T->nodeNum) {
		return ERROR;
	}
	// 从删除结点开始标记要删除的所有结点
	const int delFlag = -2;
	DuLinkList delList, clist1, clist2;
	InitList(&delList);
	ChildNode * delPtr = &(T->nodes[delIndex]);
	ElemType e1, e2, e3;
	do {
		delPtr->data = delFlag;
		clist1 = delPtr->fristChild;
		if (clist1) {
			for (int i = 1; i <= ListLength(clist1); i++) {
				GetElem(clist1, i, &e1);
				T->nodes[e1].data = delFlag;
				clist2 = T->nodes[e1].fristChild;

				if (clist2) {
					for (int j = 1; j <= ListLength(clist2); j++) {
						GetElem(clist2, j, &e2);
						ListInsert(&delList, 1, e2);
					}
				}
			}
		}

		if (!ListDelete(&delList, 1, &e3)) {
			free(delList);
			break;
		}
		else {
			delPtr = &(T->nodes[e3]);
		}
	} while (1);

	// 遍历树，通过删除标记删除给结点孩子链表的值并修正剩余的值
	int delNum = 0;
	for (int i = 0; i < T->nodeNum; i++) {
		DuLinkList list = T->nodes[i].fristChild;
		if (!list) {
			continue;
		}
		int len = ListLength(list);
		if (T->nodes[i].data == delFlag) {
			delNum = delNum + len;
			ClearList(&list);
			free(list);
		}
		else
		{
			Node * node = list->next->next; // 第一个有效的值
			for (int j = 1; j <= len; j++) {
				int cIndex = node->data;
				if (T->nodes[cIndex].data == delFlag) {
					ListDelete(&list, j, NULL);
					if (ListEmpty(list)) {
						free(list);
						T->nodes[i].fristChild = NULL;
					}
					delNum++;
				}
				else {
					node->data = node->data - delNum;
				}
				node = node->next;
			}
		}
	}
	DG(1);
	printf("%d,%d,", T->nodes[2].data, T->nodes[2].parent);
	int count = ListLength(T->nodes[2].fristChild);
	DG(count);
	Node * c = T->nodes[2].fristChild;
	while (count--) {
		printf("%c ", c->data);
		c = c->next;
	}
	DG(2);
	//ChildTree_print(*T);
	// 根据删除标记校正位置
	int offset = 0; // 偏移量
	for (int i = 0; i < T->nodeNum; i++) {
		int exchange = i + offset;
		while (exchange != T->nodeNum - 1 && T->nodes[exchange].data == delFlag) {
			offset += 1;
			exchange++;
		}
		if (offset > 0) {
			T->nodes[i].data = T->nodes[exchange].data;
			T->nodes[i].fristChild = T->nodes[exchange].fristChild;
			T->nodes[exchange].fristChild = NULL;
		}
		if (exchange == T->nodeNum - 1) {
			break;
		}
	}

	//遍历树，根据各结点的孩子链表修正双亲
	T->nodeNum = T->nodeNum - offset;
	for (int i = 0; i < T->nodeNum; i++) {
		DuLinkList list = T->nodes[i].fristChild;
		if (list) {
			Node * fNode = list->next->next;
			for (int j = 0; j < ListLength(list); j++) {
				T->nodes[fNode->data].parent = i;
				fNode = fNode->next;
			}
		}
	}
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

Bool ChildTree_isTheSame(ChildTree T, ChildTree t)
{
	if (T.nodeNum == t.nodeNum) {
		int i, j;
		for (i = 0, j = 0; i < T.nodeNum; i++, j++) {
			ChildNode n1 = T.nodes[i];
			ChildNode n2 = t.nodes[j];

			if (n1.data != n2.data) {
				fprintf(stdout, "[data][T:%c] neq [t:%c]\n", n1.data, n2.data);
				return FALSE;
			}

			if (n1.parent != n2.parent) {
				fprintf(stdout, "[parent][T:%d] neq [t:%d]\n", n1.parent, n2.parent);
				return FALSE;
			}

			if (!List_isTheSame(n1.fristChild, n2.fristChild)) {
				fprintf(stdout, "[fristChild][T] neq [t]\n");
				return FALSE;
			}
		}
		return TRUE;
	}
	fprintf(stdout, "[nodeNum][T] neq [t]\n");
	return FALSE;
}
