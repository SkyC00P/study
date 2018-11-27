#include "ParentTree.h"

Status ParentTree_init(PTree * T)
{
	T->n = 0;
	return OK;
}

Bool ParentTree_isEmpty(PTree T)
{
	return T.n == 0 ? TRUE : FALSE;
}

Status ParentTree_create(FILE * fp, PTree * T)
{
	char buf[50];

	while ((fgets(buf, sizeof(buf), fp)) != NULL) {
		printf("%s\n", buf);
		break;
	}
	return OK;
}
