#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
void numberTriangle(){
    int i,j, number[5][5] = {7,0,0,0,0,
                             3,8,0,0,0,
                             8,1,0,0,0,
                             2,7,4,4,0,
                             4,5,2,6,5};
    int dp[5][5] = {0};
    for(i=0; i<5; i++)
        dp[4][i] = number[4][i];
    for(i=3; i>=0; i--)
        for(j=0; j<=i; j++)
            dp[i][j] = number[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
    printf("最大和为:%d\n", dp[0][0]);
    printf("路径为:");
    for(i=0,j=0; i<5; i++){
        if(dp[i][j] < dp[i][j+1]) j += 1;
        printf("%d ", number[i][j]);
    }
}
int main(){
    numberTriangle2();
    return 0;
}
