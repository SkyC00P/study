#include "test.h"
#include "link_list.h"
#include <stdlib.h>

static void test_init_list();
static void test_list_empty();
static void test_list_insert();
static void test_list_del();
static void test_list_get();
static void test_clear_list();
static void test_locate_elem();
static void test_list_traverse();
static void test_create_list_head();
static void test_create_list_tail();

static void test() {
	test_init_list();
	test_list_empty();
	test_list_insert();
	test_list_del();
	test_list_get();
	test_clear_list();
	test_locate_elem();
	test_list_traverse();
	test_create_list_head();
	test_create_list_tail();
}


int main() {
	test();
	TEST_REPORT;
}

static void test_init_list() {
	LinkList list;
	EXPECT_EQ_INT(OK, InitList(&list));
	EXPECT_TRUE(list->next == NULL);
}

/*
  ? 如何验证 ClearList() 方法里确实调用了free(),将链表的每个节点的内存释放了
  ? 指向自动分配的内存的指针经过free()之后变成野指针，指向不受控制的内存块,但指针前后的值是不变的
  ? 指针设置为Null，也不经用，这个也不能作为判断依据，因为可以有多个变量同时保存同一份指针地址。
  ? 目前想到的只有记录指针的方法来判断，类似于引用计数。每当自动分配内存时都有一个指针返回，而释放也需要相同的指针
  ? 这有一加一减的关系，那么要么Hook malloc()等分配内存的函数来保存指针值，Hook free()函数来移除指针值，
  ? 保证对每一个指针的值跟内存分配释放一一对应。这样就能判断函数功能是否正确了。
  ? 如此一来，那么在每个list初始化时需要手动分配内存，相应的list不再使用时也要进行手动释放内存。

  1. 非空列表清除:长度为0，占用空间释放
  2. 空列表清除: OK
*/
static void test_clear_list() {
	LinkList list;
	InitList(&list);
	EXPECT_EQ_INT(OK,ClearList(&list));

	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	EXPECT_EQ_INT(OK, ClearList(&list));
	EXPECT_EQ_INT(0, ListLength(list));
	EXPECT_TRUE(list->next == NULL);
}

/*
  list:1,2,3
  1. 1,2,3正常返回1,2,3
  2. 0,4 返回 0
*/
static void test_locate_elem(){
	LinkList list;
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

void test_list_traverse(){
	LinkList list;
	InitList(&list);
	ListInsert(&list, 1, 1);
	ListInsert(&list, 2, 2);
	ListInsert(&list, 3, 3);

	printf("The list has 1,2,3, below will print all num.\n");
	EXPECT_EQ_INT(OK, ListTraverse(list));
	printf("\n");
}

void test_create_list_head(){
	LinkList list;
#ifndef DEBUG
	printf("This impl is from myself,create list has 5 number by head and all data is 0.\n");
#else
	printf("This impl is from book,create list has 5 number by head and all data is ramdom.\n");
#endif // !DEBUG
	CreateListHead(&list, 5);
	ListTraverse(list);
	printf("\n");
}

void test_create_list_tail(){
	LinkList list;
#ifndef DEBUG
	printf("This impl is from myself,create list has 5 number by tail and all data is 0.\n");
#else
	printf("This impl is from book,create list has 5 number by tail and all data is ramdom.\n");
#endif // !DEBUG
	CreateListTail(&list, 5);
	ListTraverse(list);
	printf("\n");
}

/*
  list:1，2，3，4，5
  1. 删除末尾值5
  2. 删除首位值1
  3. 删除中间值3
  4. 全删2,4
  5. 临界状态: 0,-1,超过列表长度，空列表
*/
static void test_list_del() {
	LinkList list;
	InitList(&list);
	for (int i = 1; i <= 5; i++) {
		ListInsert(&list, i, i);
	}

	ElemType delElem;
	EXPECT_EQ_INT(OK, ListDelete(&list, 5, &delElem));
	EXPECT_EQ_INT(5, delElem);
	EXPECT_EQ_INT(4, ListLength(list));

	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(1, delElem);
	EXPECT_EQ_INT(3, ListLength(list));

	EXPECT_EQ_INT(OK, ListDelete(&list, 2, &delElem));
	EXPECT_EQ_INT(3, delElem);
	EXPECT_EQ_INT(2, ListLength(list));

	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(2, delElem);
	EXPECT_EQ_INT(1, ListLength(list));

	EXPECT_EQ_INT(OK, ListDelete(&list, 1, &delElem));
	EXPECT_EQ_INT(4, delElem);
	EXPECT_EQ_INT(0, ListLength(list));

	EXPECT_EQ_INT(ERROR, ListDelete(&list, 0, &delElem));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, -1, &delElem));
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 1, &delElem));

	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(ERROR, ListDelete(&list, 2, &delElem));
}
/*
  list:1,2,3
  1. 逐位取
  2. 末尾加4后取末两位得3，4
  3. 首位加5取前两位得5，1
  4. 中间3位插值6，2，3，4位为 1，6，2
  5. 末尾删得末两位:2,3
  6. 首位删得前两位:1,6
  7. 删中间3位得1，2，3位为:1,6,3
  8. 特殊值检测: 空表，0，-1，超表长度
*/
static void test_list_get() {
	LinkList list;
	InitList(&list);
	for (int i = 1; i < 4; i++) {
		ListInsert(&list, i, i);
	}

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

	LinkList empty;
	InitList(&empty);
	EXPECT_EQ_INT(ERROR, GetElem(empty, 1, &get));
}

/*
  1. 初始化时为空
  2. 添加一个不为空
  3. 删除一个为空
*/
static void test_list_empty() {
	LinkList list;
	InitList(&list);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));

	ListInsert(&list, 1, 1);
	EXPECT_EQ_INT(FALSE, ListEmpty(list));

	ElemType e;
	ListDelete(&list, 1, &e);
	EXPECT_EQ_INT(TRUE, ListEmpty(list));
}

/*
  1. 按位置1，2逐个添加1,2
  2. 中间位置2插入3变:1,3,2
  3. 非法位置:0,-1,超列表长度2个的位置
*/
static void test_list_insert() {
	LinkList list;
	InitList(&list);

	EXPECT_EQ_INT(OK, ListInsert(&list, 1, 1));
	Node * n1 = list->next;
	EXPECT_EQ_INT(1, ListLength(list));
	EXPECT_EQ_INT(1, n1->data);
	EXPECT_TRUE(n1->next == NULL);

	EXPECT_EQ_INT(OK, ListInsert(&list, 2, 2));
	n1 = list->next;
	Node * n2 = n1->next;
	EXPECT_EQ_INT(2, ListLength(list));
	EXPECT_EQ_INT(1, n1->data);
	EXPECT_EQ_INT(2, n2->data);
	EXPECT_TRUE(n2->next == NULL);

	EXPECT_EQ_INT(OK, ListInsert(&list, 2, 3));
	n1 = list->next;
	n2 = n1->next;
	Node * n3 = n2->next;
	EXPECT_EQ_INT(3, ListLength(list));
	EXPECT_EQ_INT(1, n1->data);
	EXPECT_EQ_INT(3, n2->data);
	EXPECT_EQ_INT(2, n3->data);
	EXPECT_TRUE(n3->next == NULL);

	EXPECT_EQ_INT(ERROR, ListInsert(&list, 0, 1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, -1, 1));
	EXPECT_EQ_INT(ERROR, ListInsert(&list, ListLength(list) + 2, 1));
}
