#include <stdio.h>
#include <stdlib.h>
/* 贪心 部分背包 */
typedef struct Thing{
    int weight;
    int price;
}Thing;

static int desc(Thing* a, Thing* b){
    return b->price*1.0/b->weight - a->price*1.0/a->weight;
}

float greedySelect(Thing *t, int len, int bag){
    int i, j;
    float priceSum = 0;
    for(i=0; i<len; i++){
        if(t[i].weight > bag){
            priceSum += t[i].price/t[i].weight * bag;
            break;
        }
        bag -= t[i].weight;
        priceSum += t[i].price;
    }
    return priceSum;
}

int main(){
    Thing t[3] = {10, 60,
                  20, 100,
                  30, 120};
    int bag = 50;
    qsort(t, 3, sizeof(Thing), desc);
    float priceSum = greedySelect(t, 3, bag);
    printf("%f\n", priceSum);
    return 0;
}
