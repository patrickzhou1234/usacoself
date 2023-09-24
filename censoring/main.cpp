// http://www.usaco.org/index.php?page=viewproblem2&cpid=526
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string f, s;
    int i;
    cin >> s;
    cin >> f;
    size_t pos = s.find(f);
    while (pos != string::npos)
    {
        s.erase(pos, f.length());
        pos = s.find(f);
    }
    cout << s;
    system("pause");
    return 0;
}