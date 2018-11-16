#include "test.h"
#include "lstring.h"
#include <string.h>

static void test();
extern void printPtrNum();
extern int resetPtrNum();
extern void printAllChar(String str);

int main(void) {
	test();
	TEST_REPORT;
}

void test() {
	puts("(1) 初始化字符串测试");

	char * t1 = "";
	char * t2 = "初始化字符串测试:Hello World";
	char * t3 = "~!@#$%^&*()_+|''\\<>?\"\":;\n";

	String s1 = String_new(t1);
	String s2 = String_new(t2);
	String s3 = String_new(t3);

	int len1 = strlen(t1);
	int len2 = strlen(t2);
	int len3 = strlen(t3);

	printf("[char *] --------------------\n");
	printf("len:%d, str:%s\n", len1, t1);
	printf("len:%d, str:%s\n", len2, t2);
	printf("len:%d, str:%s\n", len3, t3);

	printf("[String] --------------------\n");
	printAllChar(s1);
	printAllChar(s2);
	printAllChar(s3);

	char * p1 = String_toString(s1);
	char * p2 = String_toString(s2);
	char * p3 = String_toString(s3);

	EXPECT_EQ_INT(0, strcmp(t1, p1));
	EXPECT_EQ_INT(0, strcmp(t2, p2));
	EXPECT_EQ_INT(0, strcmp(t3, p3));

	EXPECT_EQ_INT(len1, s1->len);
	EXPECT_EQ_INT(len2, s2->len);
	EXPECT_EQ_INT(len3, s3->len);

	EXPECT_EQ_INT(len1, String_length(s1));
	EXPECT_EQ_INT(len2, String_length(s2));
	EXPECT_EQ_INT(len3, String_length(s3));

	EXPECT_TRUE(String_isEmpty(s1));
	EXPECT_FALSE(String_isEmpty(s2));
	EXPECT_FALSE(String_isEmpty(s3));

	printPtrNum();
	int String_new_space = (len1 + len2 + len3 + 3) * sizeof(StrNode) + 3 * sizeof(struct String);
	int String_toString_space = (len1 + len2 + len3 + 3) * sizeof(char);
	EXPECT_EQ_INT(String_new_space + String_toString_space, resetPtrNum());
	
}