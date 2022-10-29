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
    int visct=0;
    billb a, b, tr;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> tr.x1 >> tr.y1 >> tr.x2 >> tr.y2;
    
    // B1 and Truck
    //int x_rightedge = min(a.x2,tr.x2);
    //int x_leftedge = max(a.x1,tr.x1);
    int x_overlap=max(0, min(a.x2,tr.x2) - max(a.x1,tr.x1));
    int y_overlap=max(0, min(a.y2,tr.y2) - max(a.y1,tr.y1));
    int finoverlap = x_overlap*y_overlap;
    // B2 and truck
    x_overlap=max(0, min(b.x2,tr.x2) - max(b.x1,tr.x1));
    y_overlap=max(0, min(b.y2,tr.y2) - max(b.y1,tr.y1));
    finoverlap+=(x_overlap*y_overlap);
    visct = ((a.x2-a.x1)*(a.y2-a.y1))+((b.x2-b.x1)*(b.y2-b.y1))-finoverlap;
    cout << visct;
    return 0;
}