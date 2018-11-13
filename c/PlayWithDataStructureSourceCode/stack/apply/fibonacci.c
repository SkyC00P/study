#include <stdio.h>
#include "test.h"

int fibonacci(int n);
int main() {

	EXPECT_EQ_INT(0, fibonacci(0));
	EXPECT_EQ_INT(1, fibonacci(1));
	EXPECT_EQ_INT(1, fibonacci(2));
	EXPECT_EQ_INT(2, fibonacci(3));
	EXPECT_EQ_INT(3, fibonacci(4));
	EXPECT_EQ_INT(5, fibonacci(5));
	EXPECT_EQ_INT(8, fibonacci(6));
	EXPECT_EQ_INT(13, fibonacci(7));
	EXPECT_EQ_INT(21, fibonacci(8));
	EXPECT_EQ_INT(34, fibonacci(9));
	EXPECT_EQ_INT(55, fibonacci(10));
	TEST_REPORT;

	while (1)
	{
		printf("请输入斐波那契数列的N值:\n");
		int n = 0;
		int code = scanf("%d", &n);

		if (code != 1 || code == 0 || code == EOF) return -2;

		if (n < 0) {
			printf("Error:N值小于0\n");
			return -1;
		}
		else
		{
			int sum = fibonacci(n);
			printf("当N为%d,结果为:%d\n\n",n, sum);
		}
	}
}

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}