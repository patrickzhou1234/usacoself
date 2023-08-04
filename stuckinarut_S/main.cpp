// http://usaco.org/index.php?page=viewproblem2&cpid=1064
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct cow
{
    int x, y, origind;
};

int main()
{
    int n, i, j, dx, dy;
    char tmp;
    cin >> n;
    vector<cow> earr, narr;
    int blame[n];
    bool blocked[n];
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 'E')
        {
            cin >> dx >> dy;
            earr.push_back({dx, dy, i});
        }
        else
        {
            cin >> dx >> dy;
            narr.push_back({dx, dy, i});
        }
        blame[i] = 0;
        blocked[i] = false;
    }
    sort(earr.begin(), earr.end(), [](cow a, cow b)
         { return a.y < b.y; });
    sort(narr.begin(), narr.end(), [](cow a, cow b)
         { return a.x < b.x; });
    for (i = 0; i < earr.size(); i++)
    {
        for (j = 0; j < narr.size(); j++)
        {
            dx = narr[j].x - earr[i].x;
            dy = earr[i].y - narr[j].y;
            if (blocked[earr[i].origind] || blocked[narr[j].origind] || dx <= 0 || dy <= 0)
                continue;
            if (dx < dy)
            {
                blame[earr[i].origind] += blame[narr[j].origind] + 1;
                blocked[narr[j].origind] = true;
            }
            else if (dx > dy)
            {
                blame[narr[j].origind] += blame[earr[i].origind] + 1;
                blocked[earr[i].origind] = true;
            }
            else
            {
                continue;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << blame[i] << "\n";
    }
    system("pause");
    return 0;
}