#include "HuffmanTree.h"
#include "help/OrderLinkList.h"
#include "test.h"

static void test();
static HuffmanTree tree;
static int _compare(void * v1, void * v2);

int main() {
	test();
	TEST_REPORT;
}

static void test() {

	OrderLinkList list = OrderLinkList_init(_compare);
	unsigned int weight[] = { 5, 29, 7, 8, 14, 23, 3, 11 };

	for (int i = 0; i < 8; i++) {
		HTNodePtr ptr = malloc(sizeof(HTNode));
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		ptr->parent = NULL;
		ptr->weight = weight[i];
		OrderLinkList_add(list, ptr);
	}
	EXPECT_EQ_INT(8, OrderLinkList_size(list));

	unsigned int sored_weight[] = { 3,5,7,8,11,14,23,29 };
	for (int i = 0; i < 8; i++) {
		HTNodePtr ptr = OrderLinkList_remove_frist(list);
		EXPECT_EQ_INT(sored_weight[i], ptr->weight);
	}

	puts("初始化赫尔曼树");
	FILE * fp = fopen("huffman_tree/test_data.txt", "r");
	if (fp) {
		tree = HuffmanTree_create(fp);
		EXPECT_TRUE(tree != NULL);
		fclose(fp);
	}
	else {
		Exit_with_msg("IO Error\n");
	}

	puts("展示赫尔曼树:5, 29, 7, 8, 14, 23, 3, 11 ");
	HuffmanTree_show(tree);

	int arr[] = { 5,15,40,30,10 };
	tree = HuffmanTree_create_inarray(arr, 5);
	puts("展示赫尔曼树:5,15,40,30,10");
	HuffmanTree_show(tree);
}

static int _compare(void * v1, void * v2) {
	CheckPtr(v1);
	CheckPtr(v2);

	HTNodePtr p1 = v1;
	HTNodePtr p2 = v2;

	return p1->weight - p2->weight;
}