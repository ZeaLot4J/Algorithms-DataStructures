#include <stdio.h> 
#include <iostream>
using namespace std;
#define MAXN 1024
 
int left[MAXN + 1], right[MAXN + 1], depth[MAXN + 1], n, t, k;
 

void getDepth(int cur, int d)
{
    depth[cur] = d;
    if (left[cur] > 0) getDepth(left[cur], d + 1);
    if (right[cur] > 0) getDepth(right[cur], d + 1);
}
 
void inOrder(int cur)
{
    if (left[cur] > 0) inOrder(left[cur]);
    cout << cur << " ";
    if (right[cur] > 0) inOrder(right[cur]);
}
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> left[i] >> right[i];
    }
 
    getDepth(1, 1);
 
    cin >> t;
    while (t--) {
        cin >> k;
        for (int i = 1; i <= n; i++) {
            if (depth[i] % k == 0) {
                swap(left[i], right[i]);
            }
        }
        inOrder(1);
        cout << endl;
    }
    return 0;
}