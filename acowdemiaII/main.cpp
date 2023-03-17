// http://usaco.org/index.php?page=viewproblem2&cpid=1132
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct greaterpair
{
    string a, b;
};

int main()
{
    int k, n, i, j, m, f;
    cin >> k >> n;
    string firstline[n];
    char ans[n][n];
    vector<greaterpair> greaterpairs;
    greaterpair tmp;
    for (i = 0; i < n; i++)
    {
        cin >> firstline[i];
    }
    string nextlines[k][n];
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> nextlines[i][j];
        }
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (m = j + 1; m < n; m++)
            {
                if (nextlines[i][j].compare(nextlines[i][m]) > 0)
                {
                    tmp.a = nextlines[i][m];
                    tmp.b = nextlines[i][j];
                    greaterpairs.push_back(tmp);
                }
                else if (m - j > 1)
                {
                    for (f = 0; f < greaterpairs.size(); f++)
                    {
                        if ((greaterpairs[f].a.compare(nextlines[i][m - 1]) == 0 && greaterpairs[f].b.compare(nextlines[i][m]) == 0) || (greaterpairs[f].b.compare(nextlines[i][m - 1]) == 0 && greaterpairs[f].a.compare(nextlines[i][m]) == 0))
                        {
                            tmp.a = nextlines[i][m];
                            tmp.b = nextlines[i][j];
                            greaterpairs.push_back(tmp);
                            break;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                ans[i][j] = 'B';
                continue;
            }
            for (m = 0; m < greaterpairs.size(); m++)
            {
                if (greaterpairs[m].a.compare(firstline[i]) == 0 && greaterpairs[m].b.compare(firstline[j]) == 0)
                {
                    ans[i][j] = '1';
                    break;
                }
                if (greaterpairs[m].a.compare(firstline[j]) == 0 && greaterpairs[m].b.compare(firstline[i]) == 0)
                {
                    ans[i][j] = '0';
                    break;
                }
            }
            if (m == greaterpairs.size())
            {
                ans[i][j] = '?';
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}