#include <stdio.h>
#include <stdlib.h>
/* ��̬�滮 floyd���·�� */
#define INT_MAX 99999

void floyd_warshall(int map[4][4], int n){
    int i,j,k;
    int dp[10][10];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            dp[i][j] = map[i][j];
    for(k=0; k<n; k++)                          //��Ҫע����ǣ�k��ѭ������������Χ
        for(i=0; i<n; i++)                      //���k�����ڲ��Ļ������ᵼ����ֵ���磬�𰸴���
            for(j=0; j<n; j++)
                if(dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

    for(i=0; i<4; i++){
        for(j=0; j<4; j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }
}

int main(){
    int map[4][4] = {0, 2,6, 4,
                    INT_MAX,0,3,INT_MAX,
                     7,INT_MAX,0, 1,
                     5,INT_MAX,12,0};
    floyd_warshall(map, 4);


    return 0;
}
