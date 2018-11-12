#include "test.h"
#include "queue.h"
#include <stdio.h>

static void test() {
	Queue q = NULL;
	puts("(1)��ʼ���ն���");
	EXPECT_EQ_INT(OK, InitQueue(&q));
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", QueueLength(q));

	puts("(2)���β������:-5,5,10");
	EnQueue(q, -5);
	EnQueue(q, 5);
	EnQueue(q, 10);
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(q);
	EXPECT_EQ_INT(3, QueueLength(q));
	EXPECT_EQ_INT(FALSE, QueueEmpty(q));
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));

	int d = 0;
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(-5, d);
	printf("��ͷԪ���ǣ�%d\n", d);

	puts("(3)����-5");
	EXPECT_EQ_INT(OK, DeQueue(q, &d));
	printf("ɾ���˶�ͷԪ��%d\n", d);
	EXPECT_EQ_INT(OK, GetHead(q, &d));
	EXPECT_EQ_INT(5, d);
	printf("�µĶ�ͷԪ���ǣ�%d\n", d);

	puts("(4)��ն���");
	ClearQueue(q);
	EXPECT_EQ_INT(TRUE, QueueEmpty(q));
	EXPECT_EQ_INT(0, QueueLength(q));
	EXPECT_EQ_INT(ERROR, DeQueue(q, &d));
	EXPECT_EQ_INT(ERROR, GetHead(q, &d));

	puts("(5)���ٶ���");
	DestroyQueue(q);
	DestroyQueue(NULL);
	printf("���ٶ��к�,q.front=%u q.rear=%u\n", q.front, q.rear);
}

int main() {
	test();
	TEST_REPORT;
}