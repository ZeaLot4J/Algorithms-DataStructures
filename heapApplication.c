#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ��һ�������е�K��������Ƚ�ǰK��������һ����С�ѣ��ٰѺ������һһ�ͶѶ�Ԫ�رȽϣ�
С������������滻��ÿ���滻�󶼴ӶѶ����µ�����ʱ�临�Ӷ�nlogn */

//����С���ѵĲ���
int asc(const void *a, const void *b){
    return *((int*)a) - *((int*)b);
}
//�����󶥶ѵĲ���
int desc(const void *a, const void *b){
    return *((int*)b) - *((int*)a);
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
//С����
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
        //���������ߴ���indexָ�����
        //����index��Ȼָ���
        if(compare(&heap[index], &heap[root<<1]) > 0)
            index = root<<1;

        //������ҽ���ң����index���ұߴ���ָ���ұ�
        if((root<<1|1)<=len && compare(&heap[index], &heap[root<<1|1]) > 0)
            index = root<<1|1;

        //���indexû�б仯�����ý������˳�
        if(index != root){
            swap(&heap[index], &heap[root]);
            root = index;
        } else
            break;
    }
}
//С����
static void siftUp(int *heap, int len, int curr, int(*compare)(void *a, void *b)){
    if(curr < 1 || curr > len){
        printf("ArrayIndexOutOfBoundsException");
        exit(-1);
    }
    int root;
    while(1 < curr){
        root = curr >> 1;
        //�����ǰ���ȸ�С���������㽻����ֵ
        if(compare(&heap[root], &heap[curr]) > 0){
            swap(&heap[root], &heap[curr]);
        }else
            break;
        curr = root;
    }
}
//��һ������ת����һ��С����
static void createHeap(int *heap, int len, int(*compare)(void *a, void *b)){
    int root = len >> 1;
    while(root >= 1){
        siftDown(heap, len, root, compare);
        root--;
    }
}


int main(){
    int arr[10] = {0, 5, 3, 8, 1, 9, 2, 4, 6, 7};
    //����������һ���ѣ���������ָ��
    //createHeap(arr, 9, desc);
    //int i;
    //for(i=1; i<10; i++){
    //    printf("%d ", arr[i]);
    //}

    //���4�����
    int heap[5] = {0};
    int i;
    //������һ����СΪ4��С����
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

    printf("���Ĵ����Ϊ:%d\n", heap[1]);
    printf("���������Ϊ:%d\n", heap[2]);
    printf("�ڶ������Ϊ:%d\n", heap[3]);
    printf("��һ�����Ϊ:%d\n", heap[4]);

    return 0;
}
