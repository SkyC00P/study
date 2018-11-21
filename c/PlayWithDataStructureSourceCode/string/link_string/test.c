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
void test_replace();
void test_indexof();
void test_insert();
void test_delete();
void test_substring();
void test_clear();
void test_concat();
void test_compare();
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
	// test_init();
	// test_copy();
	//test_compare();

	//test_concat();
	//test_clear();

	//test_substring();

	test_delete();
	// test_insert();
	// test_indexof();
	// test_replace();
}

void test_replace()
{
	puts("(10)字符替换测试"); printf("\n");
}

void test_indexof()
{
	puts("(9)字符匹配搜索测试"); printf("\n");
}

void test_insert()
{
	puts("(8)字符插入测试");
	printf("\n");
}

/*
 1. 入参检测
 2. 空字符串测试
 3. 删掉首字符
 4. 删掉末尾字符
 5. 删除指定位置后的所有字符
 6. 删除指定位置后的部分字符

 测试要点
  1. 返回字符串长度和内容符合预期
  2. 内存释放符合预期
  3. 返回的字符串指针与源字符串相同
*/
void test_delete()
{
	puts("(7)字符串删除子串测试");
	String s1 = String_new("abcdefg");
	String s2 = String_new("");

	char * tostring;
	int malloc_space;

	String str;
	malloc_space = getPtrNum();
	str = String_subString(s1, 0, 1);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s1, 8, 1);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s1, 1, 0);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s2, 1, 1);
	EXPECT_TRUE(str == NULL);
	EXPECT_EQ_INT(0, malloc_space - getPtrNum());

	malloc_space = getPtrNum();
	str = String_delete(s1, 1, 1);
	EXPECT_EQ_INT(malloc_space - getSpace(1, 0), getPtrNum());
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "bcdefg"));
	EXPECT_EQ_INT(6, String_length(str));
	EXPECT_TRUE(str == s1);
	str->head->ch = 'A';
	EXPECT_EQ_INT(0, String_compare(str, s1));
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "Acdefg"));
	printAllChar(s1);

	malloc_space = getPtrNum();
	str = String_delete(s1, String_length(s1), 1);
	printAllChar(s1);
	EXPECT_EQ_INT(malloc_space - getSpace(1, 0), getPtrNum());
	tostring = String_toString(str);
	printAllChar(s1);
	// EXPECT_EQ_INT(0, strcmp(tostring, "Acdef"));
	// EXPECT_EQ_INT(5, String_length(str));

	printf("\n");
}

