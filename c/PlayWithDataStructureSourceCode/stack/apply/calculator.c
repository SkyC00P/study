#include "test.h"
#include "../stack.h"
#include <string.h>
#include <ctype.h>

typedef enum Operate {
	// + - * /
	Add, Sub, Ride, Division
}Operate;

static Stack_T numStack;
static Stack_T operateStack;

double calculator(char * express);

char * toRPN(char * express);
Bool isNum(char ch);
int getNum(char *, int, double*);

int main() {
	InitStack(&numStack);
	InitStack(&operateStack);

	char * express = "9 + (3-1) * 3 + 10 / 2";
	char * rpn_str = toRPN(express);
	EXPECT_EQ_INT(0, strcmp("9 3 1 - 3 * + 10 2 / +", rpn_str));

}

/*
  计算表达式
*/
double calculator(char * express) {

}

/*
  前缀表达式转后缀表达式
*/
char * toRPN(char * express) {
	if (!express) return NULL;

	int len = strlen(express);
	if (len == 0) return NULL;

	for (int i = 0; i < len; i++) {
		char ch = express[i];

		// 如果是数字则入数字栈
		if (isNum(ch)) {
			double num = 0;
			int index = getNum(express, i, &num);
			Push(numStack, num);
			i = index;
			continue;
		}
		else if (isspace(ch)) {
			continue;
		}
		else if (isOperate(ch)) {
			// 如果是操作符，则进操作栈

		}
		else if (ch == '(') {

		}
		else if (ch == ')') {

		}
		else if (ch == '\0') {

		}
		else {
			printf("Unknown char :%c\n", ch);
			return NULL;
		}
	}
}

Bool isNum(char ch)
{
	return TRUE;
}

int getNum(char *, int, double *)
{
	return 0;
}
