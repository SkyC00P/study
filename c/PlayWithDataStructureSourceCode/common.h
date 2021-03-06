#ifndef HAVE_COMMON_H
#define HAVE_COMMON_H 1
#include <stdlib.h>
#include <stdio.h>

typedef int Status;
typedef int Bool;
/* 状态码 */
#define	TRUE		1			//真 
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否 
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功 
#define UNSUCCESS	0			//失败 
#define	INFEASIBLE	-1			//不可行

#ifndef _MATH_H_ 				//系统中已有此状态码定义，要避免冲突 
#define	OVERFLOW	-2			//堆栈上溢
#define UNDERFLOW	-3			//堆栈下溢
#endif

#define DG(x) printf("%d\n",x);
#define CheckPtr(ptr) \
    do {\
		if (!ptr) {\
			fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);\
			exit(INFEASIBLE);\
		}\
    } while(0)

#define Exit_with_msg(msg) \
    do {\
		fprintf(stderr, "%s:%d:%s\n", __FILE__, __LINE__, msg);\
		exit(INFEASIBLE);\
    } while(0)

static inline void Exit_without_msg() {
	exit(INFEASIBLE);
}
#endif // !HAVE_COMMON_H
