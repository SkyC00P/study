#include "test.h"
#include "BinaryTree.h"

static BiTree tree;
static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1)��ʼ������"); {
		tree = BiTree_init();
		EXPECT_TRUE(tree != NULL);
	}

}