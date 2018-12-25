#include "test.h"
#include "BinaryTree.h"

static BiTree tree;
static void test();
static void Error();
void PrintElem(BiTData e){printf("%c ", e);}

int main() {
	test();
	TEST_REPORT;
}
static void Error() {
	fprintf(stderr, "IO ERROR");
	exit(-1);
}
static void test() {
	puts("(1)初始化测试");
	{
		FILE * fp = fopen("binary_tree/test_data/pre_order.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, BiTree_create(fp, &tree));
			EXPECT_TRUE(tree != NULL);
			EXPECT_EQ_INT(4, BiTree_depth(tree));
			BiTree_print(tree);
			fclose(fp);
		}
		else {
			Error();
		}
	}

	puts("(2)查找测试");
	{
		BiTNode * node = BiTree_parent(tree, 'B');
		EXPECT_TRUE(node != NULL);
		EXPECT_TRUE(node->data == 'A');

		node = BiTree_parent(tree, 'J');
		EXPECT_TRUE(node->data == 'F');

		node = BiTree_parent(tree, 'A');
		EXPECT_TRUE(node == NULL);

		BiTNode * lnode = BiTree_left_child(tree, 'A');
		BiTNode * rnode = BiTree_right_child(tree, 'A');
		EXPECT_TRUE(lnode != NULL && lnode->data == 'B');
		EXPECT_TRUE(rnode != NULL && rnode->data == 'C');

		lnode = BiTree_left_child(tree, 'E');
		rnode = BiTree_right_child(tree, 'E');
		EXPECT_TRUE(lnode != NULL && lnode->data == 'H');
		EXPECT_TRUE(rnode != NULL && rnode->data == 'I');

		lnode = BiTree_left_child(tree, 'J');
		rnode = BiTree_right_child(tree, 'J');
		EXPECT_TRUE(lnode == NULL);
		EXPECT_TRUE(rnode == NULL);

		BiTNode * lBnode = BiTree_left_brother(tree, 'I');
		BiTNode * rBnode = BiTree_right_brother(tree, 'H');
		EXPECT_TRUE(lBnode != NULL && lBnode->data == 'H');
		EXPECT_TRUE(rBnode != NULL && rBnode->data == 'I');

		lBnode = BiTree_left_brother(tree, 'G');
		rBnode = BiTree_right_brother(tree, 'G');
		EXPECT_TRUE(lBnode == NULL);
		EXPECT_TRUE(rBnode == NULL);
	}

	puts("(3)遍历测试");
	{
		puts("-> 层序遍历");
		BiTree_level_order_traverse(tree, PrintElem);
		printf("\n-> 非递归版本 - 前序遍历\n");
		BiTree_pre_order_traverse(tree, PrintElem);
		printf("\n-> 非递归版本 - 中序遍历\n");
		BiTree_in_order_traverse(tree, PrintElem);
		printf("\n-> 非递归版本 - 后序遍历\n");
		BiTree_post_order_traverse(tree, PrintElem);
		printf("\n");
	}

	puts("(4)增删测试");
	{
		BiTree addTree;
		FILE * fp = fopen("binary_tree/test_data/del.txt", "r");
		if (fp) {
			EXPECT_EQ_INT(OK, BiTree_create(fp, &addTree));
			EXPECT_TRUE(addTree != NULL);
			puts("新插入的树为");
			BiTree_print(addTree);
			fclose(fp);
		}
		else {
			Error();
		}
		puts("增加前tree打印");
		BiTree_print(tree);
		puts("在B的左结点增加后tree打印");
		EXPECT_EQ_INT(OK, BiTree_insert(tree, 'B', addTree, bitree_direction_left_0));
		BiTree_print(tree);
		puts("在B的左结点删除后tree打印");
		EXPECT_EQ_INT(OK, BiTree_delete(tree, 'B', bitree_direction_left_0));
		BiTree_print(tree);
	}
}