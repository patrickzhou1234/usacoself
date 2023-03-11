// http://usaco.org/index.php?page=viewproblem2&cpid=1131
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, l, bs, i, tmp;
    cin >> n >> l >> bs;
    vector<int> arr;
    for (i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), greater<int>());

    system("pause");
    return 0;
}