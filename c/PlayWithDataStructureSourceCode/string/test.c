#include "test.h"
#include "string.h"
#include <stdio.h>

static char showCompareStatus(int status);
static void test() {

	String s1 = NULL;
	puts("(1) 初始化字符串s1为abcd");
	EXPECT_EQ_INT(OK, StrAssign(s1, "abcd"));
	StrPrint(s1);
	EXPECT_EQ_INT(4, StrLength(s1));
	EXPECT_EQ_INT(0, StrEmpty(s1));
	printf("串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StrEmpty(s1));

#ifdef BOOK
	String tooLongStr = NULL;
	EXPECT_EQ_INT(ERROR, StrAssign(tooLongStr, "1234567890 1234567890 1234567890 1234567890 1234567890"));
#endif // BOOK
	
	puts("(2) 将字符串s1拷贝到s2,s2为空");
	String s2 = NULL;
	EXPECT_EQ_INT(OK, StrCopy(s2, s1));
	EXPECT_EQ_INT(0, StrCompare(s1, s2));
	EXPECT_EQ_INT(4, StrLength(s2));
	EXPECT_EQ_INT(0, StrEmpty(s2));
	printf("拷贝s1生成的串为: ");
	StrPrint(s2);
	printf("s1,s2拷贝为深拷贝，s1指针:%p,s2指针:%p,两者不相等\n", s1, s2);
	EXPECT_FALSE(s2 == s1);

	puts("(3) 字符串对比测试");
	String s3 = NULL;
	EXPECT_EQ_INT(OK,StrAssign(s3, "efghijk"));
	i = StrCompare(s1, s2);

	printf("串s1%c串s2\n", s);


	k = Concat(t, s1, s2);
	printf("串s1联接串s2得到的串t为: ");
	StrPrint(t);
	if (k == FALSE)
		printf("串t有截断\n");
	ClearString(s1);
	printf("清为空串后,串s1为: ");
	StrPrint(s1);
	printf("串长为%d 串空否？%d(1:是 0:否)\n", StrLength(s1), StrEmpty(s1));
	printf("求串t的子串,请输入子串的起始位置,子串长度: ");

	i = 2;
	j = 3;
	printf("%d,%d \n", i, j);

	k = SubString(s2, t, i, j);
	if (k)
	{
		printf("子串s2为: ");
		StrPrint(s2);
	}
	printf("从串t的第pos个字符起,删除len个字符，请输入pos,len: ");

	i = 4;
	j = 2;
	printf("%d,%d \n", i, j);


	StrDelete(t, i, j);
	printf("删除后的串t为: ");
	StrPrint(t);
	i = StrLength(s2) / 2;
	StrInsert(s2, i, t);
	printf("在串s2的第%d个字符之前插入串t后,串s2为:\n", i);
	StrPrint(s2);
	i = Index(s2, t, 1);
	printf("s2的第%d个字母起和t第一次匹配\n", i);
	SubString(t, s2, 1, 1);
	printf("串t为：");
	StrPrint(t);
	Concat(s1, t, t);
	printf("串s1为：");
	StrPrint(s1);
	Replace(s2, t, s1);
	printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
	StrPrint(s2);


	return 0;
}

int main() {
	test();
	TEST_REPORT;
}

char showCompareStatus(int i)
{
	if (i < 0)
		s = '<';
	else if (i == 0)
		s = '=';
	else
		s = '>';
}
