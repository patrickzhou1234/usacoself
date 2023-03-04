// http://www.usaco.org/index.php?page=viewproblem2&cpid=1180
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

bool calculateProbability(vector<int> a, vector<int> b)
{
    int awin = 0, bwin = 0, i, j;
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < b.size(); j++)
        {
            if (a[i] > b[j])
            {
                awin++;
            }
            if (a[i] < b[j])
            {
                bwin++;
            }
        }
    }
    if (awin > bwin)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, i, j, m, k, cs, tmp;
    cin >> n;
    vector<int> tmpset, c;
    vector<vector<int>> a, b;
    bool fd;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cin >> tmp;
            tmpset.push_back(tmp);
        }
        a.push_back(tmpset);
        tmpset.clear();
        for (j = 0; j < 4; j++)
        {
            cin >> tmp;
            tmpset.push_back(tmp);
        }
        b.push_back(tmpset);
        tmpset.clear();
    }
    for (cs = 0; cs < n; cs++)
    {
        fd = false;
        for (i = 1; i <= 10; i++)
        {
            for (j = 1; j <= 10; j++)
            {
                for (m = 1; m <= 10; m++)
                {
                    for (k = 1; k <= 10; k++)
                    {
                        c.insert(c.end(), {i, j, m, k});
                        if (calculateProbability(a[cs], b[cs]))
                        {
                            if (calculateProbability(b[cs], c) && calculateProbability(c, a[cs]))
                            {
                                fd = true;
                            }
                        }
                        else
                        {
                            if (calculateProbability(a[cs], c) && calculateProbability(c, b[cs]))
                            {
                                fd = true;
                            }
                        }
                        c.clear();
                    }
                }
            }
        }
        if (fd)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    system("pause");
    return 0;
}