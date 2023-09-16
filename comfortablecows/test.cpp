// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct coord
{
    int x;
    int y;
};

int main()
{
    coord adj[] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<coord> comfcws;
    int n, i, j, finalcc = 0, x, y, cc;
    cin >> n;
    bool arr[1008][1008];
    for (i = 0; i < 1004; i++)
    {
        for (j = 0; j < 1004; j++)
        {
            arr[i][j] = false;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < comfcws.size(); j++)
        {
            cc = 0;
            x = comfcws[j].x;
            y = comfcws[j].y;
            if (arr[x + 2][y + 2])
            {
                if (arr[x + 2][y + 3])
                {
                    cc++;
                }
                if (arr[x + 2][y + 1])
                {
                    cc++;
                }
                if (arr[x + 1][y + 2])
                {
                    cc++;
                }
                if (arr[x + 3][y + 2])
                {
                    cc++;
                }
                if (cc != 3)
                {
                    comfcws.erase(comfcws.begin() + j);
                    finalcc--;
                }
            }
        }
        cin >> x >> y;
        arr[x + 2][y + 2] = true;
        for (j = 0; j < 5; j++)
        {
            cc = 0;
            if (arr[x + 2 + adj[j].x][y + 2 + adj[j].y])
            {
                if (arr[x + 2 + adj[j].x][y + 3 + adj[j].y])
                {
                    cc++;
                }
                if (arr[x + 2 + adj[j].x][y + 1 + adj[j].y])
                {
                    cc++;
                }
                if (arr[x + 1 + adj[j].x][y + 2 + adj[j].y])
                {
                    cc++;
                }
                if (arr[x + 3 + adj[j].x][y + 2 + adj[j].y])
                {
                    cc++;
                }
                if (cc == 3)
                {
                    comfcws.push_back({x + adj[j].x, y + adj[j].y});
                    finalcc++;
                }
            }
        }
        cout << finalcc << endl;
    }
    return 0;
}