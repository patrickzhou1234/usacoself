// http://www.usaco.org/index.php?page=viewproblem2&cpid=892
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i - 1])
        {
            j = i;
            break;
        }
    }
    cout << j;
    return 0;
}