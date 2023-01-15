// http://www.usaco.org/index.php?page=viewproblem2&cpid=615
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m, i;
    cin >> x >> y >> m;
    int mx = m / x, mxresult = -MAX_INT, numY;
    for (i = 0; i <= mx; i++)
    {
        numY = (m - (i * x)) / y;
        mxresult = max(mxresult, numY * y + i * x);
    }
    cout << mxresult;
    system("pause");
    return 0;
}