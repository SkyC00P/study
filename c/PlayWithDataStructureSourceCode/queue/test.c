#include "test.h"
#include "queue.h"
#include <stdio.h>

static void test() {
	Queue q = NULL;
	puts("(1)初始化空队列");
	EXPECT_EQ_INT(OK, InitQueue(&q));
	EXPECT_EQ_INT(ERROR, InitQueue(&q));
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));

	puts("(2)入队测试");
	EXPECT_EQ_INT(OK,EnQueue(q, -5));
	EXPECT_EQ_INT(OK,EnQueue(q, 5));
	EXPECT_EQ_INT(OK,EnQueue(q, 10));
	printf("队列的元素依次为：");
	QueueTraverse(q);
	EXPECT_EQ_INT(3, QueueLength(q));
	EXPECT_EQ_INT(FALSE, QueueEmpty(q));
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));

#ifdef SQ_QUEUE
	printf("继续入队列从1到6\n");
	for (int i = 1; i <= 6; i++) {
		EXPECT_EQ_INT(OK, EnQueue(q, i));
	}
	EXPECT_EQ_INT(ERROR, EnQueue(q, 7));

	EXPECT_EQ_INT(9, QueueLength(q));
	EXPECT_EQ_INT(FALSE, QueueEmpty(q));
	QueueTraverse(q);
#endif // SQ_QUEUE

	int d = 0;
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(-5, d);
	printf("队头元素是：%d\n", d);

	puts("(3)出队测试");
	EXPECT_EQ_INT(ERROR, DeQueue(NULL, &d));
	EXPECT_EQ_INT(OK, DeQueue(q, &d));
	EXPECT_EQ_INT(-5, d);
	printf("删除了队头元素%d\n", d);
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(5, d);
	printf("新的队头元素是：%d\n", d);
	printf("连续出队列2次\n");
	EXPECT_EQ_INT(OK, DeQueue(q, &d));
	EXPECT_EQ_INT(5, d);
	EXPECT_EQ_INT(OK, DeQueue(q, &d));
	EXPECT_EQ_INT(10, d);

	puts("(4)清空队列");
	printf("从队列里在追加1,2后清除\n");
	EXPECT_EQ_INT(OK, EnQueue(q, 1));
	EXPECT_EQ_INT(OK, EnQueue(q, 2));
	EXPECT_EQ_INT(OK,ClearQueue(q));
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	EXPECT_EQ_INT(ERROR, DeQueue(q, &d));
	EXPECT_EQ_INT(ERROR, GetHead(q, &d));
	EXPECT_EQ_INT(OK, ClearQueue(q));

	puts("(5)销毁队列");
	EXPECT_EQ_INT(OK, DestroyQueue(q));
	EXPECT_EQ_INT(ERROR, DestroyQueue(NULL));
	printf("\n");
}

int main() {
	test();
	TEST_REPORT;
}