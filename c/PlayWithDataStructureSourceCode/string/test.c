#include "test.h"
#include "string.h"
#include <string.h>

static char showCompareStatus(int status);
static void test() {

	String s1;
	String empty;
	puts("(1) 初始化字符串s1为abcd");
	EXPECT_EQ_INT(OK, StrAssign(s1, "abcd"));
	EXPECT_EQ_INT(OK, StrAssign(empty, ""));
	StrPrint(s1);
	EXPECT_EQ_INT(4, StrLength(s1));
	EXPECT_EQ_INT(FALSE, StringEmpty(s1));
	printf("串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StringEmpty(s1));

#ifdef BOOK
	String tooLongStr;
	EXPECT_EQ_INT(ERROR, StrAssign(tooLongStr, "1234567890 1234567890 1234567890 1234567890 1234567890"));
#endif // BOOK

	puts("(2) 将字符串s1拷贝到s2,s2为未初始化的字符串");
	String s2;
	EXPECT_EQ_INT(OK, StrCopy(s2, s1));
	EXPECT_EQ_INT(0, StrCompare(s1, s2));
	EXPECT_EQ_INT(4, StrLength(s2));
	EXPECT_EQ_INT(0, StringEmpty(s2));
	printf("拷贝s1生成的串为: ");
	StrPrint(s2);
	printf("s1,s2拷贝为深拷贝，s1指针:%p,s2指针:%p,两者不相等\n", s1, s2);
	EXPECT_FALSE(s2 == s1);

	 puts("(3) 字符串对比测试");
	 int i = StrCompare(s1, s2);
	 EXPECT_EQ_INT(0, i);
	 printf("串s1%c串s2\n", showCompareStatus(i));
	 i = StrCompare(s2, s1);
	 EXPECT_EQ_INT(0, i);
	 printf("串s2%c串s1\n", showCompareStatus(i));
	 
	 String s3;
	 EXPECT_EQ_INT(OK, StrAssign(s3, "ebcd"));
	 i = StrCompare(s1, s3);
	 printf("比较串s3=\"ebcd\",串s1%c串s3\n", showCompareStatus(i));
	 EXPECT_TRUE(i < 0);
	 i = StrCompare(s3, s1);
	 EXPECT_TRUE(i > 0);
	 EXPECT_EQ_INT(OK, StrAssign(s3, "abcde"));
	 printf("比较串s3=\"abcde\",串s1%c串s3\n", showCompareStatus(i));
	 EXPECT_TRUE(i < 0);
	 EXPECT_EQ_INT(OK, StrAssign(s3, "abce"));
	 printf("比较串s3=\"abce\",串s1%c串s3\n", showCompareStatus(i));
	 EXPECT_TRUE(i > 0);
	 
	// puts("(4)字符串连接测试");
	// String t;
	// EXPECT_EQ_INT(OK, Concat(t, s1, s2));
	// printf("串s1联接串s2得到的串t为: ");
	// StrPrint(t);
	// EXPECT_EQ_INT(0, strcmp(t, "abcdabcd"));
	// 
	// puts("(5)字符串清空操作");
	// EXPECT_EQ_INT(OK, ClearString(s1));
	// EXPECT_EQ_INT(0, StrCompare(s1, empty));
	// printf("清为空串后,串s1为: ");
	// StrPrint(s1);
	// printf("串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StringEmpty(s1));
	// 
	// puts("(6)求串t的子串,从主串第二个字符起截取3个");
	// printf("求串t的子串,请输入子串的起始位置,子串长度: ");
	// EXPECT_EQ_INT(OK, SubString(s1, t, 2, 3));
	// printf("子串s1为: ");
	// StrPrint(s1);
	// EXPECT_EQ_INT(0, strcmp(s1, "cda"));
	// 
	// puts("(7)从串t的第4个字符起,删除2个字符");
	// EXPECT_EQ_INT(OK, StrDelete(t, 4, 2));
	// printf("删除后的串t为: ");
	// StrPrint(t);
	// EXPECT_EQ_INT(0, strcmp(t, "abcdcd"));
	// 
	// puts("(8)字符插入测试");
	// i = StrLength(s2) / 2;
	// EXPECT_EQ_INT(OK,StrInsert(s2, i, t));
	// printf("在串s2的第%d个字符之前插入串t后,串s2为:\n", i);
	// StrPrint(s2);
	// 
	// puts("(9)字符匹配测试");
	// i = Index(s2, t, 1);
	// printf("s2的第%d个字母起和t第一次匹配\n", i);
	// 
	// puts("(10)字符替换测试");
	// Replace(s2, t, s1);
	// printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
	// StrPrint(s2);

}

int main() {
	test();
	TEST_REPORT;
}

static char showCompareStatus(int i)
{
	char s;
	if (i < 0)
		s = '<';
	else if (i == 0)
		s = '=';
	else
		s = '>';
	return s;
}
