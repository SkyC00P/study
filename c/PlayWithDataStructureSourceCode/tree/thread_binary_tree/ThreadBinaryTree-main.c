#include "ThreadBinaryTree.h"
#include "test.h"

static void test();
void PrintElem(TBData e);

static TBTree T1, T2;
static TBTree t1, t2;

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("按先序序列创建二叉树");
	FILE * fp = fopen("thread_binary_tree/test_data.txt", "r");
	if (fp) {
		EXPECT_EQ_INT(OK, TBTree_create(fp, &t1));
		fseek(fp, 0, SEEK_SET);
		EXPECT_EQ_INT(OK, TBTree_create(fp, &t2));
		fclose(fp);
	}
	else {
		EXPECT_TRUE(0);
	}

	puts("1. 测试先序遍历");
	{
		puts("线索化t1树为T1");
		EXPECT_EQ_INT(OK, TBTree_preorder_Threading(&T1, t1));
		puts("先序遍历T1:A B D G E H I C F J");
		EXPECT_EQ_INT(OK, TBTree_preOrder_traverse(T1, PrintElem));

		printf("\n");
	}

	puts("2. 测试中序遍历");
	{
		puts("线索化t2树为T2");
		EXPECT_EQ_INT(OK, TBTree_inorder_Threading(&T2, t2));
		puts("先序遍历T1:G D B H E I A F J C");
		EXPECT_EQ_INT(OK, TBTree_inOrder_traverse(T2, PrintElem));

		printf("\n");
	}

}

void PrintElem(TBData e) {
	printf("%c ", e);
}