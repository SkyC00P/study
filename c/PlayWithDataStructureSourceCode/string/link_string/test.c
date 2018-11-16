#include "test.h"
#include "lstring.h"
#include <string.h>

static void test_init();

static void test();
extern void printPtrNum();
extern int resetPtrNum();
extern void printAllChar(String str);

int main(void) {
	test();
	TEST_REPORT;
}

void test() {
	//test_init();

	puts("(2) 字符串拷贝测试");

	char * t1 = "";
	char * t2 = "abc";

	String s1 = String_new(t1);
	String s2 = String_new(t2);

	printf("测试拷贝s1的副本s,s1为空字符串\n");
	String s = String_copy(s1);
	puts("拷贝得到的副本s:");
	printAllChar(s);

	puts("检查副本s的长度和内容与原来一样");
	EXPECT_TRUE(s);
	EXPECT_EQ_INT(0, s->len);
	EXPECT_TRUE(String_isEmpty(s));
	EXPECT_EQ_INT(0, String_length(s));
	EXPECT_EQ_INT(0, strcmp(String_toString(s), t1));

	puts("检查是否是深拷贝，修改s1的值，看是否会影响副本s的内容。插入s2到s1");
	String_insert(s1, 1, s2);
	printAllChar(s1);
	EXPECT_EQ_INT(0, strcmp(String_toString(s), t1));
	EXPECT_TRUE(s != s1);
	EXPECT_TRUE(strcmp(String_toString(s1), t1) != 0);

	printf("测试拷贝s2的副本c,s2为abc\n");
	String c = String_copy(s2);
	puts("拷贝得到的副本c:");
	printAllChar(c);

	puts("检查副本s的长度和内容与原来一样");
	EXPECT_TRUE(c);
	EXPECT_EQ_INT(3, c->len);
	EXPECT_FALSE(String_isEmpty(c));
	EXPECT_EQ_INT(3, String_length(c));

	puts("检查是否是深拷贝，修改s2的值，看是否会影响副本c的内容。插入s1到s2");
	String_insert(s2, 1, s1);
	printAllChar(s2);
	EXPECT_EQ_INT(0, strcmp(String_toString(c), t2));
	EXPECT_TRUE(c != s2);
	EXPECT_TRUE(strcmp(String_toString(s2), t2) != 0);

	printf("\n");
}

void test_init()
{
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
	printf("\n");
}
