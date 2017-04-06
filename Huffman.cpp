#include <iostream>
#include <cstring>
using namespace std;

/*定义赫夫曼结点*/
typedef struct HuffmanTreeNode
{
    char data;
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;



void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int* w,int n)
{
    if(n<1) return;

    int m = 2 * n - 1;
    HT = new HTNode[m+1];

    cout << "请输入元素的值：";
    for(int i=1; i<=n; i++)
    {
        cin >> HT[i].data;
    }

    for(int i=1; i<=m; i++)
    {
        HT[i].weight = w[i-1];
        HT[i].parent = HT[i].rchild = HT[i].lchild = 0;
    }

    int min1, min2, index1, index2;
    for(int i=1; i<=n-1; i++)
    {
        min1 = min2 = 1000;
        index1 = index2 = 0;
        for(int j=1; j<n+i; j++)
        {
            if(HT[j].parent != 0) continue;
            if(HT[j].weight < min1)
            {
                min2 = min1;
                index2 = index1;
                min1 = HT[j].weight;
                index1 = j;
            }
            else if(HT[j].weight < min2)
            {
                min2 = HT[j].weight;
                index2 = j;
            }
        }
        HT[n+i].weight = HT[index1].weight + HT[index2].weight;
        HT[n+i].lchild = index1;
        HT[n+i].rchild = index2;
        HT[index1].parent = HT[index2].parent = n+i;
    }
    HC = new char*[n+1];
    char* hfcd = new char[n+1];
    int t, p, start;
    hfcd[n] = '\0';

    for(int i=1; i<=n; i++)
    {
        start = n;
        for(t=i,p=HT[t].parent;p!=0;t=p,p=HT[p].parent)
        {
            if(HT[p].lchild==t)
                hfcd[--start] = '0';
            else if(HT[p].rchild==t)
                hfcd[--start] = '1';
        }
        HC[i] = new char[n-start+1];
        strcpy(HC[i],&hfcd[start]);
    }
    delete[] hfcd;
}
int main()
{
    HuffmanTree HT = NULL;
    HuffmanCode HC = NULL;
    int* w = NULL;
    int n;

    cout << "请输入元素个数：";
    cin >> n;

    w = new int[n];
    cout << "请输入元素对应权值：";
    for(int i=0; i<n; i++)
    {
        cin >> w[i];
    }

    HuffmanCoding(HT,HC,w,n);
    for(int i=1; i<=n; i++)
    {
        cout << HT[i].data << "----";
        cout << HC[i] << endl;
    }
    return 0;
}
