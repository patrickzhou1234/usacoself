// http://www.usaco.org/index.php?page=viewproblem2&cpid=783
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_INT 2147483647

#define MAX_DOUBLE 9007199254740991

struct billb {
    int x1, y1, x2, y2;
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    double i, j, mnX=MAX_DOUBLE, mxX=-1, mnY=MAX_DOUBLE, mxY=-1;
    billb a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    for (i=a.x1+0.5;i<a.x2;i++) {
        for (j=a.y1+0.5;j<a.y2;j++) {
            if (!(i>b.x1 && i<b.x2 && j>b.y1 && j<b.y2)) {
                mnX = min(mnX, i);
                mxX = max(mxX, i);
                mnY = min(mnY, j);
                mxY = max(mxY, j);
            }
        }
    }
    mnX = floor(mnX);
    mxX = ceil(mxX);
    mnY = floor(mnY);
    mxY = ceil(mxY);
    cout << (mxX-mnX)*(mxY-mnY);
    system("pause");
    return 0;
}