// http://usaco.org/index.php?page=viewproblem2&cpid=104
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    vector<int> b;
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    int n, k, i, x, y;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    for (i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        arr[y + 1]--;
        arr[x]++;
    }
    for (i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        b.push_back(arr[i]);
    }
    sort(b.begin(), b.end());
    cout << b[n / 2] << endl;
    return 0;
}