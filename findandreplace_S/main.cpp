// http://www.usaco.org/index.php?page=viewproblem2&cpid=1278
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct spair
{
    string from, to;
};

int main()
{
    int t, i, j, m, ct;
    bool added, impossible;
    cin >> t;
    spair pairs[t];
    for (i = 0; i < t; i++)
    {
        cin >> pairs[i].from >> pairs[i].to;
    }
    for (i = 0; i < t; i++)
    {
        ct = 0;
        for (j = 0; j < pairs[i].from.length(); j++)
        {
            if (pairs[i].from.at(j) != pairs[i].to.at(j))
            {
                added = false, impossible = false;
                for (m = 0; m < pairs[i].from.length(); m++)
                {
                    if (pairs[i].from.at(m) == pairs[i].to.at(j) && pairs[i].from.at(m) != pairs[i].to.at(m))
                    {
                        pairs[i].from.at(j) = pairs[i].to.at(j);
                        pairs[i].from.at(m) = pairs[i].to.at(m);
                        ct += 3;
                        added = true;
                    }
                    if (pairs[i].from.at(j) == pairs[i].from.at(m) && pairs[i].to.at(j) != pairs[i].to.at(m))
                    {
                        impossible = true;
                    }
                }
                if (impossible)
                {
                    ct = -1;
                    break;
                }
                if (!added)
                {
                    ct++;
                }
            }
        }
        cout << ct << "\n";
    }
    system("pause");
    return 0;
}