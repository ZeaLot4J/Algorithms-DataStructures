#include <iostream>
using namespace std;
/*结点*/
typedef struct Node
{
    int i;//非零元行下标
    int j;//非零元列下标
    int elem;//非零元值
    struct Node * right, * down;//指向右边下一个结点和指向下边下一个结点
}Node;
typedef struct
{
    Node ** rowHead, ** colHead;//头指针
    int rowNum;//行数
    int colNum;//列数
    int num;//非零元个数
}CrossList;

void createCrossMatrix(CrossList & matrix)
{
    cout << "请输入稀疏矩阵的行数、列数、非零元素的个数" << endl;
    cin >> matrix.rowNum >> matrix.colNum >> matrix.num;
                                //下标从1开始
    matrix.rowHead = new Node*[matrix.rowNum+1];//第一列为仅指针有用的头结点组
    matrix.colHead = new Node*[matrix.colNum+1];//第一行为仅指针有用的头结点组
    for(int i=1; i<=matrix.rowNum; i++)//把第一列的头结点全部指向NULL
        matrix.rowHead[i] = NULL;
    for(int i=1; i<=matrix.colNum; i++)//把第一行的头结点全部指向NULL
        matrix.colHead[i] = NULL;
    cout << "请输入稀疏矩阵，按行标、列标、元素值的顺序输入（行列下标都从1开始），如果行为0，则结束输入。" << endl;
    int row, col, elem;
    Node * pt, * qt;                  //临时指针用来创造结点
    cin >> row >> col >> elem;
    while(row)
    {
        pt = new Node;
        pt->i = row;
        pt->j = col;
        pt->elem = elem;
        if(matrix.rowHead[row]==NULL || matrix.rowHead[row]->j>col)
        {
            pt->right = matrix.rowHead[row];
            matrix.rowHead[row] = pt;
        }
        else
        {
            qt = matrix.rowHead[row];
            while(qt->right && qt->right->j<col)
                qt = qt->right;
            pt->right = qt->right;
            qt -> right = pt;
        }
        if(matrix.colHead[col]==NULL || matrix.colHead[col]->i>row)
        {
            pt->down = matrix.colHead[col];
            matrix.colHead[col] = pt;
        }
        else
        {
            qt = matrix.colHead[col];
            while(qt->down && qt->down->i<row)
                qt = qt->down;
            pt->down = qt->down;
            qt->down = pt;
        }
        cin >> row >> col >> elem;
    }
}
void displayMatrix(CrossList & matrix)
{
    Node * pt;
    for(int i=1; i<=matrix.rowNum; i++)
    {
        pt = matrix.rowHead[i];
        while(pt)
        {
            cout << pt->i << "\t" << pt->j << "\t" << pt->elem << endl;
            pt = pt->right;
        }
    }
}
int main()
{
    CrossList cl;
    createCrossMatrix(cl);
    displayMatrix(cl);
    return 0;
}
