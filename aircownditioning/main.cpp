// http://www.usaco.org/index.php?page=viewproblem2&cpid=1156
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int main()
{
    int n, i, ans;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 2);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (i = 1; i <= n; i++)
    {
        c[i] = a[i] - b[i];
    }
    ans = 0;
    for (i = 0; i <= n; i++)
    {
        ans += abs(c[i] - c[i + 1]);
    }
    cout << ans / 2;
    system("pause");
    return 0;
}