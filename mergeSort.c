#include <stdio.h>
#include <stdlib.h>

/* 归并排序 */

/* 合并两个有序段 两个有序段在同一个数组中的不同位置 */
void merge(int* a, int left, int mid, int right, int *c){
    int i = left, j = mid+1;
    int m = mid, n = right;
    int k=0;
    while(i<=m && j<=n){
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while(i<=m)
        c[k++] = a[i++];
    while(j<=n)
        c[k++] = a[j++];

    for(i=0; i<k; i++)
        a[left+i] = c[i];
}                                               //临时数组
void mergeSort0(int* arr, int left, int right, int* tmp){
    if(left < right){//最少要剩下两个元素
        int mid = (left + right) / 2;
        mergeSort0(arr, left, mid, tmp);
        mergeSort0(arr, mid+1, right, tmp);
        merge(arr, left, mid, right, tmp);
    }
}
void mergeSort(int* arr, int len){
    int* tmp = (int*)malloc(sizeof(int)*len);
    mergeSort0(arr, 0, len-1, tmp);
    free(tmp);
}
int main(){
    int arr[] = {5,3,9,8,2,7,6,1,4,10};
    mergeSort(arr, 10);
    int i;
    for(i=0; i<10; i++)
        printf("%d ", arr[i]);
    return 0;
}
