#include "ChildBrotherTree.h"
#include "test.h"

static CBTree tree;
static void test();
static void printNodeData(CBData);
int main() {
	test();
	TEST_REPORT;
}
static void Error() {
	fprintf(stderr, "IO ERROR");
	exit(-1);
}
static void test() {
	puts("(1) 初始化测试"); {
		EXPECT_EQ_INT(OK, CBTree_init(&tree));
		EXPECT_TRUE(CBTree_isEmpty(tree));
		puts(" --> 从文件中读取并初始化");
		FILE * fp = fopen("child_brother_tree/TestData.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, CBTree_create(fp, &tree));
			fclose(fp);

			CBTree_print(tree);
			EXPECT_EQ_INT(3, CBTree_degree(tree));
			EXPECT_EQ_INT(4, CBTree_depth(tree));

			CBTree_level_order_traverse(tree, printNodeData);
			printf("\n");
			CBTree_preorder_traverse(tree, printNodeData);
			printf("\n");
			CBTree_inorder_traverse(tree, printNodeData);
			printf("\n");
			CBTree_postorder_traverse(tree, printNodeData);
			printf("\n");
		}
		else {
			Error();
		}

		CBTree t;
		FILE * fpTmp = fopen("child_brother_tree/TestData_1.txt", "r");
		if (fpTmp) {
			EXPECT_EQ_INT(OK, CBTree_create(fpTmp, &t));
			fclose(fpTmp);

			CBTree_print(t);
			CBTree_preorder_traverse(t, printNodeData);
			printf("\n");
			CBTree_inorder_traverse(t, printNodeData);
			printf("\n");
			CBTree_postorder_traverse(t, printNodeData);
			printf("\n");
		}
		else {
			Error();
		}
	}
}

static void printNodeData(CBData data) {
	printf("%c ", data);
}