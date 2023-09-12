// link to problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k, m, j, tmpinp, z;
    cin >> k;
    vector<vector<int>> mat;
    vector<int> tmp;
    for (i = 0; i <= n; i++)
    {
        mat.push_back(tmp);
    }
    for (i = 0; i < k; i++)
    {
        cin >> k;
        cin >> m;
        for (j = 0; j < m; j++)
        {
            cin >> tmpinp;
            mat[i].push_back(tmpinp);
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        a[i]++;
        for (j = 0; j < mat[i].size(); j++)
        {
            a[mat[i][j]]--;
        }
        if (a[i] < 0)
        {
            if (mat[i].size() == 0)
            {
                break;
            }
        }
        if (i == 0 && a[i] < 0)
        {
            break;
        }
    }
    cout << a[n - 1] - 1;
    system("pause");
    return 0;
}