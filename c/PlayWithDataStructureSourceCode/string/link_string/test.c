#include "test.h"
#include "lstring.h"
#include <string.h>
//#define DEBUG
#ifdef DEBUG
#define PSIZEOF(x) printf("malloc_space is %d\n", x)
#else
#define PSIZEOF(x) 
#endif // DEBUG
static void test_init();
static int getSpace(int node, int string);
static void test();
void test_copy();
extern void printPtrNum();
extern void resetPtrNum();
extern int getPtrNum();
extern void printAllChar(String str);

int main(void) {
	printf("sizeof struct string:%ld,sizeof StrNode:%ld\n", sizeof(struct String), sizeof(StrNode));
	test();
	TEST_REPORT;
}

void test() {
	test_init();
	test_copy();
}

void test_copy()
{
	puts("(2) 字符串拷贝测试");
	unsigned int malloc_space = 0;

	char * t1 = "";
	char * t2 = "abc";

	String s1 = String_new(t1);
	String s2 = String_new(t2);
	// 实例化分配的空间 
	unsigned int space_new = getSpace(5, 2);
	malloc_space += space_new;
	PSIZEOF(malloc_space);

	printf("测试拷贝s1的副本s,s1为空字符串\n");
	String s = String_copy(s1);
	malloc_space += getSpace(1, 1);
	PSIZEOF(malloc_space);
	puts("拷贝得到的副本s:");
	printAllChar(s);

	puts("检查副本s的长度和内容与原来一样");
	EXPECT_TRUE(s);
	EXPECT_EQ_INT(0, s->len);
	EXPECT_TRUE(String_isEmpty(s));
	EXPECT_EQ_INT(0, String_length(s));
	char * toString = String_toString(s);
	EXPECT_EQ_INT(0, strcmp(toString, t1));
	malloc_space += sizeof(char) * (strlen(toString) + 1);
	PSIZEOF(malloc_space);

	puts("检查是否是深拷贝，修改s1的值，看是否会影响副本s的内容。插入s2到s1");
	String_insert(s1, 1, s2);
	malloc_space += String_length(s2) * sizeof(StrNode);
	PSIZEOF(malloc_space);
	// s2 插入到 s1变成abc\n
	printAllChar(s1);
	toString = String_toString(s);
	EXPECT_EQ_INT(0, strcmp(toString, t1));
	malloc_space += sizeof(char) * (strlen(toString) + 1);

	EXPECT_TRUE(s != s1);
	toString = String_toString(s1);
	EXPECT_TRUE(strcmp(toString, t1) != 0);
	malloc_space += sizeof(char) * (strlen(toString) + 1);
	PSIZEOF(malloc_space);

	printf("测试拷贝s2的副本c,s2为abc\n");
	String c = String_copy(s2);
	malloc_space += getSpace(String_length(c) + 1, 1);
	PSIZEOF(malloc_space);
	puts("拷贝得到的副本c:");
	printAllChar(c);

	puts("检查副本s的长度和内容与原来一样");
	EXPECT_TRUE(c);
	EXPECT_EQ_INT(3, c->len);
	EXPECT_FALSE(String_isEmpty(c));
	EXPECT_EQ_INT(3, String_length(c));

	toString = String_toString(c);
	EXPECT_EQ_INT(0, strcmp(toString, t2));
	malloc_space += sizeof(char) * (strlen(toString) + 1);
	PSIZEOF(malloc_space);

	puts("检查是否是深拷贝，修改s2的值，看是否会影响副本c的内容。插入s1到s2");
	String_insert(s2, 1, s1);
	malloc_space += String_length(s1) * sizeof(StrNode);
	PSIZEOF(malloc_space);
	printAllChar(s2);
	toString = String_toString(c);
	EXPECT_EQ_INT(0, strcmp(toString, t2));
	malloc_space += sizeof(char) * (strlen(toString) + 1);
	PSIZEOF(malloc_space);
	EXPECT_TRUE(c != s2);
	toString = String_toString(s2);
	EXPECT_TRUE(strcmp(toString, t2) != 0);
	malloc_space += sizeof(char) * (strlen(toString) + 1);
	PSIZEOF(malloc_space);

	// 检查当前测试使用的堆内存未释放的为预期值
	EXPECT_EQ_INT(malloc_space, getPtrNum());
	resetPtrNum();
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
	EXPECT_EQ_INT(String_new_space + String_toString_space, getPtrNum());
	resetPtrNum();
	printf("\n");
}

int getSpace(int charNode, int string)
{
	return charNode * sizeof(StrNode) + string * sizeof(struct String);
}
