// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct coord
{
    int x;
    int y;
};

int main()
{
    int n, i, j, finalcc;
    cin >> n;
    bool arr[1004][1004];
    for (i = 0; i < 1004; i++)
    {
        for (j = 0; j < 1004; j++)
        {
            arr[i][j] = false;
        }
    }
    coord pts[8];
    for (i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pts[i].x = x;
        pts[i].y = y;
        arr[x + 2][y + 2] = true;
        finalcc = 0;
        for (j = 0; j < n; j++)
        {
            int cc = 0;
            x = pts[j].x;
            y = pts[j].y;
            if (arr[x + 2][y + 3])
            {
                cc++;
            }
            if (arr[x + 2][y + 1])
            {
                cc++;
            }
            if (arr[x + 3][y + 2])
            {
                cc++;
            }
            if (arr[x + 1][y + 2])
            {
                cc++;
            }
            if (cc == 3)
            {
                finalcc++;
            }
        }
        cout << finalcc << endl;
    }
    system("pause");
    return 0;
}