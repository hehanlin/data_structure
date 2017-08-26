#include "../include/util.h"
//找出数组中最大的两个数
void max2(int A[], int lo, int hi, int &x1, int &x2) {
    int i = 0;
    for(x1 =lo, i = lo+1; i<hi; i++ ) {
        if(A[x1]<A[i])  x1 = i;
    }
    
    for(x2=lo, i =lo+1; i<x1; i++) {
        if(A[x2]<A[i]) x2 = i;
    }

    for(int i = x1+1; i<hi; i++) {
        if(A[x2]<A[i]) x2 = i;
    }
}

void max2_a(int A[], int lo, int hi, int &x1, int &x2) {
    if(A[x1=lo] < A[x2=lo+1]) swap(x1, x2);
    for(int i = lo+2; i< hi; i++) {
        if(A[x2] < A[i]) {
            if(A[x1]<A[x2=i]) {
                swap(x1, x2);
            }
        }
    }
}

int main(void) {
    int A[] = {7,9,10,78,56,18,191,8,6};
    int x1, x2;
    max2_a(A, 0, 9, x1, x2);
    printf("%d   %d\n",A[x1], A[x2]);
    return 0;
}