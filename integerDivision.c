#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 递归 */
int integerDivision(int n, int m){
    if(n == 1)  return 1;
    if(m == 1)  return 1;
    if(n <= m)  return 1 + integerDivision(n, n-1);
    if(m > 1 && m < n)  return integerDivision(n-m, m) + integerDivision(n, m-1);
}
/* 动态规划，以空间换时间，耗时骤减 */
int integerDivision2(int ival){
    //下标从1开始
    int dp[120][120], i, j;
    memset(dp, 0, sizeof(int));
    for(i=1; i<ival+1; i++){
        dp[1][i] = 1;
        dp[i][1] = 1;
    }

    for(i=2; i<ival+1; i++){
        for(j=2; j<ival+1; j++){
            if(i <= j)  dp[i][j] = 1 + dp[i][i-1];
            if(j > 1 && j < i)  dp[i][j] = dp[i-j][j] + dp[i][j-1];
        }
    }
    return dp[ival][ival];
}
int main(){
    int n;
    while(scanf("%d", &n)!=EOF)
        printf("%d\n",integerDivision2(n));
    return 0;
}

/*


6
5+1
4+2 4+1+1
3+3 3+2+1 3+1+1+1
2+2+1+1 2+2+2 2+1+1+1
1+1+1+1+1+1

q(n,m) 1<m<n
表示整数n划分中，最大加数不超过m的划分种类数
(1)、如果最大加数等于m的情况，则
比如m=4,则剩下的划分组合的和肯定为6-4=2，即接下来求整数2的划分种类数，其最大加数最多也只能是4(降成2)
比如m=2,则剩下的划分组合的和肯定为6-2=4，即接下来求整数4的划分种类数，其最大加数最多也只能是2(因为前面已经说了最大加数等于2)
所以可以得出q(n,m) = q(n-m, m)

(2)、如果最大加数不会为m的情况，则
比如m=4,则最大加数应该<4,即最大加数不会超过4-1=3，那么接下来继续求整数6的划分种类数，其最大加数不超过3
所以可以得出q(n,m) = q(n, m-1)
*/
