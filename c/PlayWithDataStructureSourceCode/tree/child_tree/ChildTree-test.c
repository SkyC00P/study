#include "test.h"
#include "ChildTree.h"
#include <stdlib.h>

static ChildTree tree;
static ChildTree subtree;

static void showChar(ChildNodeType e);
static void test();

int main() {
	test();
	TEST_REPORT;
}
Status ChildTree_insertChild(ChildTree * T, ChildNodeType e, ChildNodeType new, int order);
static void test() {
	puts("(1) 初始化测试");
	{
		FILE * fp = fopen("child_tree/TestData_T.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, ChildTree_init(&tree, fp));
			fclose(fp);
			ChildTree_print(tree);
			ChildTree_levelOrderTraverse(tree, showChar);
			EXPECT_EQ_INT(3, ChildTree_degree(tree));
			EXPECT_EQ_INT(5, ChildTree_depth(tree));
			EXPECT_EQ_INT('R', ChildTree_root(tree));
		}
		else
		{
			fprintf(stderr, "IO ERROR");
			exit(-1);
		}

		fp = fopen("child_tree/TestData_T0.txt","r");
		if (fp) {
			EXPECT_EQ_INT(OK, ChildTree_init(&subtree, fp));
			fclose(fp);
			ChildTree_print(subtree);
			ChildTree_levelOrderTraverse(subtree, showChar);
			EXPECT_EQ_INT(3, ChildTree_degree(subtree));
			EXPECT_EQ_INT(3, ChildTree_depth(subtree));
			EXPECT_EQ_INT('0', ChildTree_root(subtree));
		}
		else
		{
			fprintf(stderr, "IO ERROR");
			exit(-1);
		}
	}

	puts("(2) 查询测试"); 
	{
		puts("-> 验证ChildTree_vaule()");
		EXPECT_EQ_INT('R', ChildTree_vaule(tree, 0));
		EXPECT_EQ_INT('D', ChildTree_vaule(tree, 4));
		EXPECT_EQ_INT('I', ChildTree_vaule(tree, 10));

		EXPECT_EQ_INT('0', ChildTree_vaule(subtree, 0));
		EXPECT_EQ_INT('3', ChildTree_vaule(subtree, 3));
		EXPECT_EQ_INT('5', ChildTree_vaule(subtree, 5));

		puts("-> 验证ChildTree_order()");
		EXPECT_EQ_INT(0, ChildTree_order(tree, 'R'));
		EXPECT_EQ_INT(4, ChildTree_order(tree, 'D'));
		EXPECT_EQ_INT(10, ChildTree_order(tree, 'I'));

		EXPECT_EQ_INT(0, ChildTree_order(subtree, '0'));
		EXPECT_EQ_INT(3, ChildTree_order(subtree, '3'));
		EXPECT_EQ_INT(5, ChildTree_order(subtree, '5'));

		puts("-> 验证ChildTree_assign()");
		puts("将树tree根结点R替换Z");
		EXPECT_EQ_INT(OK, ChildTree_assign(&tree, 'R', 'Z'));
		puts("将树tree结点D替换T");
		EXPECT_EQ_INT(OK, ChildTree_assign(&tree, 'D', 'T'));
		ChildTree_print(tree);

		puts("-> 验证ChildTree_findChild()");
		EXPECT_TRUE(ChildTree_findChild(tree, 'F', 2) == 'H');
		EXPECT_TRUE(ChildTree_findChild(tree, 'F', 1) == 'G');
		EXPECT_TRUE(ChildTree_findChild(tree, 'B', 2) == '\0');

		puts("-> 验证ChildTree_findBrother()");
		EXPECT_TRUE(ChildTree_findBrother(tree, 'H', 1) == 'G');
		EXPECT_TRUE(ChildTree_findBrother(tree, 'H', 2) == 'K');
		EXPECT_TRUE(ChildTree_findBrother(tree, 'H', 3) == '\0');

		puts("-> 验证ChildTree_getChildCount()");
		EXPECT_EQ_INT(3, ChildTree_getChildCount(tree, 'F'));
		EXPECT_EQ_INT(2, ChildTree_getChildCount(tree, 'A'));
		EXPECT_EQ_INT(3, ChildTree_getChildCount(tree, 'Z'));
		EXPECT_EQ_INT(0, ChildTree_getChildCount(tree, 'B'));
	}

	puts("(3) 新增结点测试");
	{
		EXPECT_EQ_INT(OK, ChildTree_insertTree(&tree, 'Z', 2, subtree));
		ChildTree_print(tree);
		ChildTree tmp; 
		ChildTree_init(&tmp, fopen("child_tree/TestData_T1.txt","r"));
		EXPECT_TRUE(ChildTree_isTheSame(tree, tmp));
	}

	puts("(4) 删除结点测试"); {
		EXPECT_EQ_INT(OK, ChildTree_deleteTree(&tree, 'Z', 2));
		ChildTree tmp;
		ChildTree_init(&tmp, fopen("child_tree/TestData_T2.txt", "r"));
		ChildTree_print(tmp);
		EXPECT_TRUE(ChildTree_isTheSame(tree, tmp));
	}

}

static void showChar(ChildNodeType e) {
	printf("%c ", e);
}