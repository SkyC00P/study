#include "test.h"
#include "stack.h"
#include <stdio.h>

static void test() {

	int e = 0;
	Stack_T s = NULL;
	EXPECT_EQ_INT(OK, InitStack(&s));
	EXPECT_EQ_INT(ERROR, Push(NULL, e));

	for (int j = 1; j <= 10; j++) {
		EXPECT_EQ_INT(OK, Push(s, j));
	}
#ifdef SQ_STACK
	EXPECT_EQ_INT(ERROR, Push(s, 11));
#endif // SQ_STACK

	printf("栈中元素依次为：");
	StackTraverse(s);

	EXPECT_EQ_INT(OK, Pop(s, &e));
	EXPECT_EQ_INT(10, e);
	printf("弹出的栈顶元素 e=%d", e);

	EXPECT_EQ_INT(OK, Pop(s, &e));
	EXPECT_EQ_INT(9, e);
	printf(",%d\n", e);

	EXPECT_FALSE(StackEmpty(s));
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	EXPECT_EQ_INT(OK, GetTop(s, &e));
	EXPECT_EQ_INT(8, e);
	EXPECT_EQ_INT(8, StackLength(s));
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));

	printf("清除栈...");
	EXPECT_EQ_INT(OK, ClearStack(s));
	EXPECT_TRUE(StackEmpty(s));
	EXPECT_EQ_INT(ERROR, GetTop(s, &e));
	EXPECT_EQ_INT(ERROR, Pop(s, &e));
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	EXPECT_EQ_INT(OK, DestroyStack(s));
	EXPECT_EQ_INT(ERROR, DestroyStack(NULL));
}

int main() {
	test();
	TEST_REPORT;
}

