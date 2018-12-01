#include "test.h"
#include "ChildTree.h"
#include <stdlib.h>

static ChildTree tree;
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
		}
		else
		{
			fprintf(stderr, "IO ERROR");
			exit(-1);
		}
	}

}