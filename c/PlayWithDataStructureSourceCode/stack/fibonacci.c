#include <stdio.h>
int fibonacci(int n);
int main() {
	while (1)
	{
		printf("请输入斐波那契数列的N值:\n");
		int n = 0;
		scanf("%d", &n);

		if (n < 0) {
			printf("Error:N值小于0\n");
			return -1;
		}
		else
		{
			int sum = fibonacci(n);
			printf("结果为:%d\n\n", sum);
		}
	}
}

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}