// http://usaco.org/index.php?page=viewproblem2&cpid=1131
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int checkMax(vector<int> arr)
{
    int i;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] < i + 1)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int n, l, i, tmp;
    cin >> n >> l;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    tmp = checkMax(arr);
    for (i = tmp; i > tmp - l; i--)
    {
        if (i >= 0)
        {
            arr[i]++;
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    cout << checkMax(arr) << endl;
    system("pause");
    return 0;
}