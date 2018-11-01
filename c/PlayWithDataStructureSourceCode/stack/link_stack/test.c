#include "test.h"
#include "link_stack.h"

int main() {
	LinkStack stack;
	EXPECT_EQ_INT(1, init(&stack));
	TEST_REPORT;
}