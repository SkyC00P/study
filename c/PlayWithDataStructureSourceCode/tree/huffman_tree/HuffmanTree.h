#ifndef HAVE_HUFFMAN_TREE_H
#define HAVE_HUFFMAN_TREE_H
#include "common.h"

typedef struct HTNode {
	unsigned int weight;
	struct HTNode *  parent;
	struct HTNode * lchild;
	struct HTNode * rchild;
}HTNode, *HTNodePtr;

typedef HTNode * HuffmanTree;

HuffmanTree HuffmanTree_create(FILE * fp);

void HuffmanTree_show(HuffmanTree ht);

#endif // !HAVE_HUFFMAN_TREE_H