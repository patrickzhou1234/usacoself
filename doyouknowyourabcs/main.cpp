// http://www.usaco.org/index.php?page=viewproblem2&cpid=1059
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int i, j, z;
    int a[7];
    for (i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 7);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            for (z = 0; z < 6; z++)
            {
                if (i == j || j == z || i == z)
                    continue;
                if (a[i] + a[j] + a[z] == a[6])
                {
                    cout << a[i] << " " << a[j] << " " << a[z] << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}