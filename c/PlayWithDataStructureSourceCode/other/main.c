#include <stdio.h>
#include "SqList.c"

void test_get_elem();

void test_list_insert();

void test_list_del();

int main(void) {
//    test_get_elem();
//    test_list_insert();
    test_list_del();
    return 0;
}

void test_get_elem() {
    SqList list;
    ElemType elemType;

    list.data[0] = 2;
    list.length = 1;

    Status status = GetElem(list, 1, &elemType);

    printf("status is %d and elemType is %d", status, elemType);
}

void test_list_insert() {
    SqList list;
    list.length = 0;

    for (int i = 1; i < 5; ++i) {
        Status status = ListInsert(&list, i, i);
        if (status != OK) {
            printf("ListInsert test don't pass...\n");
            return;
        }
    }

    for (int j = 1; j < 5; ++j) {
        ElemType e;
        Status status = GetElem(list, j, &e);
        printf("after insert. [%d] Get %d elemType from list is %d\n", status, j, e);
    }

    printf("test is end...");
}

void test_list_del() {
    SqList list;
    list.length = 5;
    for (int i = 0; i < 5; ++i) {
        list.data[i] = i;
    }

    ElemType delElem;
    Status status = ListDelete(&list, 1, &delElem);
    printf("[%d]del frist elem is %d, and length is %d\n", status, delElem, list.length);

    status = ListDelete(&list, list.length, &delElem);
    printf("[%d]del end elem is %d, and length is %d\n", status, delElem, list.length);

    status = ListDelete(&list, 2, &delElem);
    printf("[%d]del 2 elem must be 2, so return del elem is %d,and length is %d\n", status, delElem, list.length);
}