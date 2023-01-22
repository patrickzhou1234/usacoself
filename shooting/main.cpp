// https://codeforces.com/contest/1216/problem/B%C2%A0
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, sum = 0, x = 0;
    cin >> n;
    int arr[n], origarr[n];
    string order = "";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    copy(arr, arr + n, origarr);
    sort(arr, arr + n);
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i] == origarr[j])
            {
                order += to_string(j + 1) + " ";
                origarr[j] = -1;
            }
        }
    }
    for (j = n - 1; j >= 0; j--)
    {
        sum += arr[j] * x + 1;
        x++;
    }
    cout << sum << "\n"
         << order;
    system("pause");
    return 0;
}