#include <stdio.h>
#include <stdlib.h>
/* 并查集，找犯罪团体 */

void init(int* arr, int len){
    int i;
    for(i=0; i<len; i++)
        arr[i] = i;
}

/* 取得某个罪犯的首领 */
int getRoot(int a, int *arr){
    if(arr[a] == a)
        return a;
    return getRoot(arr[a], arr);
}


/* 归属左边的罪犯 */
void mergeTree(int a, int b, int *arr){
    int l = getRoot(a, arr);
    int r = getRoot(b, arr);
    arr[r] = l;
}
int main(){
    int m, n;//m是罪犯人数
            //n是线索数量
    scanf("%d", &m);
    int *arr = (int*)malloc(m*sizeof(int));
    init(arr, m);
    int i, a, b;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        mergeTree(a, b, arr);
    }

    int cnt = 0;
    for(i=0; i<m ; i++){
        if(arr[i] == i)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
