#include "test.h"
#include "sqstack.c"
#include "link_stack.c"

static void test_stack();
static void test_link_stack();

static void test() {
	test_stack();
	test_link_stack();
}

int main() {
	test();
	TEST_REPORT;
}

static void test_stack(){
	Sqstack stack = NULL;
	Status status = InitStack(&stack);
	EXPECT_EQ_INT(OK, status);

}

static void test_link_stack() {
	LinkStack stack = NULL;
	Status status = InitStack(&stack);
	EXPECT_EQ_INT(OK, status);
}
