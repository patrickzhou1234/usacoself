// http://www.usaco.org/index.php?page=viewproblem2&cpid=988
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n, i, j, m;
    cin >> n;
    int barr[n], narr[n - 1], cpybarr[n];
    for (i = 0; i < n - 1; i++)
    {
        cin >> narr[i];
    }
    for (i = 1; i < n; i++)
    {
        barr[0] = i;
        for (j = 1; j < n; j++)
        {
            barr[j] = narr[j - 1] - barr[j - 1];
        }
        copy(barr, barr + n, cpybarr);
        sort(barr, barr + n);
        for (j = 0; j < n; j++)
        {
            if (barr[j] != j + 1)
            {
                break;
            }
        }
        if (j == n)
        {
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << cpybarr[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    system("pause");
    return 0;
}