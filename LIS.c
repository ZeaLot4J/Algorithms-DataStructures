#include <stdio.h>
/* ����������� */

/*
    ����:   10 3 4 1 7 5 6 8 9
    ���:   3 4 5 8 9
��dp[i]��ʾ��arr[i]Ϊ�������õ�����������еĳ���
    dp[i] = arr[0]~arr[i] (����j>=0 && j<i) ������arr[j] < arr[i] ������dp[j]�����Ǹ� + 1


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
/* �汾һ n^2 */
void lis1(int* arr, int len){
    int i,j,max;
    int dp[100] = {0};
    dp[0] = 1;
    for(i=1; i<len; i++){
        max = 0;//��С���Ȳ���С��1���������ǰ��û�бȵ�ǰarr[i]С�ģ���dp[i] Ϊ 1��Ҳ��ʾΪmax+1
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
/* �汾�� �Ż������ֵ���� ���� nlogn */
/*
����:   10 3 4 1 7 5 6 8 9
���:   3  4 5 8 9
dp[0] = 1 aux[0] = 10
dp[1] = 3 aux[]
*/
void lis2(int* arr, int len){
    int i,j,max;
    int dp[100] = {0};
    dp[0] = 1;
    for(i=1; i<len; i++){
        max = 0;//��С���Ȳ���С��1
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
