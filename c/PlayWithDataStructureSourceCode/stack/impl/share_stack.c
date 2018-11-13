#include "test.h"
#include "common.h"
#define MAXSIZE 20

typedef struct {
	int data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status SqDoubleStack_Push(SqDoubleStack *S, int e, int stackNumber);
Status SqDoubleStack_Pop(SqDoubleStack *S, int *e, int stackNumber);
Status SqDoubleStack_Init(SqDoubleStack *S);
Status SqDoubleStack_Clear(SqDoubleStack *S);
Bool SqDoubleStack_Empty(SqDoubleStack S);
int SqDoubleStack_Length(SqDoubleStack S);
void SqDoubleStack_Traverse(SqDoubleStack S);

Status SqDoubleStack_Push(SqDoubleStack *S, int e, int stackNumber) {
	if (!S) return ERROR;
	if (S->top1 + 1 == S->top2) return ERROR;

	if (stackNumber == 1 ){
		S->data[++S->top1] = e;
		return OK;
	}

	if (stackNumber == 2) {
		S->data[--S->top2] = e;
		return OK;
	}

	return ERROR;
}

Status SqDoubleStack_Pop(SqDoubleStack *S, int *e, int stackNumber) {
	if (!S) return ERROR;

	if (stackNumber == 1) {
		if (S->top1 == -1) return ERROR;
		*e = S->data[S->top1--];
		return OK;
	}

	if (stackNumber == 2){
		if (S->top2 == MAXSIZE) return ERROR;
		*e = S->data[S->top2++];
		return OK;
	}

	return ERROR;
}

Status SqDoubleStack_Init(SqDoubleStack *S) {
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

Status SqDoubleStack_Clear(SqDoubleStack *S) {
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

Bool SqDoubleStack_Empty(SqDoubleStack S) {
	return S.top1 == -1 && S.top2 == MAXSIZE ? TRUE : FALSE;
}

int SqDoubleStack_Length(SqDoubleStack S) {
	return S.top1 + 1 + MAXSIZE - S.top2;
}

void SqDoubleStack_Traverse(SqDoubleStack S) {
	int i = S.top1;
	printf("栈(1):");
	while (i >= 0) {
		printf("%d ", S.data[i--]);
	}
	i = S.top2;
	printf(",栈(2):");
	while (i < MAXSIZE) {
		printf("%d ", S.data[i++]);
	}
	printf("\n");
}

int main() {
	SqDoubleStack s;
	int e;
	EXPECT_EQ_INT(OK, SqDoubleStack_Init(&s));

	puts("(1)在第一个栈依次压入:1, 2, 3, 4, 5;栈顶为5");
	for (int j = 1; j <= 5; j++) {
		EXPECT_EQ_INT(OK, SqDoubleStack_Push(&s, j, 1));
	}

	puts("(2)在第二个栈依次压入:20,19,18;栈顶为18");
	for (int j = MAXSIZE; j >= MAXSIZE - 2; j--) {
		EXPECT_EQ_INT(OK, SqDoubleStack_Push(&s, j, 2));
	}

	printf("栈中元素依次为：");
	SqDoubleStack_Traverse(s);

	printf("当前栈中长度有：%d \n", SqDoubleStack_Length(s));
	EXPECT_EQ_INT(8, SqDoubleStack_Length(s));

	SqDoubleStack_Pop(&s, &e, 2);
	printf("(3)第二个栈弹出的栈顶元素 e=%d\n", e);
	EXPECT_EQ_INT(18, e);
	printf("栈空否：%d(1:空 0:否)\n", SqDoubleStack_Empty(s));
	EXPECT_EQ_INT(FALSE, SqDoubleStack_Empty(s));

	SqDoubleStack_Pop(&s, &e, 1);
	printf("(4)第一个栈弹出的栈顶元素 e=%d\n", e);
	EXPECT_EQ_INT(5, e);
	printf("栈空否：%d(1:空 0:否)\n", SqDoubleStack_Empty(s));
	EXPECT_EQ_INT(FALSE, SqDoubleStack_Empty(s));

	puts("(5)在第一个栈依次压入:5,6,7,...,17,18");
	for (int j = 5; j <= MAXSIZE - 2; j++) {
		EXPECT_EQ_INT(OK, SqDoubleStack_Push(&s, j, 1));
	}

	printf("栈中元素依次为：");
	SqDoubleStack_Traverse(s);

	printf("栈满否：%d(1:否 0:满)\n", SqDoubleStack_Empty(s));

	puts("(6)对满栈任意1，2栈再压数据");
	Status s1 = SqDoubleStack_Push(&s, 1, 1);
	EXPECT_EQ_INT(ERROR, s1);
	printf("结果栈1:%d,", s1);
	Status s2 = SqDoubleStack_Push(&s, 1, 2);
	EXPECT_EQ_INT(ERROR, s2);
	printf("栈2:%d(OK:1,ERROR:0)\n",s2);

	puts("(7)清空栈");
	EXPECT_EQ_INT(OK, SqDoubleStack_Clear(&s));
	printf("栈空否：%d(1:空 0:否)\n", SqDoubleStack_Empty(s));

	printf("\n");
	TEST_REPORT;
	return 0;
}
