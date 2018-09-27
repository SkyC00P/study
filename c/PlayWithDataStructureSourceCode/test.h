#ifndef HAVE_TEST_H
#define HAVE_TEST_H 1

#include <stdio.h>

static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
#define EXPECT_NOT_EQ_INT(num1, num2) EXPECT_EQ_BASE((num1) != (num2), num1, num2, "%d")
#define LOG(msg) printf("%s:%d: %s \n", __FILE__, __LINE__, msg);

#endif // !HAVE_TEST_H
