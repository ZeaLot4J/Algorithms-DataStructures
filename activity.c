#include <stdio.h>
#include <stdlib.h>
/* 贪心 活动安排 */
typedef struct Activity{
    int start;
    int end;
}Activity;

static int asc(Activity* a, Activity* b){
    return a->end - b->end;
}

void greedySelect(Activity *ac, int len, int *flag){
    int i = 0, j;
    flag[i] = 1;
    for(j=1; j<len; j++){
        if(ac[j].start >= ac[i].end) {
            flag[j] = 1;
            i = j;
        }
    }
}

int main(){
    Activity ac[11] = {
                       3,5,
                       0,6,
                       5,7,
                       3,8,
                       5,9,
                       6,10,
                       1,4,
                       8,11,
                       8,12,
                       2,13,
                       12,14};
    qsort(ac, 11, sizeof(Activity), asc);
    int flag[100] = {0};
    greedySelect(ac, 11, flag);

    int i;
    for(i=0; i<11; i++)
        if(flag[i] == 1)
            printf("%d %d\n", ac[i].start, ac[i].end);
    return 0;
}
