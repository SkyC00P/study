#include "test.h"
#include "BinaryTree.h"

static BiTree tree;
static void test();
static void Error();

int main() {
	test();
	TEST_REPORT;
}
static void Error() {
	fprintf(stderr, "IO ERROR");
	exit(-1);
}
static void test() {
	puts("(1)初始化测试"); 
	{
		FILE * fp = fopen("binary_tree/test_data/pre_order.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, BiTree_create(fp, &tree));
			EXPECT_TRUE(tree != NULL);
			EXPECT_EQ_INT(4, BiTree_depth(tree));
			BiTree_print(tree);
			fclose(fp);
		}
		else {
			Error();
		}

	}

}