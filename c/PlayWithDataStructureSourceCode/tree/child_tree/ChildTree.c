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
	//fprintf(stderr, "[findIndex] : err\n");
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

Status ChildTree_clear(ChildTree * T)
{
	return OK;
}

Bool ChildTree_isEmpty(ChildTree T)
{
	return TRUE;
}

int ChildTree_degree(ChildTree T)
{
	return 0;
}

int ChildTree_depth(ChildTree T)
{
	return 0;
}

ChildNodeType ChildTree_root(ChildTree T)
{
	return '\0';
}

ChildNodeType ChildTree_vaule(ChildTree T, int order)
{
	return '\0';
}

int ChildTree_order(ChildTree T, ChildNodeType data)
{
	return 0;
}

Status ChildTree_assign(ChildTree T, ChildNodeType old, ChildNodeType new)
{
	return OK;
}

ChildNodeType ChildTree_findChild(ChildTree T, ChildNodeType e, int order)
{
	return '\0';
}

ChildNodeType ChildTree_findBrother(ChildTree T, ChildNodeType e, int order)
{
	return '\0';
}

int ChildTree_getChildCount(ChildTree T, ChildNodeType e)
{
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

void ChildTree_levelOrderTraverse(ChildTree T, void(Visit)(ChildNodeType))
{
}

void ChildTree_print(ChildTree T)
{
	printf("size is %d\n", T.nodeNum);
	printf("| %2s | %4s | %6s | child\n", "i", "data", "parent");
	if (T.nodeNum) {
		for (int i = 0; i < T.nodeNum; i++) {
			ChildNode node = T.nodes[i];
			printf("| %2d | %4c | %6d | ", i, node.data, node.parent);
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
