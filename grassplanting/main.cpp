// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        a[i] = 0;
    string tmp;
    for (i = 0; i < (n - 1) * 2; i++)
    {
        cin >> tmp;
        a[stoi(tmp)]++;
    }
    int mx = -MAX_INT;
    for (i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
    }
    cout << mx + 1;
    return 0;
}