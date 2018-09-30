#include "test.h"
#include "sqlist.h"

static void test_initlist();
static void test_list_insert();
static void test_get_elem();
static void test_del_elem();
static void test_locate_elem();
static void test_list_empty();
static void test_clear_list();
static void test_list_length();

static void test() {
	test_initlist();
	test_list_insert();
	test_get_elem();
	test_del_elem();
	test_locate_elem();
	test_list_empty();
	test_clear_list();
	test_list_length();
}

int main(void) {
	test();
	TEST_REPORT;
}

/*
  ?:如何判断sqlist是否已经初始化完成
  ?:定义Sqlist时已经发生内存分配，但是初始值不定，所以需要手动初始化，这个只能人为控制。
  ?:那么已经初始化完成的sqlist也可以重复调用Initlist方法，没有手段防止，这个也只能人为控制。

  1. 测试返回值，测试初始化的值是否OK。
*/
static void test_initlist() {
	SqList list;
	Status status = InitList(&list);
	EXPECT_EQ_INT(OK, status);
	EXPECT_EQ_INT(0, list.length);
	for (int i = 0; i < MAXSIZE; i++) {
		EXPECT_EQ_INT(0, list.data[i]);
	}
}

/*
  1. 临界插入检测:首位插入和末位插入
  2. 无效位置插入:超当前长度位置至少2位插入，负数和零值
  3. 无可用位置插入，链表已满
  4. 重复位置插入
  5. 初始化后任意位置插入
*/
static void test_list_insert() {
	SqList list;
	InitList(&list);

	EXPECT_EQ_INT(ERROR, ListInsert(&list, 2, 2));
	EXPECT_EQ_INT(OK, ListInsert(&list, 1, 2));
	EXPECT_EQ_INT(1, list.length);
	EXPECT_EQ_INT(2, list.data[0]);

	int len = list.length;
	EXPECT_EQ_INT(OK, ListInsert(&list, len, len));
	EXPECT_EQ_INT(2, list.length);
	EXPECT_EQ_INT(len, list.data[len - 1]);
	EXPECT_EQ_INT(2, list.data[len]);

	EXPECT_EQ_INT(ERROR, ListInsert(&list, 0, -1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, -1, -2));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, MAXSIZE, MAXSIZE));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, MAXSIZE + 1, MAXSIZE + 1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, list.length + 2, list.length + 2));

	SqList list2;
	InitList(&list2);
	ListInsert(&list2, 1, 1);
	ListInsert(&list2, 1, 2);
	EXPECT_EQ_INT(2, list2.data[0]);
	EXPECT_EQ_INT(1, list2.data[1]);
	ListInsert(&list2, 2, 3);
	EXPECT_EQ_INT(2, list2.data[0]);
	EXPECT_EQ_INT(3, list2.data[1]);
	EXPECT_EQ_INT(1, list2.data[2]);

	SqList list3;
	InitList(&list3);
	for (int i = 0; i < MAXSIZE; i++) {
		ListInsert(&list3, 1, 1);
	}
	EXPECT_EQ_INT(ERROR, ListInsert(&list3, 1, 1));
}

/*
  1. 返回值正确
  2. 无效位置取值: 零，负数， 超出length
*/
static void test_get_elem() {
	SqList list;
	InitList(&list);
	ElemType e;
	EXPECT_EQ_INT(ERROR, GetElem(list, 1, &e));

	ListInsert(&list, 1, 2);
	EXPECT_EQ_INT(OK, GetElem(list, 1, &e));
	EXPECT_EQ_INT(2, e);

	ListInsert(&list, 1, 3);
	EXPECT_EQ_INT(OK, GetElem(list, 1, &e));
	EXPECT_EQ_INT(3, e);
	EXPECT_EQ_INT(OK, GetElem(list, 2, &e));
	EXPECT_EQ_INT(2, e);

	EXPECT_EQ_INT(ERROR, GetElem(list, 0, &e));
	EXPECT_EQ_INT(ERROR, GetElem(list, -1, &e));
	EXPECT_EQ_INT(ERROR, GetElem(list, list.length + 1, &e));
}

/*
  1. 空列表删除
  2. 无效位置检测: 负数，零，超过Length的值
  3. 头位删除，末位删除，中间值删除
*/
static void test_del_elem() {
	SqList list;
	InitList(&list);
	ElemType e;
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 1, &e));

	// 初始化 1,2,3,4,5的列表
	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);
	ListInsert(&list, 4, 4);
	ListInsert(&list, 5, 5);

	EXPECT_EQ_INT(ERROR, ListDelete(&list, 0, &e));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, -1, &e));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 6, &e));

	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &e));
	EXPECT_EQ_INT(1, e);
	EXPECT_EQ_INT(2, list.data[0]);
	EXPECT_EQ_INT(3, list.data[1]);
	EXPECT_EQ_INT(4, list.data[2]);
	EXPECT_EQ_INT(5, list.data[3]);
	EXPECT_EQ_INT(4, list.length);

	EXPECT_EQ_INT(OK, ListDelete(&list, 4, &e));
	EXPECT_EQ_INT(5, e);
	EXPECT_EQ_INT(2, list.data[0]);
	EXPECT_EQ_INT(3, list.data[1]);
	EXPECT_EQ_INT(4, list.data[2]);
	EXPECT_EQ_INT(3, list.length);

	EXPECT_EQ_INT(OK, ListDelete(&list, 2, &e));
	EXPECT_EQ_INT(3, e);
	EXPECT_EQ_INT(2, list.data[0]);
	EXPECT_EQ_INT(4, list.data[1]);
	EXPECT_EQ_INT(2, list.length);
}

/*
  1. 空列表检测
  2. 值存在
  3. 值不存在
*/
static void test_locate_elem() {
	SqList list;
	InitList(&list);
	EXPECT_EQ_INT(0, LocateElem(list, 0));

	for (int i = 1; i <= 3; i++){
		ListInsert(&list, i, i);
	}

	EXPECT_EQ_INT(1, LocateElem(list, 1));
	EXPECT_EQ_INT(2, LocateElem(list, 2));
	EXPECT_EQ_INT(3, LocateElem(list, 3));
	EXPECT_EQ_INT(0, LocateElem(list, 4));
}

static void test_list_empty(){
	SqList list;
	InitList(&list);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));

	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(FALSE, ListEmpty(list));
	ElemType e;
	ListDelete(&list, 1, &e);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));
}

static void test_clear_list(){
	SqList list;
	InitList(&list);
	EXPECT_EQ_INT(OK, ClearList(&list));
	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(OK, ClearList(&list));
	EXPECT_EQ_INT(0, list.length);
	EXPECT_EQ_INT(0, list.data[0]);
}

static void test_list_length(){
	SqList list;
	InitList(&list);
	EXPECT_EQ_INT(0, ListLength(list));
	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(1, ListLength(list));
	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(2, ListLength(list));
	ElemType E;
	ListDelete(&list, 1, &E);
	EXPECT_EQ_INT(1, ListLength(list));
	ClearList(&list);
	EXPECT_EQ_INT(0, ListLength(list));
}
