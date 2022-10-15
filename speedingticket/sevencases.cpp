// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
#include <iostream>
#include <algorithm>

using namespace std;

struct mat {
    int len, speed;
};

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m, i, mx=0;
    cin >> n >> m;
    mat normalseg[n], bessieseg[m];
    for (i=0;i<n;i++) {
        cin >> normalseg[i].len >> normalseg[i].speed;
    }
    for (i=0;i<m;i++) {
        cin >> bessieseg[i].len >> bessieseg[i].speed;
    }
    for (i=0;i<m;i++) {
        if (i!=0) {
            if (normalseg[i-1].len>bessieseg[i-1].len) {
                if (bessieseg[i].speed>normalseg[i-1].speed) {
                    mx = max(mx, bessieseg[i].speed-normalseg[i-1].speed);
                }
                if (bessieseg[i].speed>normalseg[i].speed) {
                    mx = max(mx, bessieseg[i].speed-normalseg[i].speed);
                }
            } else {
                if (bessieseg[i].speed>normalseg[i].speed) {
                    mx = max(mx, bessieseg[i].speed-normalseg[i].speed);
                }
            }
        } else {
            if (bessieseg[i].len>normalseg[i].len) {
                if (bessieseg[i].speed>normalseg[i].speed) {
                    mx = max(mx, bessieseg[i].speed-normalseg[i].speed);
                }
                if (bessieseg[i].speed>normalseg[i+1].speed) {
                    mx = max(mx, bessieseg[i].speed-normalseg[i+1].speed);
                }
            }
        }
    }
    cout << mx;
    return 0;
}