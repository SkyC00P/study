#include <stdio.h>

#define PRINT(msg) printf("%s:%d: %s \n", __FILE__, __LINE__, msg);

int main() {
	int ar[10];
	int * restrict restar = (int *)malloc(10 * sizeof(int));
	int * par = ar;
}