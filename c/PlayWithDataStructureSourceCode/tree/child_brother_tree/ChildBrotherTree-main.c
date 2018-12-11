#include "ChildBrotherTree.h"
#include "test.h"

static CBTree tree;
static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1) 初始化测试"); {
		EXPECT_EQ_INT(OK, CBTree_init(&tree));
	}
}