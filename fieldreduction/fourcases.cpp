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
    int n, i, a, b, c, d, e=MAX_INT, f=MAX_INT;
    cin >> n;
    coord cows[n], xArr[n], yArr[n], tmporiginal[n];
    for (i=0;i<n;i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    for (i=0;i<n;i++) {
        tmporiginal[i].x = cows[i].x;
        tmporiginal[i].y = cows[i].y;
    }
    sort(tmporiginal, tmporiginal+n, compareX);
    for (i=0;i<n;i++) {
        xArr[i] = tmporiginal[i];
    }
    for (i=0;i<n;i++) {
        tmporiginal[i].x = cows[i].x;
        tmporiginal[i].y = cows[i].y;
    }
    sort(tmporiginal, tmporiginal+n, compareY);
    for (i=0;i<n;i++) {
        yArr[i] = tmporiginal[i];
    }
    a = abs(xArr[n-2].x-xArr[0].x)*abs(yArr[n-2].y-yArr[0].y);
    b = abs(xArr[n-1].x-xArr[1].x)*abs(yArr[n-1].y-yArr[1].y);
    c = abs(xArr[n-1].x-xArr[1].x)*abs(yArr[n-2].y-yArr[0].y);
    d = abs(xArr[n-2].x-xArr[0].x)*abs(yArr[n-1].y-yArr[1].y);
    for (i=0;i<n;i++) {
        if (xArr[0].x == tmporiginal[i].x && yArr[0].y == tmporiginal[i].y) {
            e=abs(xArr[n-1].x-xArr[1].x)*abs(yArr[n-1].y-yArr[1].y);
        }
        if (xArr[n-1].x == tmporiginal[i].x && yArr[n-1].y == tmporiginal[i].y) {
            f=abs(xArr[n-2].x-xArr[0].x)*abs(yArr[n-2].y-yArr[0].y);
        }
    }
    cout << min({a, b, c, d, e, f});
    system("pause");
    return 0;
}