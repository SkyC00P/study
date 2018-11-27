#include "ParentTree.h"
#include "test.h"

static PTree tree;

void test();

void test_create_tree();

void test_init();

int main() {
	test();
	TEST_REPORT;
}

void test() {
	//test_init();
	test_create_tree();
}

void test_create_tree()
{
	puts("(2) 按文件的层序序列构造树 测试");
	{
		FILE *fp;
		fp = fopen("parent_tree/TestData_T.txt", "r");
		if (fp) {
			ParentTree_create(fp, &tree);
			fclose(fp);
		}
		
	}
	puts("");
}

void test_init()
{
	puts("(1) 初始化测试");
	{
		EXPECT_EQ_INT(OK, ParentTree_init(&tree));
		EXPECT_EQ_INT(0, tree.n);
		EXPECT_EQ_INT(TRUE, ParentTree_isEmpty(tree));
	}
	puts("");
}
