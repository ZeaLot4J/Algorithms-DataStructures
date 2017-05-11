#include <stdio.h>
/* 最长上升子序列 */

/*
    序列:   10 3 4 1 7 5 6 8 9
    结果:   3 4 5 8 9
设dp[i]表示以arr[i]为最后的数得到的最长上升序列的长度
    dp[i] = arr[0]~arr[i] (其中j>=0 && j<i) 的满足arr[j] < arr[i] 的数中dp[j]最大的那个 + 1


dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 1
dp[4] = 3
dp[5] = 3
dp[6] = 4
dp[7] = 5
dp[8] = 6

*/
/* 版本一 n^2 */
void lis1(int* arr, int len){
    int i,j,max;
    int dp[100] = {0};
    dp[0] = 1;
    for(i=1; i<len; i++){
        max = 0;//最小长度不会小于1，并且如果前面没有比当前arr[i]小的，则dp[i] 为 1，也表示为max+1
        for(j=0; j<i; j++){
            if(arr[j] < arr[i] && max < dp[j]){
                max = dp[j];
            }
        }
        dp[i] = max + 1;
    }

    for(i=0; i<len; i++){
        printf("%d ", dp[i]);
    }
}
/* 版本二 优化找最大值部分 二分 nlogn */
/*
序列:   10 3 4 1 7 5 6 8 9
结果:   3  4 5 8 9
dp[0] = 1 aux[0] = 10
dp[1] = 3 aux[]
*/
void lis2(int* arr, int len){
    int i,j,max;
    int dp[100] = {0};
    dp[0] = 1;
    for(i=1; i<len; i++){
        max = 0;//最小长度不会小于1
        for(j=0; j<i; j++){
            if(arr[j] < arr[i] && max < dp[j]){
                max = dp[j];
            }
        }
        dp[i] = max + 1;
    }

    for(i=0; i<len; i++){
        printf("%d ", dp[i]);
    }
}
int main(){

    int arr[] = {10, 3, 4, 1, 7, 5, 6, 8, 9};
    lis1(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
