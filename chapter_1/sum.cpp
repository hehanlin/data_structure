#include "../include/util.h"

//递归版数组求和，减而治之
int sum(int A[], int n) {
    return (n<1) ?
        0   :   sum(A, n-1) + A[n-1];
}

//分而治之
int sum1(int A[], int lo, int hi) {
    if(lo==hi)return A[lo];
    int mi = (lo+hi)>>1;
    return sum1(A, lo, mi) + sum1(A, mi+1, hi);
}

int main(void) {
    // int A[] = {7,9,10,78,56,18,191,8,6};
    // printf("%d\n", sum(A, 9));
    int A[] = {7,9,10,78,56,18,191,8,6};
    int a = sum1(A, 0, 8);
    printf("%d\n", a);
}