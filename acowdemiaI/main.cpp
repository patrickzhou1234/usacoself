// http://usaco.org/index.php?page=viewproblem2&cpid=1131
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int checkMax(vector<int> arr)
{
    int i, j, ct, h;
    for (i = 0; i < arr.size(); i++)
    {
        ct = 0;
        for (j = 0; j < arr.size(); j++)
        {
            if (arr[j] >= i)
            {
                ct++;
            }
        }
        if (ct >= i)
        {
            h = i;
        }
    }
    return h;
}

int main()
{
    int n, l, i, j, tmp, sum;
    cin >> n >> l;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = n - arr[i]; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                sum += arr[i] - arr[j];
            }
        }
        if (sum <= l)
        {
            cout << max(arr[i], checkMax(arr));
            break;
        }
    }
    system("pause");
    return 0;
}