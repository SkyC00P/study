#include "test.h"
#include "double_link_list.h"

static void test_init_list();
static void test_list_empty();
static void test_list_insert();
static void test_list_del();
static void test_list_get();
static void test_clear_list();
static void test_locate_elem();

static void test() {
	test_init_list();
	test_list_empty();
	test_list_insert();
	test_list_del();
	test_list_get();
	test_clear_list();
	test_locate_elem();
}

int main() {
	test();
	TEST_REPORT;
}

static void test_init_list() {
	DuLinkList list;
	EXPECT_EQ_INT(OK, InitList(&list));
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prior == list);
}

static void test_list_empty() {
	DuLinkList list;
	InitList(&list);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));

	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(FALSE, ListEmpty(list));
	
	ElemType e;
	ListDelete(&list, 1, &e);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));
}

static void test_list_insert() {
	DuLinkList list;
	InitList(&list);
	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(1, list->data);
	EXPECT_EQ_INT(1, list->prior->prior->data);
	EXPECT_EQ_INT(1, list->next->next->data);
	EXPECT_TRUE(list->next->next == list);
	EXPECT_EQ_INT(1, ListLength(list));

	EXPECT_EQ_INT(OK, ListInsert(&list, 2, 2));
	Node * n1 = list->next->next; // 1
	Node * n2 = n1->next;         // 2
	EXPECT_EQ_INT(2, ListLength(list));
	EXPECT_EQ_INT(1, n1->data);
	EXPECT_EQ_INT(2, n2->data);
	EXPECT_TRUE(n2 == list);
	EXPECT_EQ_INT(2, list->data);
	EXPECT_EQ_INT(1, list->prior->data);
	
	EXPECT_EQ_INT(OK, ListInsert(&list, 2, 3));
	n1 = list->next->next;
	n2 = n1->next;
	Node * n3 = n2->next;
	EXPECT_EQ_INT(3, ListLength(list));
	EXPECT_EQ_INT(1, n1->data);
	EXPECT_EQ_INT(3, n2->data);
	EXPECT_EQ_INT(2, n3->data);
	EXPECT_TRUE(n3 == list);
	EXPECT_EQ_INT(3, list->prior->data);
	
	EXPECT_EQ_INT(ERROR, ListInsert(&list, 0, 1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, -1, 1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, ListLength(list) + 2, 1));
}

static void test_list_del() {
	DuLinkList list;
	InitList(&list);
	// list is 1,2,3,4,5
	for (int i = 1; i <= 5; i++) {
		ListInsert(&list, i, i);
	}

	ElemType delElem;
	// 1,2,3,4
	EXPECT_EQ_INT(OK, ListDelete(&list, 5, &delElem));
	EXPECT_EQ_INT(5, delElem);
	EXPECT_EQ_INT(4, ListLength(list));
	EXPECT_EQ_INT(4, list->data);
	EXPECT_EQ_INT(3, list->prior->data);
	EXPECT_EQ_INT(1, list->next->next->data);

	// 2,3,4
	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(1, delElem);
	EXPECT_EQ_INT(3, ListLength(list));
	EXPECT_EQ_INT(4, list->data);
	EXPECT_EQ_INT(3, list->prior->data);
	EXPECT_EQ_INT(2, list->next->next->data);

	// 2,4
	EXPECT_EQ_INT(OK, ListDelete(&list, 2, &delElem));
	EXPECT_EQ_INT(3, delElem);
	EXPECT_EQ_INT(2, ListLength(list));
	EXPECT_EQ_INT(4, list->data);
	EXPECT_EQ_INT(2, list->prior->data);
	EXPECT_EQ_INT(2, list->next->next->data);

	// 4
	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(2, delElem);
	EXPECT_EQ_INT(1, ListLength(list));
	EXPECT_EQ_INT(4, list->data);
	EXPECT_EQ_INT(4, list->prior->prior->data);
	EXPECT_EQ_INT(4, list->next->next->data);

	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(4, delElem);
	EXPECT_EQ_INT(0, ListLength(list));
	EXPECT_EQ_INT(TRUE, ListEmpty(list));
	EXPECT_TRUE(list->next == list->prior);

	EXPECT_EQ_INT(ERROR, ListDelete(&list, 0, &delElem));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, -1, &delElem));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 1, &delElem));

	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 2, &delElem));
}

