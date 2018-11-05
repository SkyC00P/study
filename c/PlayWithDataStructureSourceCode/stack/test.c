#include "test.h"
#include "stack.h"
#include <stdio.h>

static void test() {

	int e = 0;
	Stack_T s = NULL;
	EXPECT_EQ_INT(OK, InitStack(&s));
	EXPECT_EQ_INT(ERROR, Push(NULL, &e));

	for (int j = 1; j <= 10; j++) {
		EXPECT_EQ_INT(OK, Push(s, &j));
	}
#ifdef SQ_STACK
	EXPECT_EQ_INT(ERROR, Push(s, &e));
#endif // SQ_STACK

//	printf("Õ»ÖÐÔªËØÒÀ´ÎÎª£º");
//	StackTraverse(s);
//
//	EXPECT_EQ_INT(OK, Pop(s, &e));
//	EXPECT_EQ_INT(10, e);
//	printf("µ¯³öµÄÕ»¶¥ÔªËØ e=%d\n", e);
//
//	EXPECT_EQ_INT(OK, Pop(s, &e));
//	EXPECT_EQ_INT(9, e);
//
//	printf("Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackEmpty(s));
//	EXPECT_FALSE(StackEmpty(s));
//
//	EXPECT_EQ_INT(OK, GetTop(s, &e));
//	EXPECT_EQ_INT(8, e);
//	EXPECT_EQ_INT(8, StackLength(s));
//	printf("Õ»¶¥ÔªËØ e=%d Õ»µÄ³¤¶ÈÎª%d\n", e, StackLength(s));
//
//	EXPECT_EQ_INT(OK, ClearStack(s));
//	EXPECT_TRUE(StackEmpty(s));
//	EXPECT_EQ_INT(ERROR, GetTop(s, &e));
//	EXPECT_EQ_INT(ERROR, Pop(s));
//	printf("Çå¿ÕÕ»ºó£¬Õ»¿Õ·ñ£º%d(1:¿Õ 0:·ñ)\n", StackEmpty(s));
//
//	EXPECT_TRUE(OK, DestroyStack(s));
//	EXPECT_FALSE(ERROR, DestroyStack(NULL));
}

int main() {
	test();
	TEST_REPORT;
}

