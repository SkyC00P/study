#include "test.h"
#include "../stack.h"
#include <string.h>

static Stack_T numStack;
static Stack_T operateStack;
/*
  计算表达式
*/
double calculator(char * express) {

}

/*
  前缀表达式转后缀表达式
*/
char * toRPN(char * express) {
	int len = strlen(express);
	for (int i = 0; i < len; i++){
		char ch = express[i];

		// 如果是数字则入数字栈
		if (isNum(ch)) {
			Push(numStack, toNum(ch))
		}
	}
}

int main() {
	char * express = "9 + (3-1) * 3 + 10 / 2";
	char * rpn_str = toRPN(express);
	EXPECT_EQ_INT(0, strcmp("9 3 1 - 3 * + 10 2 / +", rpn_str));


}