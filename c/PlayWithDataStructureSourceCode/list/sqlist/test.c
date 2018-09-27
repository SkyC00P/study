#include "test.h"
#include "sqlist.h"


int main(void) {
	EXPECT_EQ_INT(1, 1);
	EXPECT_EQ_INT(1, 2);
	printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
	SqList L;
	printf("%d,%d,%d\n", test_count, test_pass, ListEmpty(L));
}