#include "test.h"
#include "static_link_list.h"

static void test_init();
static void test_malloc_sll();
static void test_list_length();
static void test_list_insert();
static void test_list_delete();

static void test() {
	test_init();
	test_malloc_sll();
	test_list_length();
	test_list_insert();
	test_list_delete();
}

static void test_in_book() {
	StaticLinkList L;
	InitList(L);
	printf("初始化L后：L.length=%d\n", ListLength(L));

	ListInsert(L, 1, 'F');
	ListInsert(L, 1, 'E');
	ListInsert(L, 1, 'D');
	ListInsert(L, 1, 'B');
	ListInsert(L, 1, 'A');

	printf("\n在L的表头依次插入FEDBA后：\nL.data=");
	ListTraverse(L);

	ListInsert(L, 3, 'C');
	printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
	ListTraverse(L);

	ListDelete(L, 1);
	printf("\n在L的删除“A”后：\nL.data=");
	ListTraverse(L);

	printf("\n");
}

int main() {
	test_in_book();
	test();
	TEST_REPORT;
}

static void test_init() {
	StaticLinkList list;
	Status status = InitList(list);
	EXPECT_EQ_INT(OK, status);
	EXPECT_EQ_INT(1, list[0].cur);
	EXPECT_EQ_INT(2, list[1].cur);
	EXPECT_EQ_INT(list[MAXSIZE - 2].cur, MAXSIZE - 1);
	EXPECT_EQ_INT(list[MAXSIZE - 1].cur, 0);
}

static void test_malloc_sll() {
	StaticLinkList list;
	InitList(list);
	
	for (int i = 1; i < MAXSIZE; ++i) {
		int i1 = Malloc_SSL(list);
		EXPECT_EQ_INT(i, i1);
	}

	int last = Malloc_SSL(list);
	EXPECT_EQ_INT(0, last);
}

static void test_list_length() {
	StaticLinkList list;
	InitList(list);
	int length = ListLength(list);
	EXPECT_EQ_INT(0, length);

	list[0].cur = 2;
	list[1].cur = 0;
	list[1].data = 1;
	list[MAXSIZE - 1].cur = 1;
	EXPECT_EQ_INT(1, ListLength(list));

}

static void test_list_insert() {
	StaticLinkList list;
	InitList(list);

	for (int i = 1; i < MAXSIZE-1; i++){
		EXPECT_EQ_INT(OK, ListInsert(list, i, i));
		EXPECT_EQ_INT(i, list[i].data);
		EXPECT_EQ_INT(i, ListLength(list));
	}
#ifndef DEBUG
	// 书上的代码无法通过这个测试，静态链表的可供存放的位置只有MAXSIZE - 2个
	EXPECT_EQ_INT(ERROR, ListInsert(list, MAXSIZE-1, 4));
#endif // !DEBUG

	StaticLinkList list1;
	InitList(list1);
	EXPECT_EQ_INT(OK, ListInsert(list1, 1, 1));
	EXPECT_EQ_INT(OK, ListInsert(list1, 1, 2));
	EXPECT_EQ_INT(2, list1[2].data);
	EXPECT_EQ_INT(0, list1[1].cur);
	EXPECT_EQ_INT(2, ListLength(list1));
	EXPECT_EQ_INT(3, list1[0].cur);
	EXPECT_EQ_INT(2, list1[MAXSIZE - 1].cur);
}

static void test_list_delete() {
	StaticLinkList list;
	InitList(list);
	for (int i = 1; i <= MAXSIZE - 2; i++) {
		ListInsert(list, 1, i);
	}
	printf("the head cur:%d\n", list[MAXSIZE - 1].cur);
	printf("the 0 index cur:%d\n", list[0].cur);

	int index;
	for (int del = MAXSIZE - 2; del > 0; del--) {
		index = list[0].cur;
		Status status = ListDelete(list, 1);
		EXPECT_EQ_INT(OK, status);
		EXPECT_EQ_INT(del - 1, ListLength(list));
		EXPECT_NOT_EQ_INT(index, list[0].cur);
	}

}