#include <stdio.h>

#define PRINT(msg) printf("%s:%d: %s \n", __FILE__, __LINE__, msg);

void fuc1(){
    PRINT("1");
    fuc2();
}

void fuc2(){
    PRINT("2");
}

int main(void) {
    fuc1();
}