#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 回溯法解决01背包 */
int price[6] = {5, 6, 5, 1, 19, 7};
int weight[6] = {2, 3, 1, 4, 6, 5};
int x[6];
int max = 0;
int sum = 0;
void backTrack(int i, int maxWeight){//i从0开始,最大容量为10
    if(i>=6){
        max = sum > max ? sum : max;
        return;
    }

    if(weight[i] <= maxWeight){
        x[i] = 1;
        sum += price[i];
        backTrack(i+1, maxWeight-weight[i]);
        sum -= price[i];

        x[i] = 0;
        backTrack(i+1, maxWeight);
    }else{
        x[i] = 0;
        backTrack(i+1, maxWeight);
    }
}
//void backTrack(int i, int maxWeight){//i从0开始,最大容量为10
//    if(i>=6){
//        int j, sum = 0;
//        for(j=0; j<6; j++){
//            if(x[j] == 1) sum += price[j];
//        }
//        if(sum > max) max = sum;
//        return;
//    }
//
//    if(weight[i] <= maxWeight){
//        x[i] = 1;
//        backTrack(i+1, maxWeight-weight[i]);
//
//        x[i] = 0;
//        backTrack(i+1, maxWeight);
//    }else{
//        x[i] = 0;
//        backTrack(i+1, maxWeight);
//    }
//}

int main(){
    backTrack(0, 10);
    printf("%d\n", max);
    return 0;
}
