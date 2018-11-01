#include "test.h"
#include "SqStack.h"

int main() {
	SqStack stack;
	init(&stack);
	EXPECT_EQ_INT(-1, stack.data);
	TEST_REPORT;
}