#ifndef HAVE_CHILD_TREE_H
#define HAVE_CHILD_TREE_H
#include <stdio.h>
#include "common.h"

typedef struct ChildTree {
	int i;
} ChildTree;

Status ChildTree_init(ChildTree * T, FILE *fp);

#endif // !HAVE_CHILD_TREE_H