static void test_list_get() {
	DuLinkList list;
	InitList(&list);
	for (int i = 1; i < 4; i++) {
		ListInsert(&list, i, i);
	}

	// 1,2,3
	ElemType get;
	for (int i = 1; i < 4; i++) {
		EXPECT_EQ_INT(OK, GetElem(list, i, &get));
		EXPECT_EQ_INT(i, get);
	}

	ListInsert(&list, 4, 4);
	EXPECT_EQ_INT(OK, GetElem(list, 4, &get));
	EXPECT_EQ_INT(4, get);
	EXPECT_EQ_INT(OK, GetElem(list, 3, &get));
	EXPECT_EQ_INT(3, get);

	ListInsert(&list, 1, 5);
	EXPECT_EQ_INT(OK, GetElem(list, 1, &get));
	EXPECT_EQ_INT(5, get);
	EXPECT_EQ_INT(OK, GetElem(list, 2, &get));
	EXPECT_EQ_INT(1, get);

	ListInsert(&list, 3, 6);
	EXPECT_EQ_INT(OK, GetElem(list, 2, &get));
	EXPECT_EQ_INT(1, get);
	EXPECT_EQ_INT(OK, GetElem(list, 3, &get));
	EXPECT_EQ_INT(6, get);
	EXPECT_EQ_INT(OK, GetElem(list, 4, &get));
	EXPECT_EQ_INT(2, get);

	ElemType del;
	ListDelete(&list, 6, &del);
	EXPECT_EQ_INT(OK, GetElem(list, ListLength(list), &get));
	EXPECT_EQ_INT(3, get);
	EXPECT_EQ_INT(OK, GetElem(list, ListLength(list) - 1, &get));
	EXPECT_EQ_INT(2, get);

	ListDelete(&list, 1, &del);
	EXPECT_EQ_INT(OK, GetElem(list, 1, &get));
	EXPECT_EQ_INT(1, get);
	EXPECT_EQ_INT(OK, GetElem(list, 2, &get));
	EXPECT_EQ_INT(6, get);

	ListDelete(&list, 3, &del);
	EXPECT_EQ_INT(OK, GetElem(list, 1, &get));
	EXPECT_EQ_INT(1, get);
	EXPECT_EQ_INT(OK, GetElem(list, 2, &get));
	EXPECT_EQ_INT(6, get);
	EXPECT_EQ_INT(OK, GetElem(list, 3, &get));
	EXPECT_EQ_INT(3, get);

	EXPECT_EQ_INT(ERROR, GetElem(list, 0, &get));
	EXPECT_EQ_INT(ERROR, GetElem(list, -1, &get));
	EXPECT_EQ_INT(ERROR, GetElem(list, 4, &get));

	DuLinkList empty;
	InitList(&empty);
	EXPECT_EQ_INT(ERROR, GetElem(empty, 1, &get));
}

static void test_clear_list() {
	DuLinkList list;
	InitList(&list);
	printf("expect clear node num is 0,and actual ");
	EXPECT_EQ_INT(OK, ClearList(&list));

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	printf("expect clear node num is 2,and actual ");
	DuLinkList bPtr = list;
	EXPECT_EQ_INT(OK, ClearList(&list));
	DuLinkList afPtr = list;
	EXPECT_FALSE(bPtr == afPtr);
	EXPECT_EQ_INT(0, ListLength(list));
	EXPECT_TRUE(list->next == list->prior && list == list->prior);
	printf("\n");
}

static void test_locate_elem() {
	DuLinkList list;
	InitList(&list);
	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);

	EXPECT_EQ_INT(1, LocateElem(list, 1));
	EXPECT_EQ_INT(2, LocateElem(list, 2));
	EXPECT_EQ_INT(3, LocateElem(list, 3));

	EXPECT_EQ_INT(0, LocateElem(list, 0));
	EXPECT_EQ_INT(0, LocateElem(list, 4));
}