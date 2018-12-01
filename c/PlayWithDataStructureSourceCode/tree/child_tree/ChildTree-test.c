#include "test.h"
#include "ChildTree.h"
#include <stdlib.h>

static ChildTree tree;
static ChildTree subtree;

static void showChar(ChildNodeType e);
static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1) 初始化测试");
	{
		FILE * fp = fopen("child_tree/TestData_T.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, ChildTree_init(&tree, fp));
			fclose(fp);
			ChildTree_print(tree);
			ChildTree_levelOrderTraverse(tree, showChar);
			EXPECT_EQ_INT(3, ChildTree_degree(tree));
			EXPECT_EQ_INT(5, ChildTree_depth(tree));
			EXPECT_EQ_INT('R', ChildTree_root(tree));
		}
		else
		{
			fprintf(stderr, "IO ERROR");
			exit(-1);
		}

		fp = fopen("child_tree/TestData_T0.txt","r");
		if (fp) {
			EXPECT_EQ_INT(OK, ChildTree_init(&subtree, fp));
			fclose(fp);
			ChildTree_print(subtree);
			ChildTree_levelOrderTraverse(subtree, showChar);
			EXPECT_EQ_INT(3, ChildTree_degree(subtree));
			EXPECT_EQ_INT(3, ChildTree_depth(subtree));
			EXPECT_EQ_INT('0', ChildTree_root(subtree));
		}
		else
		{
			fprintf(stderr, "IO ERROR");
			exit(-1);
		}
	}

}

static void showChar(ChildNodeType e) {
	printf("%c ", e);
}