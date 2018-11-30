#include "test.h"
#include "ChildTree.h"

static ChildTree tree;
static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	FILE * fp = fopen("child_tree/TestData_T.txt", "r");
	if (fp) {
		EXPECT_EQ_INT(OK, ChildTree_init(&tree,fp));
	}
}