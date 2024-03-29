// http://www.usaco.org/index.php?page=viewproblem2&cpid=1155
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int i, j, m, gct, hct, ct = 0;
    cin >> i;
    string inp, tmp;
    cin >> inp;
    for (i = 3; i <= inp.length(); i++)
    {
        for (j = 0; j <= inp.length() - i; j++)
        {
            tmp = inp.substr(j, i);
            gct = count(tmp.begin(), tmp.end(), 'G');
            hct = count(tmp.begin(), tmp.end(), 'H');
            if (gct == 1 || hct == 1)
            {
                ct++;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}