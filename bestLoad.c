#include <stdio.h>
#include <stdlib.h>
/* ̰�� ����װ��(���Ҫ���ԭ���������ŵĻ�����Ҫ�ٿ�һ�������¼�±�) */
typedef struct Thing{
    int weight;
    int price;
}Thing;

static int asc(int* a, int* b){
    return *a - *b;
}

void greedySelect(int *weight, int len, int *flag, int load){
    int i;
    for(i=0; i<len; i++){
        if(weight[i] > load)
            break;
        load -= weight[i];
        flag[i] = 1;
    }
}

int main(){
    int weight[4] = {20, 10, 26, 15};// 10 15 20 26
    int load = 70;
    qsort(weight, 4, sizeof(int), asc);
    int flag[100] = {0};
    greedySelect(weight, 3, flag, load);
    int i;
    for(i=0; i<4; i++){
        if(flag[i] == 1)
            printf("%d ", i);
    }
    return 0;
}
