// http://www.usaco.org/index.php?page=viewproblem2&cpid=917
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct segment {
    int a, b;
};

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n, i;
    cin >> n;
    string arr[n];
    segment segs[n];
    for (i=0;i<n;i++) {
        cin >> arr[i] >> segs[i].a >> segs[i].b;
    }
    int maxR=1000000, minR=0;
    for (i=n-1;i>=0;i--) {
        if (arr[i]=="off") {
            minR+=segs[i].a;
            maxR+=segs[i].b;
        }
        if (arr[i]=="on") {
            minR-=segs[i].b;
            minR = max(0, minR);
            maxR-=segs[i].a;
            maxR = max(0, maxR);
        }
        if (arr[i]=="none") {
            minR = max(minR, segs[i].a);
            maxR = min(maxR, segs[i].b);
        }
    }
    cout << minR << " " << maxR << "\n";
    for (i=0;i<n;i++) {
        if (arr[i]=="on") {
            minR+=segs[i].a;
            maxR+=segs[i].b;
        }
        if (arr[i]=="off") {
            minR-=segs[i].b;
            minR = max(0, minR);
            maxR-=segs[i].a;
            maxR = max(0, maxR);
        }
        if (arr[i]=="none") {
            minR = max(minR, segs[i].a);
            maxR = min(maxR, segs[i].b);
        }
    }
    cout << minR << " " << maxR;
    return 0;
}