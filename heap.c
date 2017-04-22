#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SIZE 10000
/* 堆的算法 */
int heap[SIZE];//下标从1开始算
int size = 0;
//向下调整           //需要向下调整的元素下标
static void siftDown(int topIndex){//时间复杂度O(log(n))
    int t, index;
    while(topIndex*2 <= size){//只要有左孩子就行
        if(heap[topIndex] > heap[topIndex*2])
            index = topIndex * 2;
        else
            index = topIndex;

        if(topIndex*2+1 <= size){//如果有右孩子的话
            if(heap[index] > heap[topIndex*2+1])//如果右孩子还要更小的话
                index = topIndex * 2 + 1;
        }
        if(index == topIndex) break;//如果无需调整

        t = heap[topIndex];
        heap[topIndex] = heap[index];
        heap[index] = t;
        topIndex = index;
    }
}
static void siftUp(int index){//时间复杂度O(log(n))
    int i, t;
    while(index != 1){
        int rootIndex = index / 2;
        if(heap[index] < heap[rootIndex]){
            t = heap[index];
            heap[index] = heap[rootIndex];
            heap[rootIndex] = t;
            index = rootIndex;
        }else{
            break;
        }
    }
}

/*
尾部插入 logn，如果用循环用offer来创建一个堆，则总时间复杂度为nlogn
如果直接将一个数组转换成堆，用下面的方法可以降到n
*/
static void offer(int value){
    heap[++size] = value;
    siftUp(size);
}
/* 直接将数组转成堆 时间复杂度为n(证明比较复杂)，从最后一个非叶结点开始siftDown */
static void convertArrayToHeap(int* arr, int len){
    size = 0;//把全局heap清空
    int i;
    for(i=0; i<len; i++){
        heap[i+1] = arr[i];
        size++;
    }
    for(i=len/2; i>=1; i--){
        siftDown(i);
    }

}
/* 首部删除 logn*/
static int poll(){
    if(size==0) return -1;
    //首部和尾部交换
    int t = heap[1];
    heap[1] = heap[size];
    heap[size] = t;
    size--;
    siftDown(1);
    return heap[size+1];
}
static void printHeap(){
    int i;
    for(i=1; i<=size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

/*
堆排序思路是 对于一个堆（必须是一个堆进行堆排序才有效），
将其最后一个元素与堆顶元素交换，堆长度减一，再对堆顶元素siftDown
小顶堆排完序之后会变成大顶堆，vice versa
 nlogn
 */
static void heapSort(){
    int t;
    int tempSize = size;//先把size保存一下
    while(size>=1){
        t = heap[size];
        heap[size] = heap[1];
        heap[1] = t;
        size--;
        siftDown(1);
    }
    size = tempSize;
}
int main(){
    int i;
    int arr[] = {5,3,7,1,9,2,6,4,8};
    convertArrayToHeap(arr, 9);
    printHeap();
    heapSort();
    printHeap();
    while(1){
        system("cls");
        printf("1.添加尾部元素\n");
        printf("2.删除首部元素\n");
        printHeap();
        scanf("%d", &i);
        switch(i){
        case 1:
            printf("请输入元素值:");
            scanf("%d", &i);
            offer(i);
            break;
        case 2:
            poll();
            break;
        default:
            break;
        }
    }
    return 0;
}
