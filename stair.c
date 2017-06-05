#include <stdio.h>
#include <stdlib.h>
/* 回溯，台阶一步或两步*/

int x[100];
int cnt = 0;
void backTrack(int i, int n){
    int j;
    if(cnt == n){
        for(j=0; j<i; j++)
            printf("%d ", x[j]);
        printf("\n");
    }else if(cnt > n){
        return;
    }else{
        cnt += 1;
        x[i] = 1;
        backTrack(i+1, n);
        cnt -= 1;
        x[i] = 0;

        cnt += 2;
        x[i] = 2;
        backTrack(i+1, n);
        cnt -= 2;
        x[i] = 0;

    }
}

int main(){
    backTrack(0, 3);
    return 0;
}
