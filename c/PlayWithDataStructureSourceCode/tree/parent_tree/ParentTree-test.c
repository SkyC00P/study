/*
 树的数据结构不适合用顺序存储结构来存储，实在是太不方便了
 他的优势就是存取是O(1)，可以根据层序号拿到结点，结点的双亲
 通过一个唯一标识符来获得树的结点，那么这个唯一标识符是什么呢？
 如果允许存储的数据不重复，而且存储的数据可以进行比较，那么可以用存储的数据来作为唯一的标识符
 例如存储的数据为字符类型且不重复，那么就OK: A为根结点，BCD为A的孩子结点。
 但如果是允许重复，则得给存储的类型搞一个Hash函数，通过该哈希函数来获得唯一值，

 树的API设计难的点是:
 1. 根据什么来获得指定的结点
 2. 结点存储的数据允不允许重复
 3. 树的各结点顺序是否需要维护

 主要的API
 3. 插入子树，插入孩子结点，插入兄弟结点
 4. 删除子树
 5. 查找指定值的结点
 6. 查找指定结点的双亲，兄弟，孩子，堂兄弟
 7. 树的各结点层序号
*/
#include "ParentTree.h"
#include "test.h"

static PTree tree;
void test_create_tree();
void PrintElem(TElemType p);
void test_get_vaule();
void test_init();
void test();
void test_order();

int main() {
	test();
	TEST_REPORT;
}

void test_create_tree()
{
	puts("(2) 按文件的层序序列构造树 测试");
	{
		FILE *fp;
		fp = fopen("parent_tree/TestData_T.txt", "r");
		if (fp) {
			ParentTree_create(fp, &tree);
			fclose(fp);
			puts("");
			ParentTree_print(tree);
			printf("层序遍历树:");
			ParentTree_levelOrderTraverse(tree, PrintElem);
		}

	}
	puts("");
}

void PrintElem(TElemType p)
{
	printf("%c ", p);
}

void test_get_vaule()
{
	puts("(3) 获取值测试"); {
		EXPECT_TRUE('A' == ParentTree_value(tree, 1));
		EXPECT_TRUE('B' == ParentTree_value(tree, 2));
		EXPECT_TRUE('C' == ParentTree_value(tree, 3));
		EXPECT_TRUE('D' == ParentTree_value(tree, 4));
		EXPECT_TRUE('E' == ParentTree_value(tree, 5));
		EXPECT_TRUE('F' == ParentTree_value(tree, 6));
		EXPECT_TRUE('G' == ParentTree_value(tree, 7));
		EXPECT_TRUE('H' == ParentTree_value(tree, 8));
		EXPECT_TRUE('I' == ParentTree_value(tree, 9));
		EXPECT_TRUE('J' == ParentTree_value(tree, 10));
	}
	puts("");
}

void test_init()
{
	puts("(1) 初始化测试");
	{
		EXPECT_EQ_INT(OK, ParentTree_init(&tree));
		EXPECT_EQ_INT(0, tree.n);
		EXPECT_EQ_INT(TRUE, ParentTree_isEmpty(tree));
	}
	puts("");
}

void test() {
	test_init();
	test_create_tree();

	EXPECT_EQ_INT(3, ParentTree_degree(tree));
	EXPECT_EQ_INT(4, ParentTree_depth(tree));
	EXPECT_EQ_INT('A', ParentTree_root(tree));

	test_get_vaule();
	test_order();

	printf("(4)函数 ParentTree_assign 测试...\n");
	{
		ParentTree_assign(&tree, 'B', 'X');
		EXPECT_TRUE(1 == ParentTree_order(tree, 'X'));
		printf("\n");
	}

	TElemType e = ParentTree_childVaule(tree, 'A', 2);
	EXPECT_TRUE(e == 'C');

	e = ParentTree_siblingVaule(tree, 'H', 1);
	EXPECT_TRUE(e == 'G');
	e = ParentTree_siblingVaule(tree, 'H', 2);
	EXPECT_TRUE(e == 'I');

	EXPECT_EQ_INT(2, ParentTree_ChildCount(tree, 'A'));
	EXPECT_EQ_INT(0, ParentTree_ChildCount(tree, 'I'));
	EXPECT_EQ_INT(3, ParentTree_ChildCount(tree, 'D'));

	printf("(5) 函数 ChildCount_P、ChildSeat_P、InsertChild_P、InsertTree_P 等测试...\n");
	{
		PTree T0;
		FILE *fp;

		printf("创建并打印树 T0 ...\n");
		ParentTree_init(&T0);
		fp = fopen("parent_tree/TestData_T0.txt", "r");
		ParentTree_create(fp, &T0);
		fclose(fp);
		ParentTree_print(tree);
		ParentTree_print(T0);
		printf("将树 T0 插入为树 T 中结点 %c 的第 %d 棵子树后，T = \n", 'X', 1);
		ParentTree_insertTree(&tree, 'D', 2, T0);
		ParentTree_print(tree);
		printf("\n");
	}

	printf("(6)删除树测试\n");				//18.函数DeleteTree_P测试
	{
		ParentTree_print(tree);
		printf("删除 T 中结点 %c 的第 %d 棵子树后，T = \n", 'D', 3);
		ParentTree_delteTree(&tree, '0', 3);
		ParentTree_print(tree);
		printf("\n");
	}

	ParentTree_clear(&tree);
	EXPECT_EQ_INT(TRUE, ParentTree_isEmpty(tree));
}

void test_order() {
	puts("(3) 获取序列测试"); {
		EXPECT_TRUE(0 == ParentTree_order(tree, 'A'));
		EXPECT_TRUE(1 == ParentTree_order(tree, 'B'));
		EXPECT_TRUE(2 == ParentTree_order(tree, 'C'));
		EXPECT_TRUE(3 == ParentTree_order(tree, 'D'));
		EXPECT_TRUE(4 == ParentTree_order(tree, 'E'));
		EXPECT_TRUE(5 == ParentTree_order(tree, 'F'));
		EXPECT_TRUE(6 == ParentTree_order(tree, 'G'));
		EXPECT_TRUE(7 == ParentTree_order(tree, 'H'));
		EXPECT_TRUE(8 == ParentTree_order(tree, 'I'));
		EXPECT_TRUE(9 == ParentTree_order(tree, 'J'));
		EXPECT_TRUE(-1 == ParentTree_order(tree, 'Z'));
	}
	puts("");
}