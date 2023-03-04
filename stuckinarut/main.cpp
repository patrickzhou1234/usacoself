// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct cow
{
    char dir;
    int x, y;
    bool mobile = true;
};

struct coord
{
    int x, y;
};

int main()
{
    int n, i, j, m;
    cin >> n;
    cow c;
    vector<cow> cows;
    coord tmp;
    vector<coord> coords;
    for (i = 0; i < n; i++)
    {
        cin >> c.dir >> c.x >> c.y;
        cows.push_back(c);
    }
    int cowG[n];
    for (i = 0; i < n; i++)
    {
        cowG[i] = -1;
    }
    for (i = 1; i <= 100; i++)
    {
        for (j = 0; j < cows.size(); j++)
        {
            if (cows[j].mobile)
            {
                tmp.x = cows[j].x;
                tmp.y = cows[j].y;
                coords.push_back(tmp);
            }
        }
        for (j = 0; j < cows.size(); j++)
        {
            if (cows[j].mobile)
            {
                if (cows[j].dir == 'N')
                {
                    cows[j].y++;
                }
                if (cows[j].dir == 'S')
                {
                    cows[j].y--;
                }
                if (cows[j].dir == 'E')
                {
                    cows[j].x++;
                }
                if (cows[j].dir == 'W')
                {
                    cows[j].x--;
                }
            }
        }
        for (j = 0; j < cows.size(); j++)
        {
            if (cows[j].mobile)
            {
                for (m = 0; m < coords.size(); m++)
                {
                    if (cows[j].x == coords[m].x && cows[j].y == coords[m].y)
                    {
                        cowG[j] = i;
                        cows[j].mobile = false;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (cowG[i] == -1)
        {
            cout << "Infinity";
        }
        else
        {
            cout << cowG[i];
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}