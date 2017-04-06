/*
    最大子段和
*/
#include <stdio.h>
#include <malloc.h>

int max(int a,int b){
    return a>b?a:b;
}
/* 方法一 暴力*/
//int maxSubSum(int *a, int len, int *besti, int *bestj){ //-2 11 -4 13 -5 -2
//    int i,j, maxSum = 0;
//    for(i=0; i<len; i++){
//        int sum = 0;
//        for(j=i; j<len; j++){
//            sum += a[j];
//            if(sum > maxSum){
//                maxSum = sum;
//                *besti = i;
//                *bestj = j;
//            }
//        }
//    }
//    return maxSum;
//}
/* 动态规划
a[]
-2 11 -4 13 -5 -2

b[j] 表示以a[j]为最终元素的子段中的和最大的那个子段的和
比如最终元素为13时，以13为最终元素的子段有{-2,11,-4,13}=18,{11,-4,13}=20,{-4,13}=9,{13}=13
其中和最大的子段为{11,-4,13}=20，
所以b[3] = 20
那么b[2] = 7
同理b[1] = 11
	b[0] = 0
如果b[j-1]>0，则b[j]=b[j-1]+a[j]
否则，则b[j]=0
可得递推式b[j] = max(b[j-1] + a[j] , a[j])
*/
int maxSubSum(int *a, int len, int *besti, int *bestj){
    int *b = (int*)malloc(len*sizeof(int));

    int i, sum=0;
    if(a[0]<0){
        b[0] = 0;
    }else{
        b[0] = a[0];
    }
    for(i=1; i<len; i++){
        b[i] = max(b[i-1]+a[i], a[i]);
    }
    //找出b中的最大的元素
    for(i=0; i<len; i++){
        if(b[i] > sum){
            sum = b[i];
        }
    }
    return sum;
}
/* 上面算法的简化 */
int maxSubSum2(int *a, int len, int *besti, int *bestj){
    int b,sum,i;
    b = sum = 0;
    for(i=0; i<len; i++){
        if(b > 0){
            b += a[i];
        }else{
            b = a[i];
        }
        if(b > sum){
            sum = b;
        }
    }
    return sum;
}
int main(){
    int n;
    printf("请输入整数序列长度:");
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));

    printf("请输入%d个整数的序列:", n);
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int besti, bestj;
    int len = maxSubSum2(a, n, &besti, &bestj);
    printf("最大子段下标为%d到%d，和为%d\n", besti,bestj, len);
    return 0;
}
