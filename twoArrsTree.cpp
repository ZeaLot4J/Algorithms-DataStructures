#include <stdio.h> 
#include <iostream>
using namespace std;
#define MAXN 1024
 
/* Hackerrank SwapNodes */
int left[MAXN + 1], right[MAXN + 1], depth[MAXN + 1], n, t, k;
 

void getDepth(int cur, int d)
{
    depth[cur] = d;
    if (left[cur] > 0) getDepth(left[cur], d + 1);
    if (right[cur] > 0) getDepth(right[cur], d + 1);
}
 
void preOrder(int cur)
{
	cout << cur << " ";
    if (left[cur] > 0) preOrder(left[cur]);
    if (right[cur] > 0) preOrder(right[cur]);
}
void inOrder(int cur)
{
    if (left[cur] > 0) inOrder(left[cur]);
    cout << cur << " ";
    if (right[cur] > 0) inOrder(right[cur]);
}
void postOrder(int cur)
{
    if (left[cur] > 0) postOrder(left[cur]);
    if (right[cur] > 0) postOrder(right[cur]);
	cout << cur << " ";
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