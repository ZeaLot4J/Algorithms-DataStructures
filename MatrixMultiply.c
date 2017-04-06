#include <stdio.h>


/*===================================
动态规划：矩阵连乘
===================================*/
const int INF = 999;
int memo[100][100];
int s[100][100];

//递归
int bestMatrixChain(int p[], int left, int right){
    if(left==right){
        return 0;
    }
    int k,count,min=INF;
    for(k=left; k<=right-1; k++){//k是分隔点
        count = 0;
        if(memo[left][k]==0){
            memo[left][k] =  bestMatrixChain(p, left, k);
        }
        count += memo[left][k];
        if(memo[k+1][right]==0){
           memo[k+1][right] =  bestMatrixChain(p, k+1, right);
        }
        count += memo[k+1][right];
        count += p[left-1]*p[k]*p[right];

        if(min > count){
            min = count;
            s[left][right] = k;
        }
    }
    return min;
}

/*
    迭代
    矩阵连乘动态规划：求数乘次数最少的矩阵链
    m[i][j]：      表示矩阵i到矩阵j的矩阵链 最少的数乘次数
    p数组：        存放矩阵的行数其中p[i-1]和p[i]表示矩阵i的行数和列数， (1<=i<=n)
    n：            表示p数组的长度
*/
void matrixChain(int** m, int* p, int n){
    int i;
    for(i=1; i<=n; i++){
        m[i][i] = 0;
    }

    int len,j,k, min=INF;
    for(len=2;len<=n;len++){
        for(i=1; i<=n-len+1; i++){
            j = len+i-1;
            for(k=i; k<j; j++){
                int count = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(min > count){
                    min = count;
                }
            }
            m[i][j] = min;
        }
    }
}


/*
    矩阵相乘算法
*/
void matrixMultiply(int a[][2], int b[][3], int c[][3], int ar, int ac, int br, int bc){
    if(ac != br){
        printf("不可乘\n");
    }
    int sum = 0,i,j,k;
    for(i=0; i<ar; i++){
        for(j=0; j<bc; j++){
            for(k=0; k<ac; k++){
                sum += a[i][k]*b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
}

int main(){
//    int a[][2] = {1,4,
//                   2,5,
//                   3,6};
//    int ar = 3, ac = 2;
//    int b[][3] = {1,2,3,
//                   4,5,6};
//    int br = 2, bc = 3;
//    int c[3][3];
//    matrixMultiply(a,b,c,ar,ac,br,bc);
//    int i,j;
//    for(i=0; i<3; i++){
//        for(j=0; j<3; j++){
//            printf("%d ", c[i][j]);
//        }
//        printf("\n");
//    }
    const int N = 5;
    int p[] = {3,2,4,3,5};
    int m[10][10];
    int result = bestMatrixChain(p, 1 ,4);

    printf("%d\n", result);
    int i,j;
    for(i=1; i<=4; i++){
        for(j=1; j<=4; j++){
            if(i!=j && i<j){
                printf("A%d~A%d, A%d~A%d\n", i,s[i][j], s[i][j]+1,j);
            }
        }
    }

    return 0;
}//A1((A2A3)A4)
