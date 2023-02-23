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
    for (i = 0; i < (int)inp.size(); i++)
    {
        gct = 0, hct = 0;
        for (j = i; j < (int)inp.size(); j++)
        {
            if (inp[j] == 'G')
                gct++;
            if (inp[j] == 'H')
                hct++;
            if (gct + hct >= 3 && (gct == 1 || hct == 1))
            {
                ct++;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}