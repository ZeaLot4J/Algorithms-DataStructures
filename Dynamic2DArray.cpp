#include <iostream>

using namespace std;

int ** make2DArray(int row, int col)
{
    int ** p = new int*[row];
    if(!p) return p;
    for(int i=0; i<row; i++)
    {
        *(p+i)= new int[col];
        if(*(p+i)==NULL)
            return p;
    }
    return p;
}
void destroy2DArray(int **p, int row)
{
    for(int i=0; i<row; i++)
    {
        delete *(p+i);
        *(p+i) = NULL;
    }
    delete p;
    p = NULL;
    cout << "二维数组已销毁。" << endl;
}
int main()
{
    int row, col;
    cout << "请输入二维数组的行与列：";
    cin >> row;
    cin >> col;
    int **p = make2DArray(row, col);
    cout << "请输入数值：";
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            cin >> *(*(p+i)+j);
        }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << *(*(p+i)+j) <<' ';
        }
        cout <<endl;
    }
    destroy2DArray(p, row);


    return 0;
}
