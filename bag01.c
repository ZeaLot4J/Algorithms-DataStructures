

/* 01背包问题

设f[i][v]表示 此时前i件物品放入一个容量还剩v的背包中可以获得最大价值
向前倒退一步
对于第i-1件物品，其表示可能有两种情况
1、当第i件物品没有放入时，则放入第i-1件物品之后背包剩余容量应该和放入第i件物品后的背包剩余容量相同
    为v，所以为f[i-1][v]，价值也应该是和f[i][v]相等的。
2、当第i件物品放入时，则放入第i-1件物品之后背包剩余容量应该比放入第i件物品后的背包剩余容量多了c[i]
    所以为f[i-1][v-c[i]]，价值应该是比f[i][v]少了第i件物品的价值
所以综上所述，f[i][v]可以表示为f[i-1][v] 中 f[i-1][v-c[i]]+w[i] 其价值较大的那个
即 f[i][v] = max(f[i-1][v], f[i-1][v-c[i]]+w[i]);
当v=0时，f[i][0]结果肯定为0，因为背包容量为0的话，放不了任何东西，价值肯定为0
当i=0时，f[0][v] = max(w[0],0)，为第0件物品的价值或0中的较大者
*/
/* 动态规划 */
#include<stdio.h>
#include<string.h>

#define N 1010
#define max(a,b) (a)>(b)?(a):(b)

int dp[N][N];
int n, m;
int w[N], c[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);
        int i,j;
        for (i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for (i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (i = 1; i <= n; i++){
            for (j = 0; j <=m; j++){
                if (j - c[i] >= 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for(i=0; i<=n; i++){
            for(j=0; j<=m; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}

/*
1
6 10
5 6 5 1 19 7
2 3 1 4 6 5
*/
