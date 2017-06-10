#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 求一个数组中第K大的数，先将前K个数生成一个最小堆，再把后面的数一一和堆顶元素比较，
小的跳过，大的替换，每次替换后都从堆顶向下调整，时间复杂度nlogn */

//产生小顶堆的策略
int asc(const void *a, const void *b){
    return *((int*)a) - *((int*)b);
}
//产生大顶堆的策略
int desc(const void *a, const void *b){
    return *((int*)b) - *((int*)a);
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
//小顶堆
/*
           5
       3      8
     6   9  2   4
    1 7
*/
static void siftDown(int *heap, int len, int root, int(*compare)(void *a, void *b)){
    if(root < 1){
        printf("ArrayIndexOutOfBoundsException");
        exit(-1);
    }
    while((root<<1) <= len){
        int index = root;
        //如果根比左边大，则index指向左边
        //否则index仍然指向根
        if(compare(&heap[index], &heap[root<<1]) > 0)
            index = root<<1;

        //如果有右结点且，如果index比右边大，则指向右边
        if((root<<1|1)<=len && compare(&heap[index], &heap[root<<1|1]) > 0)
            index = root<<1|1;

        //如果index没有变化，则不用交换，退出
        if(index != root){
            swap(&heap[index], &heap[root]);
            root = index;
        } else
            break;
    }
}
//小顶堆
static void siftUp(int *heap, int len, int curr, int(*compare)(void *a, void *b)){
    if(curr < 1 || curr > len){
        printf("ArrayIndexOutOfBoundsException");
        exit(-1);
    }
    int root;
    while(1 < curr){
        root = curr >> 1;
        //如果当前结点比根小，则与根结点交换数值
        if(compare(&heap[root], &heap[curr]) > 0){
            swap(&heap[root], &heap[curr]);
        }else
            break;
        curr = root;
    }
}
//将一个数组转换成一个小顶堆
static void createHeap(int *heap, int len, int(*compare)(void *a, void *b)){
    int root = len >> 1;
    while(root >= 1){
        siftDown(heap, len, root, compare);
        root--;
    }
}


int main(){
    int arr[10] = {0, 5, 3, 8, 1, 9, 2, 4, 6, 7};
    //将数组改造成一个堆，策略自行指定
    //createHeap(arr, 9, desc);
    //int i;
    //for(i=1; i<10; i++){
    //    printf("%d ", arr[i]);
    //}

    //求第4大的数
    int heap[5] = {0};
    int i;
    //先生成一个大小为4的小顶堆
    for(i=1; i<=4; i++){
        heap[i] = arr[i];
    }
    createHeap(heap, 4, asc);//O(n)
    for(i=5; i<10; i++){
        if(arr[i] > heap[1]){
            heap[1] = arr[i];
            siftDown(heap, 4, 1, asc);
        }
    }

    printf("第四大的数为:%d\n", heap[1]);
    printf("第三大的数为:%d\n", heap[2]);
    printf("第二大的数为:%d\n", heap[3]);
    printf("第一大的数为:%d\n", heap[4]);

    return 0;
}
