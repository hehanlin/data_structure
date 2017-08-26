#include "../include/util.h"

//斐波那契数列
int fib(int n) {
    return (2>n) ? n : fib(n-1)+fib(n-2);
}

//迭代版
int fib1(int n) {
    int f = 0, g = 1;
    while(0<n--) {
        g= g+f;
        f= g-f;
    }
    return f;
}

int main(void) {
    printf("%d\n", fib1(10));
}