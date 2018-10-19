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
  ? �����֤ ClearList() ������ȷʵ������free(),�������ÿ���ڵ���ڴ��ͷ���
  ? ָ���Զ�������ڴ��ָ�뾭��free()֮����Ұָ�룬ָ���ܿ��Ƶ��ڴ��,��ָ��ǰ���ֵ�ǲ����
  ? ָ������ΪNull��Ҳ�����ã����Ҳ������Ϊ�ж����ݣ���Ϊ�����ж������ͬʱ����ͬһ��ָ���ַ��
  ? Ŀǰ�뵽��ֻ�м�¼ָ��ķ������жϣ����������ü�����ÿ���Զ������ڴ�ʱ����һ��ָ�뷵�أ����ͷ�Ҳ��Ҫ��ͬ��ָ��
  ? ����һ��һ���Ĺ�ϵ����ôҪôHook malloc()�ȷ����ڴ�ĺ���������ָ��ֵ��Hook free()�������Ƴ�ָ��ֵ��
  ? ��֤��ÿһ��ָ���ֵ���ڴ�����ͷ�һһ��Ӧ�����������жϺ��������Ƿ���ȷ�ˡ�
  ? ���һ������ô��ÿ��list��ʼ��ʱ��Ҫ�ֶ������ڴ棬��Ӧ��list����ʹ��ʱҲҪ�����ֶ��ͷ��ڴ档

  1. �ǿ��б����:����Ϊ0��ռ�ÿռ��ͷ�
  2. ���б����: OK
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
  1. 1,2,3��������1,2,3
  2. 0,4 ���� 0
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
  list:1��2��3��4��5
  1. ɾ��ĩβֵ5
  2. ɾ����λֵ1
  3. ɾ���м�ֵ3
  4. ȫɾ2,4
  5. �ٽ�״̬: 0,-1,�����б��ȣ����б�
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
  1. ��λȡ
  2. ĩβ��4��ȡĩ��λ��3��4
  3. ��λ��5ȡǰ��λ��5��1
  4. �м�3λ��ֵ6��2��3��4λΪ 1��6��2
  5. ĩβɾ��ĩ��λ:2,3
  6. ��λɾ��ǰ��λ:1,6
  7. ɾ�м�3λ��1��2��3λΪ:1,6,3
  8. ����ֵ���: �ձ�0��-1��������
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
  1. ��ʼ��ʱΪ��
  2. ���һ����Ϊ��
  3. ɾ��һ��Ϊ��
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
  1. ��λ��1��2������1,2
  2. �м�λ��2����3��:1,3,2
  3. �Ƿ�λ��:0,-1,���б���2����λ��
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
