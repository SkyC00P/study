#define  MAXSIZE 5

#include "static_linklist.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
#define EXPECT_NOT_EQ_INT(num1, num2) EXPECT_EQ_BASE((num1) != (num2), num1, num2, "%d")

#define PRINT(msg) printf("%s:%d: %s \n", __FILE__, __LINE__, msg);
#define PRLIST(list) \
    printf("%s:%d: StaticLinkList[index, cur]:",__FILE__, __LINE__);\
    for(int i=0; i<MAXSIZE; i++){\
        printf("[%d,%d]", i,list[i].cur);\
    }\
    printf("\n");

#define PR_DATA(list, n, len) \
    printf("%s:%d: StaticLinkList[length:%d][index,cur,data]:",__FILE__, __LINE__,len);\
    for(int i=1; i<=n; i++){\
        printf("[%d,%d,%d]", i,list[i].cur, list[i].data);\
    }\
    printf("\n");

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
    PRLIST(list);
    for (int i = 1; i < MAXSIZE; ++i) {
        int i1 = Malloc_SLL(list);
        EXPECT_EQ_INT(i, i1);
    }

    int last = Malloc_SLL(list);
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
    Status status = ListInsert(list, 1, 1);
    EXPECT_EQ_INT(OK, status);
    EXPECT_EQ_INT(1, list[1].data);
    EXPECT_EQ_INT(1, ListLength(list));

    EXPECT_EQ_INT(OK, ListInsert(list, 2, 2));
    EXPECT_EQ_INT(2, list[2].data);
    EXPECT_EQ_INT(2, ListLength(list));

    EXPECT_EQ_INT(OK, ListInsert(list, 3, 3));
    EXPECT_EQ_INT(3, list[3].data);
    EXPECT_EQ_INT(3, ListLength(list));

    PRLIST(list);
    EXPECT_EQ_INT(ERROR, ListInsert(list, 4, 4));
    PR_DATA(list, 4, ListLength(list));

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
    PR_DATA(list, MAXSIZE - 2, ListLength(list));
    printf("the head cur:%d\n", list[MAXSIZE-1].cur);
    printf("the 0 index cur:%d\n", list[0].cur);

    int index;
    ElemType e;
    for (int del = MAXSIZE - 2; del > 0; del--) {
        index = list[0].cur;
        Status status = ListDelete(list, 1, &e);
        EXPECT_EQ_INT(OK, status);
        EXPECT_EQ_INT(del, e);
        EXPECT_EQ_INT(del - 1, ListLength(list));
        EXPECT_NOT_EQ_INT(index, list[0].cur);
    }

}

static void test() {
    test_init();
    test_malloc_sll();
    test_list_length();
    test_list_insert();
    test_list_delete();
}

int main() {
    test();
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return main_ret;
}