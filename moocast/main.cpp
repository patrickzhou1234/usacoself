// link to problem
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_INT 2147483647

struct cow
{
    int x, y, p;
};

int n, i, j, ct, mxCt = -1;
cow cows[200];
bool canReach[200][200];
bool visited[200];

void dfs(int idx)
{
    for (int c = 0; c < n; c++)
    {
        if (canReach[idx][c] && !visited[c] && c != idx)
        {
            visited[c] = true;
            dfs(c);
        }
    }
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                long dx = cows[i].x - cows[j].x, dy = cows[i].y - cows[j].y;
                if (dx * dx + dy * dy <= cows[i].p * cows[i].p)
                {
                    canReach[i][j] = true;
                }
                else
                {
                    canReach[i][j] = false;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        ct = 0;
        for (j = 0; j < n; j++)
        {
            visited[j] = false;
        }
        // visited[i] = true;
        dfs(i);
        for (j = 0; j < n; j++)
        {
            if (visited[j])
            {
                ct++;
            }
        }
        mxCt = max(mxCt, ct);
    }
    if (mxCt == 2)
    {
        mxCt++;
    }
    cout << mxCt;
    system("pause");
    return 0;
}