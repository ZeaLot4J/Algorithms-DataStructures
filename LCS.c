#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
int longest[MAXSIZE][MAXSIZE];      //公共子序列最长长度
int dp[MAXSIZE][MAXSIZE];         //str1[i]==str2[j]相同字符记录为1，
char str1[MAXSIZE];                 //否则，若longest[i-1][j] >= longest[i][j-1]，则记为2
char str2[MAXSIZE];                 //否则，若longest[i][j-1] >= longest[i-1][j]，则记为3

int max(int a, int b)
{
    return a > b ? a : b;
}

/*
    用递归做
*/
//int lcslen(int i, int j)
//{
//    if(i==0 || j==0)
//    {
//        return 0;
//    }
//    else
//    {
//        if(str1[i-1] == str2[j-1])
//        {
//            return lcs(i-1, j-1) + 1;
//        }
//        else
//        {
//            return max(lcs(i-1, j), lcs(i, j-1));
//        }
//    }
//}

/*
    用迭代做，要点是把已知的值预先填入数组中，为后面值的产生做迭代
*/
void lcslen(int len1, int len2)
{
    int i,j;
    //第一行和第一列初始化为0
    for(i=0; i<len1+1; i++)
    {
        longest[i][0] = 0;
    }
    for(j=0; j<len2+1; j++)
    {
        longest[0][j] = 0;
    }

    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                longest[i][j] = longest[i-1][j-1] + 1;
                dp[i][j] = 1;
            }
            else
            {
                if(longest[i-1][j] >= longest[i][j-1])
                {
                    longest[i][j] = longest[i-1][j];
                    dp[i][j] = 2;
                }
                else
                {
                    longest[i][j] = longest[i][j-1];
                    dp[i][j] = 3;
                }
            }
        }
    }
}
void lcs(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }

    if(dp[i][j] == 1)
    {
        lcs(i-1, j-1);
        printf("%c",str2[j-1]);//或者str1[i-1]
    }
    else if(dp[i][j] == 2)
    {
        lcs(i-1, j);
    }
    else
    {
        lcs(i, j-1);
    }
}
int main()
{
    printf("请输入字符串1:");
    scanf("%s", str1);
    printf("请输入字符串2:");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    lcslen(len1, len2);
    printf("最长公共子序列的长度为:%d\n", longest[len1][len2]);
    lcs(len1, len2);

    printf("\n");
    int i,j;
    for(i=0; i<=len1; i++)
    {
        for(j=0; j<=len2; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
