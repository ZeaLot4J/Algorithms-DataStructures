#include<iostream>

using namespace std;
//最后一个非叶结点是n/2-1

//堆的调整算法，大顶堆，最后是单独写一个函数
void heapAdjustLargeTop(int* ia,int index, int n){
    int t,maxIndex;
    while(1){
        if(index*2<n){//如果有左孩子结点
            maxIndex = ia[index]<ia[index*2]?index*2:index;
        }else{//没有左孩子则退出
            break;
        }
        if(index*2+1<n){// 如果有右孩子结点
            maxIndex = ia[maxIndex]<ia[index*2+1]?index*2+1:maxIndex;
        }
        if(index!=maxIndex){//如果最大数的下标不是自己
            t = ia[index];
            ia[index] = ia[maxIndex];
            ia[maxIndex] = t;
            index = maxIndex;
        }else{
            break;
        }
    }
}
void heapAdjustLittleTop(int* ia,int index, int n){
    int t,minIndex;
    while(1){
        if(index*2<n){//如果有左孩子结点
            minIndex = ia[index]>ia[index*2]?index*2:index;
        }else{//没有左孩子则退出
            break;
        }
        if(index*2+1<n){// 如果有右孩子结点
            minIndex = ia[minIndex]>ia[index*2+1]?index*2+1:minIndex;
        }
        if(index!=minIndex){//如果最大数的下标不是自己
            t = ia[index];
            ia[index] = ia[minIndex];
            ia[minIndex] = t;
            index = minIndex;
        }else{
            break;
        }
    }
}
//建一个大顶堆
void createHeap(int* ia, int n){
    for(int i=n/2; i>0; i--){
        heapAdjustLargeTop(ia,i,n);
    }
}
void heapSort(int* ia, int n){
    int t,i = n;
    while(i>2){
        t = ia[i];
        ia[i] = ia[1];
        ia[1] = t;
        i--;
        heapAdjustLittleTop(ia,1,i);
    }
}
int main(){

//    int ia[100] = {0,99,5,36,7,22,17,46,12,2,19,25,28,1,92};
    int ia[100] = {0,1 ,2, 5, 7, 12, 17, 19, 22, 25, 28, 36, 46, 92, 99};
    int n = 14;
//    createHeap(ia,14);
    heapSort(ia,14);
    for(int i=1; i<=14; i++){
        cout << ia[i] << " ";
    }
    cout << endl;
    return 0;
}
