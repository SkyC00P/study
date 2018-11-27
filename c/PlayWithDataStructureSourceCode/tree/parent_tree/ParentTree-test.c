#include "ParentTree.h"
#include "test.h"

void test();

int main() {
	test();
	TEST_REPORT;
}

void test() {
	PTree tree;
	puts("(1) 初始化测试");
	{
		EXPECT_EQ_INT(OK, ParentTree_init(&tree));
	}
	puts("");
}