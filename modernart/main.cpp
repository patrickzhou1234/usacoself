// link to problem
#include <iostream>
#include <unordered_set>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    unordered_set<int> ans;
    int dim[10][4];
    int n, i, j, k;
    cin >> n;
    char chararr[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> chararr[i][j];
        }
    }
    int arr[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = chararr[i][j] - '0';
        }
    }
    for (i = 0; i < 10; i++)
    {
        dim[i][0] = MAX_INT;
        dim[i][1] = MAX_INT;
        dim[i][2] = -1;
        dim[i][3] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                dim[arr[i][j]][0] = min(dim[arr[i][j]][0], i);
                dim[arr[i][j]][1] = min(dim[arr[i][j]][1], j);
                dim[arr[i][j]][2] = max(dim[arr[i][j]][2], i);
                dim[arr[i][j]][3] = max(dim[arr[i][j]][3], j);
            }
        }
    }
    int totalused = 0;
    for (i = 0; i < 10; i++)
    {
        if (dim[i][0] == MAX_INT)
        {
            continue;
        }
        totalused++;
        for (j = dim[i][0]; j <= dim[i][2]; j++)
        {
            for (k = dim[i][1]; k <= dim[i][3]; k++)
            {
                if (arr[j][k] != i)
                {
                    ans.insert(arr[j][k]);
                }
            }
        }
    }
    cout << totalused - ans.size();
    system("pause");
    return 0;
}