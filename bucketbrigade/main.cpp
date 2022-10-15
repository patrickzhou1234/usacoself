// http://usaco.org/index.php?page=viewproblem2&cpid=939
#include <iostream>
#include <algorithm>

using namespace std;

struct coord {
    int x, y;
};

#define MAX_INT 2147483647

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    char map[10][10], ans[10][10];
    int i, j, minX, minY, maxY, maxX;
    coord b, r, l;
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            cin >> map[i][j];
        }
    }
    for (i=0;i<10;i++) {
        for (j=0;j<10;j++) {
            if (map[i][j] == 'B') {
                b.x = i;
                b.y = j;
            } else if (map[i][j] == 'R') {
                r.x = i;
                r.y = j;
            } else if (map[i][j] == 'L') {
                l.x = i;
                l.y = j;
            }
        }
    }
    minX = min(b.x, l.x);
    maxX = max(b.x, l.x);
    minY = min(b.y, l.y);
    maxY = max(b.y, l.y);
    if ((b.x == l.x && r.x == b.x && r.y>minY && r.y<maxY) || (b.y == l.y && r.y == b.y && r.x>minX && r.x<maxX)) {
        cout << abs(l.x-b.x)+abs(l.y-b.y)-1+2;
    } else {
        cout << abs(l.x-b.x)+abs(l.y-b.y)-1;
    }
    system("pause");
    return 0;
}