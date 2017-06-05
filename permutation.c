#include <stdio.h>
#include <stdlib.h>
/* 回溯，1，2，3，4，5，6的全排列*/

#define n 6
int flag[n+1];
int x[n+1];
void backTrack(int i){
    int j;
    if(i > n){
        for(j=1; j<=n; j++)
            printf("%d ", x[j]);
        printf("\n");
    }else{
        for(j=1; j<=n; j++){
            if(flag[j]==0){
                flag[j] = 1;
                x[i] = j;
                backTrack(i+1);
                flag[j] = 0;
            }
        }
    }
}

int main(){
    backTrack(1);
    return 0;
}
