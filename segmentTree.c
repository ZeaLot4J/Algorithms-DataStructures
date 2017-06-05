#include <stdio.h>
/* �߶��� */
#define SIZE 1000//�������
int segTree[SIZE];//�������ʾ��
int sum[SIZE*4];//���ĺ�
int lazy[SIZE*4];//�ӳٱ�� lazy propagation
/* �������Һ��Ӹ��µ�ǰ�����Ϣ�������Ǽ�¼�����ӽ��ĺ� */
void pushUp(int root){
    sum[root] = sum[root*2] + sum[root*2+1];
}
/* �����ӳٱ�� */
void pushDown(int root, int ln, int rn){//���Һ�������ʾ������εĳ���
    if(lazy[root] != 0){
        lazy[root*2] += lazy[root];
        lazy[root*2+1] += lazy[root];
        sum[root*2] += lazy[root] * ln;
        sum[root*2+1] += lazy[root] * rn;
        lazy[root] = 0;//��ձ��
    }
}
/* ���sum���� */
void createSegTree(int left, int right, int root){
    if(left >= right){
        sum[root] = segTree[left];
        return;
    }
    int mid = (left + right) / 2;
    createSegTree(left, mid, root*2);
    createSegTree(mid+1, right, root*2+1);
    pushUp(root);
}
/* ����һ��Ԫ�� */
void update(int left, int right, int root, int i, int newVal){
    if(left >= right){
        sum[root] += newVal;
        return;
    }
    int mid = (left + right) / 2;
    if(i <= mid)
        update(left, mid, root*2, i, newVal);
    else
        update(mid+1, right, root*2+1, i, newVal);
    pushUp(root);
}
/* ����һ�������Ԫ�� */
void rangeUpdate(int left, int right, int root, int uleft, int uright, int newVal){
    if(uleft<=left && uright>=right){
        sum[root] += (right-left+1) * newVal;
        lazy[root] += newVal;
        return;
    }
    int mid = (left + right) / 2;
    //pushDown(root, mid-left+1, right-mid+1);
    if(uleft <= mid)
        rangeUpdate(left, mid, root*2, uleft, uright, newVal);
    if(uright >= mid+1)
        rangeUpdate(mid+1, right, root*2+1, uleft, uright, newVal);
    pushUp(root);
}
/* ��ĳ������ĺ� */
int query(int left, int right, int root, int qleft, int qright){
    if(qleft<=left && qright>=right)
        return sum[root];
    int res = 0;
    int mid = (left + right) / 2;
    pushDown(root, mid-left+1, right-mid+1);
    if(qleft <= mid)
        res += query(left, mid, root*2, qleft, qright);
    if(qright >= mid+1)
        res += query(mid+1, right, root*2+1, qleft, qright);
    return res;
}
int main(){
    int n;
    scanf("%d", &n);
    int i;
    for(i=1; i<=n; i++)
        scanf("%d", &segTree[i]);
    createSegTree(1, n, 1);

    printf("%d\n", query(1, n, 1, 1, 5));

    rangeUpdate(1, n, 1,1, 3, 10);
    update(1,n,1, 4,1);
    printf("%d\n", query(1, n, 1, 1, 5));


    return 0;
}
