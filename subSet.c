#include <stdio.h>
#include <stdlib.h>
/* 回溯，求集合abcd的子集*/

char *str = "abcd";
int x[4];
void backTrack(int i, int n){
    if(i >= n){
        int j;
        for(j=0; j<n; j++){
            if(x[j] == 1)
                printf("%c ", str[j]);
        }
        printf("\n");
    }else{
        x[i] = 1;
        backTrack(i+1, n);
        x[i] = 0;
        backTrack(i+1, n);
    }
}

int main(){
    backTrack(0, 4);
    return 0;
}
