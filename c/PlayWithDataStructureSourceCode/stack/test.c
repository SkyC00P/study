#include "test.h"
#include "stack.h"
#include <stdio.h>

static void test() {

	int e = 0;
	Stack_T s = NULL;
	printf("(1)初始化栈\n");
	EXPECT_EQ_INT(OK, InitStack(&s));
	EXPECT_EQ_INT(ERROR, Push(NULL, e));

	printf("\n");
	printf("(2)依次添加1到10到栈中，栈顶为10，栈尾为1\n");
	for (int j = 1; j <= 10; j++) {
		EXPECT_EQ_INT(OK, Push(s, j));
	}
#ifdef SQ_STACK
	EXPECT_EQ_INT(ERROR, Push(s, 11));
#endif // SQ_STACK

	printf("\n");
	printf("(3)栈中元素依次为：");
	StackTraverse(s);

	printf("\n");
	printf("(4)出栈2次\n");
	EXPECT_EQ_INT(OK, Pop(s, &e));
	EXPECT_EQ_INT(10, e);
	printf("弹出的栈顶元素 e=%d\n", e);

	EXPECT_EQ_INT(OK, Pop(s, &e));
	EXPECT_EQ_INT(9, e);
	printf("弹出的栈顶元素 e=%d\n", e);
	
	printf("\n");
	printf("(4)验证栈是否为空\n");
	EXPECT_FALSE(StackEmpty(s));
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	printf("\n");
	printf("(5)获得栈顶元素\n");
	EXPECT_EQ_INT(OK, GetTop(s, &e));
	EXPECT_EQ_INT(8, e);
	EXPECT_EQ_INT(8, StackLength(s));
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));

	printf("\n(6)清除栈...\n");
	EXPECT_EQ_INT(OK, ClearStack(s));
	EXPECT_TRUE(StackEmpty(s));
	EXPECT_EQ_INT(ERROR, GetTop(s, &e));
	EXPECT_EQ_INT(ERROR, Pop(s, &e));
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	
	printf("\n(7)销毁栈...\n");
	EXPECT_EQ_INT(OK, DestroyStack(s));
	EXPECT_EQ_INT(ERROR, DestroyStack(NULL));
	printf("\n");
}

int main() {
	test();
	TEST_REPORT;
}

