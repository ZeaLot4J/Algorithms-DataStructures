
/* 01背包问题

设dp[i][v]表示 此时前i件物品放入一个容量还剩v的背包中可以获得最大价值
向前倒退一步
对于第i-1件物品，其表示可能有两种情况
1、当第i件物品没有放入时，则放入第i-1件物品之后背包剩余容量应该和放入第i件物品后的背包剩余容量相同
    为v，所以为dp[i-1][v]，价值也应该是和dp[i][v]相等的。
2、当第i件物品放入时，则放入第i-1件物品之后背包剩余容量应该比放入第i件物品后的背包剩余容量多了c[i]
    所以为dp[i-1][v-c[i]]，价值应该是比dp[i][v]少了第i件物品的价值
所以综上所述，dp[i][v]可以表示为dp[i-1][v] 和 dp[i-1][v-c[i]]+w[i] 其价值较大的那个
即 dp[i][v] = max(dp[i-1][v], dp[i-1][v-c[i]]+w[i]);
当v=0时，dp[i][0]结果肯定为0，因为背包容量为0的话，放不了任何东西，价值肯定为0
当i=0时，dp[0][v] = max(w[0],0)，为第0件物品的价值或0中的较大者



观察dp[i][j] = max{dp[i-1][j], dp[i-1][j-c[i]]+w[i]}
第i行第j列只与i-1行第j列和i-1行v-c[i]列有关，
即本行只与上一行有关，所以可以只用一个一维数组保存第i-1行的各列值，到了i行之后，用原数组的相关值
来推i行的各列值，然后覆盖原数组，以达到节省空间的目的
状态转移方程变为:   dp[j] = max(dp[j], dp[j-c[i]]+w[i])
要注意的是：此处的j要从后往前递减，因为dp[j]的值是和dp[j-c[i]]有关，而j-c[i]<j，也就是说
如果j从左往右递增的话，dp[j]的值由左边的值推出，dp[j+n]的值也会由左边的值推出，而此时左边的值已经
被dp[j]及其左边的值给覆盖了
*/
/* 动态规划 */
#include<stdio.h>
#include<string.h>

#define N 1010
#define max(a,b) (a)>(b)?(a):(b)

int dp[N][N];
int n, m;
int w[N], c[N];

//void bag01(){
//    int t;
//    scanf("%d", &t);
//    while (t--){
//        memset(dp, 0, sizeof(dp));
//        memset(w, 0, sizeof(w));
//        memset(c, 0, sizeof(c));
//        scanf("%d%d", &n, &m);
//        int i,j;
//        for (i = 1; i <= n; i++)
//            scanf("%d", &w[i]);
//        for (i = 1; i <= n; i++)
//            scanf("%d", &c[i]);
//        for (i = 1; i <= n; i++){
//            for (j = 0; j <=m; j++){
//                if (j - c[i] >= 0)
//                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
//                else
//                    dp[i][j] = dp[i - 1][j];
//            }
//        }
//        for(i=0; i<=n; i++){
//            for(j=0; j<=m; j++)
//                printf("%d ", dp[i][j]);
//            printf("\n");
//        }
//        printf("%d\n", dp[n][m]);
//    }
//}
void bag01(){
    int dp[N];
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
            for (j = m; j >= 0; j--){
                if(j-c[i] >= 0)
                    dp[j] = max(dp[j], dp[j-c[i]]+w[i]);
            }
        }
        for(i=0; i<=m; i++)
            printf("%d ", dp[i]);
        printf("\n");
        printf("%d\n", dp[m]);
    }
}


int main()
{
    bag01();
    return 0;
}

/*
1
6 10
5 6 5 1 19 7
2 3 1 4 6 5
*/
