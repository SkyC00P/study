#include "ThreadBinaryTree.h"
#include "test.h"

static void test();
void PrintElem(TBData e);

static TBTree T1, T2, T3;
static TBTree t1, t2, t3;

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
		fseek(fp, 0, SEEK_SET);
		EXPECT_EQ_INT(OK, TBTree_create(fp, &t3));
		fclose(fp);
	}
	else {
		EXPECT_TRUE(0);
	}

	EXPECT_EQ_INT(OK, TBTree_preorder_Threading(&T1, t1));
}

void PrintElem(TBData e) {
	printf("%c ", e);
}