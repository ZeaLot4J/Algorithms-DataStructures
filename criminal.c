#include <stdio.h>
#include <stdlib.h>
/* ���鼯���ҷ������� */

void init(int* arr, int len){
    int i;
    for(i=0; i<len; i++)
        arr[i] = i;
}

/* ȡ��ĳ���ﷸ������ */
int getRoot(int a, int *arr){
    if(arr[a] == a)
        return a;
    return getRoot(arr[a], arr);
}


/* ������ߵ��ﷸ */
void mergeTree(int a, int b, int *arr){
    int l = getRoot(a, arr);
    int r = getRoot(b, arr);
    arr[r] = l;
}
int main(){
    int m, n;//m���ﷸ����
            //n����������
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
