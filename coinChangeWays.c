#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* 找零方案数问题 */
/* 递归 从最大面值开始找起，倒推，有两种情况，不使用当前面值，和使用了当前面值
    递推式为 f(m,n) = f(m-1, n) + f(m, n-coinValue[m]) ,其中m为面值数组的下标，从最大开始，
                                                        n为剩余要找的钱数，会逐渐变小
 */
int count( int S[], int m, int n )
{
    // 如果n为0，钱已经凑完
    if (n == 0)
        return 1;
    if (n < 0)//凑出来的钱数过大，没有正好凑满
        return 0;
    // 没有硬币可用了，也返回0
    if (m <=0 )
        return 0;
    // 按照上面的递归函数
                //从最大的面值开始
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}
/* 动态规划求解
    递推式为 dp[n][m] = dp[n][m-1] + dp[n-coinValue[m]][m]
    本来应该表示成dp[m][n]，但是dp[n][m]可以方便后续的优化
 */
long count2(int *coinValue, int m, int n){
    int i,j;
    long dp[n+1][m];//因为有n这一行，所以要+1
    //n为0表示满足方案，
    for(j=0; j<m; j++){
        dp[0][j] = 1;
    }

    for(j=0; j<m; j++){
        for(i=1; i<=n; i++){
            long a = j>0?dp[i][j-1]:0;
            long b = i-coinValue[j]>=0?dp[i-coinValue[j]][j]:0;    //防止下标变成负数
            dp[i][j] = a + b;
        }
    }
    return dp[n][m-1];
}
/* 动态规划优化 */
long count3(int *coinValue, int m, int n) {
    long dp[n+1],i,j;
    memset(dp, 0, sizeof(dp));
    //初始化基本情况
    dp[0] = 1;

    for(i=0; i<m; i++)
        for(j=coinValue[i]; j<=n; j++)
            dp[j] += dp[j-coinValue[i]];

    return dp[n];
}
int compDesc(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}
int main()
{
    int i,j,m, n;
    scanf("%d", &n);
    scanf("%d", &m);
    int *coinValue = (int*)malloc(m*sizeof(int));
    for(i=0; i<m; i++){
        scanf("%d", &coinValue[i]);
    }
    qsort(coinValue, m, sizeof(int), compDesc);//应该将面值按从大到小排好
    printf("%ld", count3(coinValue, m, n));
    return 0;
}
