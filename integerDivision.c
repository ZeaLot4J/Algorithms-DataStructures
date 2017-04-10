#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* �ݹ� */
int integerDivision(int n, int m){
    if(n == 1)  return 1;
    if(m == 1)  return 1;
    if(n <= m)  return 1 + integerDivision(n, n-1);
    if(m > 1 && m < n)  return integerDivision(n-m, m) + integerDivision(n, m-1);
}
/* ��̬�滮���Կռ任ʱ�䣬��ʱ��� */
int integerDivision2(int ival){
    //�±��1��ʼ
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
��ʾ����n�����У�������������m�Ļ���������
(1)���������������m���������
����m=4,��ʣ�µĻ�����ϵĺͿ϶�Ϊ6-4=2����������������2�Ļ����������������������Ҳֻ����4(����2)
����m=2,��ʣ�µĻ�����ϵĺͿ϶�Ϊ6-2=4����������������4�Ļ����������������������Ҳֻ����2(��Ϊǰ���Ѿ�˵������������2)
���Կ��Եó�q(n,m) = q(n-m, m)

(2)���������������Ϊm���������
����m=4,��������Ӧ��<4,�����������ᳬ��4-1=3����ô����������������6�Ļ�������������������������3
���Կ��Եó�q(n,m) = q(n, m-1)
*/
