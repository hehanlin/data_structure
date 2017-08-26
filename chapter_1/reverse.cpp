#include "../include/util.h"

//数组倒置,递归减而治之
void reverse(int A[], int lo, int hi) {
    if(lo<hi) {
        swap(A[lo], A[hi]);
        reverse(A, lo+1, hi-1);
    }
}

//迭代版
void reverse1(int A[], int lo, int hi) {
    while(lo<hi) swap(A[lo++], A[hi--]);
}

int main(void) {
    int A[] = {7,9,10,78,56,18,191,8,6};
    reverse1(A, 0, 8);   //[lo.hi]
    for(int i = 0; i< 9; i++ ){
        printf("%d\n",A[i]);
    }
}