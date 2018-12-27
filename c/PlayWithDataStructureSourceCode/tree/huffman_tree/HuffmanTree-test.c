#include "HuffmanTree.h"
#include "test.h"

static void test();
static HuffmanTree tree;

int main() {
	test();
	//TEST_REPORT;
}

static void test() {
	puts("初始化赫尔曼树");
	FILE * fp = fopen("huffman_tree/test_data.txt", "r");
	if (fp) {
		tree = HuffmanTree_create(fp);
		EXPECT_TRUE(tree != NULL);
		fclose(fp);
	}
	else {
		Exit_with_msg("IO Error\n");
	}

	puts("展示赫尔曼树");
	HuffmanTree_show(tree);


}