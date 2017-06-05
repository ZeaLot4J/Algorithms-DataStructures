#include <stdio.h>
#include <stdlib.h>
/* »ØËÝ£¬°Ë»Êºó */
int flag[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int cnt = 0;
void printBoard(){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<flag[i]; j++)
            printf("0");
        printf("*");
        for(j=flag[i]+1; j<8; j++)
            printf("0");
        printf("\n");
    }
    printf("\n");
    cnt++;
}

int check(int row){
    int i;
    for(i=0; i<row; i++)
        if(flag[i]==flag[row] || abs(i-row)==abs(flag[i]-flag[row]))
            return 0;
    return 1;
}

void backTrack(int row){
    if(row >= 8)
        printBoard();
    else{
        int col;
        for(col=0; col<8; col++){
            flag[row] = col;
            if(check(row)==1){
                backTrack(row+1);
            }
            flag[row] = -1;
        }
    }

}

int main(){
    backTrack(0);
    printf("%d\n", cnt);
    return 0;
}
