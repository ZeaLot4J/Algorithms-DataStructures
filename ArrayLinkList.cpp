#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, k;
    cout << "please input n: ";
    cin >> n;
    cout << "please input k: ";
    cin >> k;
    int * a = new int[n+1];
    int * b = new int[n+1];
    for(int i=1, val=2; i<n; i++, val++)
    {
        a[i] = val;
        b[i] = val;
    }
    a[0] = b[0] = -1;
    a[n] = b[n] = 1;

    int i=n, tmp;
    for(int cnt=0, kt=0; cnt!=n; cnt++, kt=0)
    {
        while(kt < k)
        {
            if(b[i])
                kt++;
            tmp = i;
            i = a[i];

        }
        cout << i << ' ';
        b[tmp] = 0;
    }

    return 0;
}
