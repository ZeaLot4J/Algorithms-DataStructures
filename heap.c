#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define SIZE 10000
/* �ѵ��㷨 */
int heap[SIZE];//�±��1��ʼ��
int size = 0;
//���µ���           //��Ҫ���µ�����Ԫ���±�
static void siftDown(int topIndex){//ʱ�临�Ӷ�O(log(n))
    int t, index;
    while(topIndex*2 <= size){//ֻҪ�����Ӿ���
        if(heap[topIndex] > heap[topIndex*2])
            index = topIndex * 2;
        else
            index = topIndex;

        if(topIndex*2+1 <= size){//������Һ��ӵĻ�
            if(heap[index] > heap[topIndex*2+1])//����Һ��ӻ�Ҫ��С�Ļ�
                index = topIndex * 2 + 1;
        }
        if(index == topIndex) break;//����������

        t = heap[topIndex];
        heap[topIndex] = heap[index];
        heap[index] = t;
        topIndex = index;
    }
}
static void siftUp(int index){//ʱ�临�Ӷ�O(log(n))
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
β������ logn�������ѭ����offer������һ���ѣ�����ʱ�临�Ӷ�Ϊnlogn
���ֱ�ӽ�һ������ת���ɶѣ�������ķ������Խ���n
*/
static void offer(int value){
    heap[++size] = value;
    siftUp(size);
}
/* ֱ�ӽ�����ת�ɶ� ʱ�临�Ӷ�Ϊn(֤���Ƚϸ���)�������һ����Ҷ��㿪ʼsiftDown */
static void convertArrayToHeap(int* arr, int len){
    size = 0;//��ȫ��heap���
    int i;
    for(i=0; i<len; i++){
        heap[i+1] = arr[i];
        size++;
    }
    for(i=len/2; i>=1; i--){
        siftDown(i);
    }

}
/* �ײ�ɾ�� logn*/
static int poll(){
    if(size==0) return -1;
    //�ײ���β������
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
������˼·�� ����һ���ѣ�������һ���ѽ��ж��������Ч����
�������һ��Ԫ����Ѷ�Ԫ�ؽ������ѳ��ȼ�һ���ٶԶѶ�Ԫ��siftDown
С����������֮����ɴ󶥶ѣ�vice versa
 nlogn
 */
static void heapSort(){
    int t;
    int tempSize = size;//�Ȱ�size����һ��
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
        printf("1.���β��Ԫ��\n");
        printf("2.ɾ���ײ�Ԫ��\n");
        printHeap();
        scanf("%d", &i);
        switch(i){
        case 1:
            printf("������Ԫ��ֵ:");
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
