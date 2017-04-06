#include <iostream>
using namespace std;

void insertSort(int* ia, int n)
{
    int tmp, j;
    for(int i=1; i<n; i++)//从第二个数开始
    {
        tmp = ia[i];
        j = i;
        while(j>0 && ia[j-1]>tmp)
        {
            ia[j] = ia[j-1];
            j--;
        }
        ia[j] = tmp;
    }
}
int main()
{
    int ia[9] = {5,3, 8,1, 4, 2, 6, 7, 9};
    insertSort(ia, 9);

    for(int i=0; i<9; i++)
        cout << ia[i] << " ";
    return 0;
}
