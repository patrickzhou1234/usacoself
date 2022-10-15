// http://www.usaco.org/index.php?page=viewproblem2&cpid=641
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

struct coord {
    int x, y;
};

bool compare(coord a, coord b)
{
    if (abs(a.x)+abs(a.y)>abs(b.x)+abs(b.y)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, i, firstval, secondval;
    cin >> n;
    coord cows[n];
    for (i=0;i<n;i++) {
        cin >> cows[i].x >> cows[i].y;
    }
    sort(cows, cows+n, compare);
    for (i=0;i<n;i++) {
        cout << cows[i].x << " " << cows[i].y << endl;
    }
    firstval = (abs(cows[0].x-cows[n-2].x)+1)*(abs(cows[0].y-cows[n-2].y)+1);
    secondval = (abs(cows[1].x-cows[n-1].x)+1)*(abs(cows[1].y-cows[n-1].y)+1);
    cout << min(firstval, secondval);
    system("pause");
    return 0;
}