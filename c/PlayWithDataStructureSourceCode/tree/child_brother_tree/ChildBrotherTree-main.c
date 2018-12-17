#include "ChildBrotherTree.h"
#include "test.h"

static CBTree tree;
static void test();

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
		}
		else {
			Error();
		}
	}
}