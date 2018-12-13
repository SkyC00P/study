#include "HashMap.h"
#include "test.h"
#include <stdlib.h>

static HashMap map;
static void test();
static void map_free_value(void * val);
static unsigned int free_space = 0;

static char test_data_upper_case[] = {
	'A','B','C','D','E','F','G',
	'H','I','J','K','L','M','N',
	'O','P','Q','R','S','T',
	'U','V','W','X','Y','Z'
};

static char test_data_lower_case[] = {
	'a','b','c','d','e','f','g',
	'h','i','j','k','l','m','n',
	'o','p','q','r','s','t',
	'u','v','w','x','y','z'
};

static char test_data_num[] = {
	'0','1','2','3','4','5','6','7','8','9'
};

typedef struct ChNode
{
	char ch;
	int index;
}ChNode, *ChNodePtr;

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1)初始化测试");
	{
		map = HashTable_init();
		EXPECT_TRUE(map != NULL);
		EXPECT_TRUE(HashMap_isEmpty(map));
	}

	puts("(2)put,get,remove测试"); {
		puts("->以26个大写字母为Key,每一个字母对应一个结点，结点里包含字母和在数组的下标");
		for (int i = 0; i < 26; i++) {
			ChNodePtr ptr = malloc(sizeof(ChNode));
			ptr->ch = test_data_upper_case[i];
			ptr->index = i;
			EXPECT_EQ_INT(OK, HashMap_put(map, test_data_upper_case[i], ptr));
		}
		EXPECT_FALSE(HashMap_isEmpty(map));
		EXPECT_EQ_INT(26, HashMap_size(map));

		puts("->以26个小写字母为Key,每一个字母对应一个结点，结点里包含字母和在数组的下标");
		for (int i = 0; i < 26; i++) {
			ChNodePtr ptr = malloc(sizeof(ChNode));
			ptr->ch = test_data_lower_case[i];
			ptr->index = i;
			EXPECT_EQ_INT(OK, HashMap_put(map, test_data_lower_case[i], ptr));
		}
		EXPECT_FALSE(HashMap_isEmpty(map));
		EXPECT_EQ_INT(52, HashMap_size(map));

		puts("->以10个数字为Key,每一个数字对应一个结点，结点里包含数字和在数组的下标");
		for (int index = 0; index < 10; index++) {
			ChNodePtr ptr = malloc(sizeof(ChNode));
			ptr->ch = test_data_num[index];
			ptr->index = index;
			EXPECT_EQ_INT(OK, HashMap_put(map, test_data_num[index], ptr));
		}
		EXPECT_EQ_INT(62, HashMap_size(map));

		puts("->验证特殊字符\"#\",以及修改已有值，以及验证不同key相同hash值的错误处理");
		ChNodePtr ptr = malloc(sizeof(ChNode));
		ptr->ch = '#';
		ptr->index = 63;
		EXPECT_EQ_INT(OK, HashMap_put(map, '#', ptr));

		ChNodePtr getPtr = (ChNodePtr)HashMap_get(map, '#');
		EXPECT_EQ_INT('#', getPtr->ch);
		EXPECT_EQ_INT(63, getPtr->index);

		ChNodePtr ptr_new = malloc(sizeof(ChNode));
		ptr_new->ch = '-';
		ptr_new->index = 64;
		EXPECT_EQ_INT(OK, HashMap_put(map, '#', ptr_new));

		ChNodePtr getPtr_new = (ChNodePtr)HashMap_get(map, '#');
		EXPECT_EQ_INT('-', getPtr_new->ch);
		EXPECT_EQ_INT(64, getPtr_new->index);
		EXPECT_TRUE(getPtr_new != getPtr);

		EXPECT_EQ_INT(ERROR, HashMap_put(map, 0, ptr)); // 0 的hash值和 101的哈希值是一样的 101就是'e'
		EXPECT_EQ_INT(63, HashMap_size(map));
		EXPECT_TRUE(NULL == HashMap_get(map, 0));

		ChNodePtr rmNode = HashMap_remove(map, 101);
		EXPECT_TRUE(rmNode);
		printf("移除掉 char:[%c],移除结点保存的值和下标:[%c, %d]\n", 101, rmNode->ch, rmNode->index);
		EXPECT_EQ_INT(62, HashMap_size(map));
		EXPECT_EQ_INT(OK, HashMap_put(map, 0, ptr)); // 这时就OK,hash不冲突了
		
		// 恢复原样释放临时的测试资源
		HashMap_remove(map, 0);
		EXPECT_EQ_INT(OK, HashMap_put(map, 101, rmNode));
		EXPECT_EQ_INT(OK, HashMap_put(map, '#', ptr));
		free(getPtr_new);
	}

	puts("(3) 匹配测试");
	{
		for (int i = 0; i < 26; i++) {
			EXPECT_TRUE(HashMap_contain(map, test_data_upper_case[i]));
		}
		for (int i = 0; i < 26; i++) {
			EXPECT_TRUE(HashMap_contain(map, test_data_lower_case[i]));
		}
		for (int i = 0; i < 10; i++)
		{
			EXPECT_TRUE(HashMap_contain(map, test_data_num[i]));
		}
		EXPECT_TRUE(HashMap_contain(map, '#'));
		EXPECT_EQ_INT(63, HashMap_size(map));
	}

	puts("(4) Map销毁测试");
	{
		HashMap_destory(map, map_free_value);
		EXPECT_EQ_INT(63 * sizeof(ChNode), free_space);
	}
}

void map_free_value(void * val)
{
	if (val) {
		ChNodePtr ptr = (ChNodePtr)val;
		free_space += sizeof(ChNode);
		free(ptr);
	}
}
