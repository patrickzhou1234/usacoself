// https://cses.fi/problemset/task/1619
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct unit
{
    int time;
    string type;
};

bool comp(unit a, unit b)
{
    if (a.time == b.time)
    {
        if (a.type == "start")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return (a.time < b.time);
}

int main()
{
    int n, i, tmp, mxtmp = -1;
    cin >> n;
    unit times[2 * n];
    int alt = 1;
    for (i = 0; i < 2 * n; i++)
    {
        cin >> times[i].time;
        if (alt == 1)
        {
            times[i].type = "start";
            alt *= -1;
        }
        else
        {
            times[i].type = "end";
            alt *= -1;
        }
    }
    sort(times, times + 2 * n, comp);
    tmp = 0;
    for (i = 0; i < n; i++)
    {
        if (times[i].type == "start")
        {
            tmp++;
        }
        else
        {
            tmp--;
        }
        mxtmp = max(mxtmp, tmp);
    }
    cout << mxtmp;
    return 0;
}