/*
    最大子矩阵
*/
#include <stdio.h>
#include <stdlib.h>
/*
如果matrix[rStart~rEnd][cStart~cEnd]的和最大
那么在rStart和rEnd已经确定的情况下，这rStart-rEnd行中，列号从cStart到cEnd的元素之和肯定也是最大的
详细过程请看课本P57
*/
/* 最大子段和算法*/
int maxSubSum(int *a, int len){
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
/* 最大子矩阵和算法 */
int maxSubMatrix(int **matrix, int r, int c){
    int i,j,k,sum=0, max;
    int b[c];       //表示几行之间每一列的和
    for(i=0; i<r; i++){//对于每一行
        memset(b,0,sizeof(b));//将b清零
        for(j=i; j<r; j++){
            for(k=0; k<c; k++){
                b[k] += matrix[j][k];
            }
            max = maxSubSum(b, c);
            if(max > sum){
                sum = max;
            }
        }
    }
    return sum;
}
/* 求一个矩阵的元素之和 */
//int matrixSum(int **matrix, int rStart, int rEnd, int cStart, int cEnd){
//    int i,j,sum=0;
//    for(i=rStart; i<=rEnd; i++){
//        for(j=cStart; j<=cEnd; j++){
//            sum += matrix[i][j];
//        }
//    }
//    return sum;
//}

/* 暴力 */
//int maxSubMatrix(int **matrix, int r, int c){
//    int sum=0,mSum;
//    int rStart, cStart;
//    int rEnd, cEnd;
//    for(rStart=0; rStart<r; rStart++){
//        for(rEnd=rStart; rEnd<r; rEnd++){
//            for(cStart=0; cStart<c; cStart++){
//                for(cEnd=cStart; cEnd<c; cEnd++){
//                    mSum = matrixSum(matrix, rStart, rEnd, cStart, cEnd);
//                    if(mSum > sum){
//                        sum = mSum;
//                    }
//                }
//            }
//        }
//    }
//    return sum;
//}
/* 根据行列数生成矩阵 */
int** createMatrix(int r, int c){
    int i,j;
    int **matrix = NULL;
    matrix = (int*)malloc(r*sizeof(int*));
    for(i=0; i<r; i++){
        matrix[i] = (int)malloc(c*sizeof(int));
    }
    printf("请输入矩阵:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}
int main(){
    int r,c;
    printf("请输入矩阵的行:");
    scanf("%d", &r);
    printf("请输入矩阵的列:");
    scanf("%d", &c);
    int **matrix = createMatrix(r,c);
    int sum = maxSubMatrix(matrix, r, c);
    printf("最大和为:%d",sum);
    return 0;
}
