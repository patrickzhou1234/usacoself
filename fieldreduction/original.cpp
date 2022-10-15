// http://www.usaco.org/index.php?page=viewproblem2&cpid=641
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct coord {
    int x, y;
};

int main() {
    int n, i, mxpt=-1, mnpt=MAX_INT, mxind, mnind, outmin, outmax;
    cin >> n;
    coord cows[n], simarr[n-1];
    for (i=0;i<n;i++) {
        cin >> cows[i].x >> cows[i].y;
        mxpt = max(mxpt, abs(cows[i].x)+abs(cows[i].y));
        mnpt = min(mnpt, abs(cows[i].x)+abs(cows[i].y));
    }
    for (i=0;i<n;i++) {
        if (abs(cows[i].x)+abs(cows[i].y)==mxpt) {
            mxind = i;
        } else if (abs(cows[i].x)+abs(cows[i].y)==mnpt) {
            mnind = i;
        }
    }
    for (i=0;i<n;i++) {
        if (i!=mxind) {
            simarr[i].x = cows[i].x;
            simarr[i].y = cows[i].y;
        }
        mxpt = max(mxpt, abs(cows[i].x)+abs(cows[i].y));
        mnpt = min(mnpt, abs(cows[i].x)+abs(cows[i].y));
    }
    system("pause");
    return 0;
}