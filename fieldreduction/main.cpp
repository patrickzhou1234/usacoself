// http://www.usaco.org/index.php?page=viewproblem2&cpid=641
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct coord {
    int x, y;
};

bool compareX(coord a, coord b)
{
    if (a.x>b.x) {
        return true;
    } else {
        return false;
    }
}

bool compareY(coord a, coord b)
{
    if (a.y>b.y) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n, i, mxar=-1, j, ar, minX=MAX_INT, maxX=-1, minY=MAX_INT, maxY=-1;
    cin >> n;
    coord cows[n], removed[n-1];
    for (i=0;i<n;i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    for (j=0;j<n;j++) {
        for (i=0;i<n;i++) {
            if (i!=j) {
                removed[i].x = cows[i].x;
                removed[i].y = cows[i].y;
            }
        }
        for (i=0;i<n-1;i++) {
            minX = min(removed[i].x, minX);
            maxX = max(removed[i].x, maxX);
            minY = min(removed[i].y, minY);
            maxY = max(removed[i].y, maxY);
        }
        ar = abs(maxX-minX)*abs(maxY-minY);
        mxar = max(ar, mxar);
    }
    cout << mxar;
    system("pause");
    return 0;
}