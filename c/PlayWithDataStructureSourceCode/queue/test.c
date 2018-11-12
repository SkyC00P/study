#include "test.h"
#include "queue.h"
#include <stdio.h>

static void test() {
	Queue q = NULL;
	puts("(1)初始化空队列");
	EXPECT_EQ_INT(OK, InitQueue(&q));
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));

	puts("(2)依次插入队列:-5,5,10");
	EnQueue(q, -5);
	EnQueue(q, 5);
	EnQueue(q, 10);
	printf("队列的元素依次为：");
	QueueTraverse(q);
	EXPECT_EQ_INT(3, QueueLength(q));
	EXPECT_EQ_INT(FALSE, QueueEmpty(q));
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ", QueueEmpty(q));

	int d = 0;
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(-5, d);
	printf("队头元素是：%d\n", d);

	puts("(3)出队-5");
	EXPECT_EQ_INT(OK, DeQueue(q, &d));
	printf("删除了队头元素%d\n", d);
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(5, d);
	printf("新的队头元素是：%d\n", d);

	puts("(4)清空队列");
	ClearQueue(q);
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	EXPECT_EQ_INT(ERROR, DeQueue(q, &d));
	EXPECT_EQ_INT(ERROR, GetHead(q, &d));

	puts("(5)销毁队列");
	DestroyQueue(q);
	DestroyQueue(NULL);
	printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);
}

int main() {
	test();
	TEST_REPORT;
}