// https://codeforces.com/contest/1826/problem/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int t, tmp, i, j, m, ptr, ct;
    bool fd;
    cin >> t;
    int n[t];
    vector<int> v;
    for (i = 0; i < t; i++)
    {
        fd = false;
        cin >> n[i];
        for (j = 0; j < n[i]; j++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        ct = n[i];
        ptr = n[i] - 1;
        sort(v.begin(), v.end(), greater<int>());
        for (j = 0; j <= n[i]; j++)
        {
            for (m = ptr; m >= 0 && v[m] <= j; m--)
            {
                ct--;
            }
            ptr = m;
            if (ct == j)
            {
                cout << j << endl;
                fd = true;
                break;
            }
        }
        if (!fd)
        {
            cout << -1 << endl;
        }
        v.clear();
    }
    system("pause");
    return 0;
}