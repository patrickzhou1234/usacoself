// https://codeforces.com/contest/1216/problem/C
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int i, j;
    int b1[4], b2[4], w[4];
    for (i = 0; i < 4; i++)
    {
        cin >> w[i];
    }
    for (i = 0; i < 4; i++)
    {
        cin >> b1[i];
    }
    for (i = 0; i < 4; i++)
    {
        cin >> b2[i];
    }
    double d, e;
    for (d = w[0] + 0.5; d < w[2] - 0.5; d++)
    {
        e = w[1] + 0.5;
        if (!((b1[0] <= d && d <= b1[2] && b1[1] <= e && e <= b1[3]) || (b2[0] <= d && d <= b2[2] && b2[1] <= e && e <= b2[3])))
        {
            cout << "YES";
            return 0;
        }
        e = w[3] + 0.5;
        d+=0.5;
        if (!((b1[0] <= d && d <= b1[2] && b1[1] <= e && e <= b1[3]+1.5) || (b2[0] <= d && d <= b2[2] && b2[1] <= e && e <= b2[3])))
        {
            cout << "YES";
            return 0;
        }
    }
    for (e = w[1] + 0.5; e < w[3] - 0.5; e++)
    {
        d = w[0] + 0.5;
        if (!((b1[0] <= d && d <= b1[2] && b1[1] <= e && e <= b1[3]+1.5) || (b2[0] <= d && d <= b2[2] && b2[1] <= e && e <= b2[3])))
        {
            cout << "YES";
            return 0;
        }
        d = w[2] + 0.5;
        d+=0.5;
        if (!((b1[0] <= d && d <= b1[2] && b1[1] <= e && e <= b1[3]) || (b2[0] <= d && d <= b2[2] && b2[1] <= e && e <= b2[3])))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    system("pause");
    return 0;
}