/*
 1. 入参检测
 2. 空字符截断
 3. 非空字符串截断
	3.1 完整截断
	3.2 不完整截断
	3.3 截取首字符
	3.4 截取末尾字符
 测试要点：
  1 截取字符长度和内容符合预期，
  2 内存分配符合预期，
  3 截取的新字符串与被截取的字符串相互独立
*/
void test_substring()
{
	puts("(6)字符串截取测试");
	String s1 = String_new("abcdefg");
	String s2 = String_new("");

	String str;
	resetPtrNum();
	str = String_subString(s1, 0, 1);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s1, 8, 1);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s1, 1, 0);
	EXPECT_TRUE(str == NULL);
	str = String_subString(s2, 1, 1);
	EXPECT_TRUE(str == NULL);
	EXPECT_EQ_INT(0, getPtrNum());

	char * tostring;

	resetPtrNum();
	str = String_subString(s1, 1, 1);
	EXPECT_EQ_INT(getSpace(2, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("a", tostring));
	EXPECT_EQ_INT(1, String_length(str));
	str->head->ch = 'b';
	tostring = String_toString(s1);
	EXPECT_EQ_INT(0, strcmp(tostring, "abcdefg"));

	resetPtrNum();
	str = String_subString(s1, 1, 2);
	EXPECT_EQ_INT(getSpace(3, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("ab", tostring));
	EXPECT_EQ_INT(2, String_length(str));

	resetPtrNum();
	str = String_subString(s1, 6, 2);
	EXPECT_EQ_INT(getSpace(3, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("fg", tostring));
	EXPECT_EQ_INT(2, String_length(str));

	resetPtrNum();
	str = String_subString(s1, 1, 100);
	EXPECT_EQ_INT(getSpace(8, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("abcdefg", tostring));
	EXPECT_EQ_INT(7, String_length(str));

	resetPtrNum();
	str = String_subString(s1, 2, 100);
	EXPECT_EQ_INT(getSpace(7, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("bcdefg", tostring));
	EXPECT_EQ_INT(6, String_length(str));

	resetPtrNum();
	str = String_subString(s1, 2, String_length(s1));
	EXPECT_EQ_INT(getSpace(7, 1), getPtrNum());
	printAllChar(str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp("bcdefg", tostring));
	EXPECT_EQ_INT(6, String_length(str));

	printf("\n");
}

/*
 1. 空字符串清理
 2. 非空字符串清理

 测试要点: 输出空字符串，内存释放
*/
void test_clear()
{
	puts("(5)字符串清空操作");
	char * tostring;

	resetPtrNum();
	String s1 = String_new("");
	String_clear(s1);
	EXPECT_EQ_INT(getSpace(1, 1), getPtrNum());
	EXPECT_EQ_INT(0, String_length(s1));
	EXPECT_TRUE(String_isEmpty(s1));
	tostring = String_toString(s1);
	EXPECT_EQ_INT(0, strcmp("", tostring));

	resetPtrNum();
	String s2 = String_new("abc");
	String_clear(s2);
	EXPECT_EQ_INT(getSpace(1, 1), getPtrNum());
	EXPECT_EQ_INT(0, String_length(s1));
	EXPECT_TRUE(String_isEmpty(s1));
	tostring = String_toString(s1);
	EXPECT_EQ_INT(0, strcmp("", tostring));

	printf("\n");
}

/*
 1. 空字符串自连接
 2. 非空字符串自连接
 3. 连接返回的是新字符串
 4. 空字符串和非空字符串相连
 5. 两个非空字符串的相连

 测试要点：1. 连接长度 2. 连接内容 3.新字符串内存空间归属于大小
*/
void test_concat()
{
	puts("(4)字符串连接测试");
	String str;
	char *tostring;
	unsigned int malloc_space = 0;
	String s1 = String_new("");

	resetPtrNum();
	str = String_concat(s1, s1);
	malloc_space = getSpace(1, 1);
	EXPECT_EQ_INT(malloc_space, getPtrNum());
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, ""));
	EXPECT_EQ_INT(0, String_length(str));

	String s2 = String_new("abc");
	resetPtrNum();
	str = String_concat(s2, s2);
	malloc_space = getSpace(7, 1);
	EXPECT_EQ_INT(malloc_space, getPtrNum());
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "abcabc"));
	EXPECT_EQ_INT(6, String_length(str));

	String s3 = String_new("ab");
	String s4 = String_new("");
	resetPtrNum();
	str = String_concat(s3, s4);
	malloc_space = getSpace(3, 1);
	EXPECT_EQ_INT(malloc_space, getPtrNum());
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "ab"));
	EXPECT_EQ_INT(2, String_length(str));

	String s5 = String_new("edfh");
	String s6 = String_new("ijkl");
	resetPtrNum();
	str = String_concat(s5, s6);
	malloc_space = getSpace(9, 1);
	EXPECT_EQ_INT(malloc_space, getPtrNum());
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "edfhijkl"));
	EXPECT_EQ_INT(8, String_length(str));

	s5->head->ch = 'a';
	s6->head->ch = 'b';
	printAllChar(s5);
	printAllChar(s6);
	EXPECT_TRUE(s5 != str);
	EXPECT_TRUE(s6 != str);
	tostring = String_toString(str);
	EXPECT_EQ_INT(0, strcmp(tostring, "edfhijkl"));
	EXPECT_EQ_INT(8, String_length(str));
	resetPtrNum();
	printf("\n");
}

void test_compare()
{
	puts("(3) 字符串对比测试");
	char * t1 = "";
	char * t2 = "abc";
	char * t3 = "abc";
	char * t4 = "abcd";
	char * t5 = "aba";
	char * t6 = "abe";
	char * t7 = "def";
	char * t8 = "feg";

	String s1 = String_new(t1);
	String s2 = String_new(t2);
	String s3 = String_new(t3);
	String s4 = String_new(t4);
	String s5 = String_new(t5);
	String s6 = String_new(t6);
	String s7 = String_new(t7);
	String s8 = String_new(t8);

	// 相等测试
	EXPECT_EQ_INT(0, String_compare(s1, s1));
	EXPECT_EQ_INT(0, String_compare(s2, s2));
	EXPECT_EQ_INT(0, String_compare(s2, s3));
	EXPECT_EQ_INT(0, String_compare(s3, s2));

	// 相同序列不等长度测试
	EXPECT_TRUE(String_compare(s3, s4) < 0);
	EXPECT_TRUE(String_compare(s4, s3) > 0);

	// 同等长度字符序列对比
	EXPECT_TRUE(String_compare(s2, s5) > 0);
	EXPECT_TRUE(String_compare(s2, s6) < 0);
	EXPECT_TRUE(String_compare(s7, s2) > 0);
	EXPECT_TRUE(String_compare(s7, s8) < 0);

	// 不等长度不等字符序列优先级测试
	EXPECT_TRUE(String_compare(s4, s8) < 0);
	printf("\n");
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
