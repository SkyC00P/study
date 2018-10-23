#include "test.h"
#include "loop_link_list.h"

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
	LoopLinkList list;
	EXPECT_EQ_INT(OK, InitList(&list));
	EXPECT_TRUE(list->next == list);
}

static void test_list_empty() {
	LoopLinkList list;
	InitList(&list);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));

	/*ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(FALSE, ListEmpty(list));

	ElemType e;
	ListDelete(&list, 1, &e);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));*/
}

static void test_list_insert() {

}

static void test_list_del() {

}

static void test_list_get() {

}

static void test_clear_list() {

}

static void test_locate_elem() {

}