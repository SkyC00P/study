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

static void List_print(DuLinkList list) {
	if (!list) {
		return;
	}
	int len = ListLength(list);
	Node * pNode = list;
	for (int i = 0; i < len; i++) {
		printf("%d ", pNode->data);
		pNode = pNode->prior;
	}
	printf("\n");
}

static Node * List_get(DuLinkList list, int i) {
	if (list) {
		Node * node = list->next; // head point
		int len = ListLength(list);

		if (i > len) {
			fprintf(stderr, "List get is Error i:[%d]\n", i);
			return NULL;
		}

		for (int j = 0; j < len && j < i; j++) {
			node = node->next;
		}
		return node;
	}
	return NULL;
}
/* 1. 确定插入的结点的数据: 
	1. 插入的下标
	2. 结点的双亲的下标 
	3. 孩子链表置空(因为是以叶子结点插入的)
	4. 数据已知
   2. 腾出新的位置，将插入位置下的所有位置下移一位，保持数据不变
   3. 遍历祖父结点到最后的叶节点，修改孩子链表和双亲结点的值
   4. 在腾出的新位置上插入数据
*/
Status ChildTree_insertChild_1(ChildTree * T, ChildNodeType e, ChildNodeType new, int order) {

}

Status ChildTree_insertChild(ChildTree * T, ChildNodeType e, ChildNodeType new, int order) {
	
	return ChildTree_insertChild_1(T, e, new, order);
	// 1. 找到父节点
	int parent = ChildTree_order(*T, e);
	// 2. 在父节点的孩子链表插入值并更新剩下的值
	ChildNode * parentNode = &(T->nodes[parent]);
	if (!parentNode->fristChild) {
		InitList(&(parentNode->fristChild));
	}
	DuLinkList list = parentNode->fristChild;
	int len = ListLength(list);
	int insertIndex;
	if (order == 0 || order > len) {
		ElemType lastIndex;
		if (GetElem(list, len, &lastIndex)) {
			insertIndex = lastIndex + 1;
		}
		else {
			
			// 插入的位置:父节点的左兄弟的最后一个孩子结点的下标
			// 插入的位置:父节点的最右兄弟结点
			DuLinkList uncleList = T->nodes[T->nodes[parent].parent].fristChild;
			int len = ListLength(uncleList);
			int findIt = 0;
			while (len) {
				if (uncleList->data == parent && len - 1 > 0) {
					findIt = 1;
					break;
				}
				uncleList = uncleList->prior;
				len--;
			}
			if (findIt &&  T->nodes[uncleList->prior->data].fristChild) {
				insertIndex = T->nodes[uncleList->prior->data].fristChild->data + 1;
			}
			else {
				insertIndex = uncleList->data + 1;
			}

		}
		ListInsert(&list, ListLength(list) + 1, insertIndex);
		T->nodes[parent].fristChild = list;
	}
	else if (order < 1) {
		fprintf(stderr, "Error:order <1\n");
		return ERROR;
	}
	else
	{
		GetElem(list, order, &insertIndex);
		ListInsert(&list, order, insertIndex);
		// 链表少了个设置相应位置值的方法,只好自己再写个
		Node * n = List_get(list, insertIndex);
		int len = ListLength(list);
		for (int i = insertIndex + 1; i <= len; i++) {
			n->next->data += 1;
			n = n->next;
		}
		T->nodes[parent].fristChild = list;
	}
	// 更新并移动所有剩下所有结点的数据
	for (int i = T->nodeNum; i > insertIndex; i--) {
		int pVaule = T->nodes[i - 1].parent;
		if (pVaule >= insertIndex) {
			T->nodes[i].parent = pVaule + 1;
		}
		else
		{
			T->nodes[i].parent = pVaule;
		}

		DuLinkList list = T->nodes[i - 1].fristChild;
		if (list) {
			Node * head = list->next->next;
			int len = ListLength(list);
			for (int i = 0; i < len; i++) {
				if (head->data >= insertIndex) {
					head->data++;
				}
				head = head->next;
			}
			T->nodes[i].fristChild = list;
		}
		else
		{
			T->nodes[i].fristChild = NULL;
		}
		T->nodes[i].data = T->nodes[i - 1].data;
	}
	// 更新左兄弟的孩子链表
	for (int i = parent + 1; i < insertIndex; i++) {
		DuLinkList list = T->nodes[i].fristChild;
		if (list) {
			Node * head = list->next->next;
			int len = ListLength(list);
			for (int i = 0; i < len; i++) {
				if (head->data >= insertIndex) {
					head->data++;
				}
				head = head->next;
			}
		}
	}
	T->nodes[insertIndex].data = new;
	T->nodes[insertIndex].parent = parent;
	T->nodes[insertIndex].fristChild = NULL;
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

Bool ChildTree_isTheSame(ChildTree T, ChildTree t)
{
	if (T.nodeNum == t.nodeNum) {
		for (int i = 0, j = 0; i < T.nodeNum, j < t.nodeNum; i++, j++) {
			ChildNode n1 = T.nodes[i];
			ChildNode n2 = t.nodes[j];

			if (n1.data != n2.data) {
				return FALSE;
			}

			if (n1.parent != n2.parent) {
				return FALSE;
			}

			if (!List_isTheSame(n1.fristChild, n2.fristChild)) {
				return FALSE;
			}
		}
		return TRUE;
	}
	return FALSE;
}
