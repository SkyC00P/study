#include "HuffmanTree.h"
#include "test.h"

static void test();
static HuffmanTree tree;

int main() {
	test();
	//TEST_REPORT;
}

static void test() {
	FILE * fp = fopen("huffman_tree/test_data.txt", "r");
	if (fp) {
		tree = HuffmanTree_create(fp);
		
		fclose(fp);
	}
	else {
		Exit_with_msg("IO Error\n");
	}
}