#include "HashMap.h"
#include "test.h"

static HashMap map;
static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1)初始化测试");
	{
		map = HashTable_init();
		EXPECT_TRUE(map != NULL);
		EXPECT_TRUE(HashMap_isEmpty(NULL));
	}
}