#include "../include/util.h"

//冒泡排序，可根据sorted标志提前结束
void bubbleSort(int A[], int n) {
    for(bool sorted = false; sorted = !sorted; n--) {
        for(int i = 1; i < n ; i++) {
            if(A[i-1]>A[i]) {
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
    }
}
 
int main(void) {
    int A[] = {7,9,10,78,56,18,191,8,6};
    bubbleSort(A, 9);
    for(int i = 0; i< 9; i++ ){
        printf("%d\n",A[i]);
    }
}