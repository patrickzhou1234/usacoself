// http://www.usaco.org/index.php?page=viewproblem2&cpid=759
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct billb {
    int x1, y1, x2, y2;
};

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int visct=0, coveredct=0;
    double i, j;
    billb a, b, tr;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> tr.x1 >> tr.y1 >> tr.x2 >> tr.y2;
    for (i=tr.x1+0.5;i<=tr.x2;i+=1) {
        for (j=tr.y1+0.5;j<=tr.y2;j+=1) {
            if ((i>a.x1 && i<a.x2 && j>a.y1 && j<a.y2) || (i>b.x1 && i<b.x2 && j>b.y1 && j<b.y2)) {
                coveredct++;
            }
        }
    }
    visct = ((a.x2-a.x1)*(a.y2-a.y1))+((b.x2-b.x1)*(b.y2-b.y1))-coveredct;
    cout << visct;
    return 0;
}