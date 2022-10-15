// http://www.usaco.org/index.php?page=viewproblem2&cpid=639
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k, i, j, ct=0, lw, tp, mxct=-1;
    cin >> n >> k;
    int sizes[n];
    for (i=0;i<n;i++) {
        cin >> sizes[i];
    }
    sort(sizes, sizes+n);
    for (j=0;j<n;j++) {
        ct=0;
        lw = sizes[j]-k;
        tp = sizes[j];
        for (i=0;i<n;i++) {
            if (sizes[i]>=lw && sizes[i]<=tp) {
                ct++;
            }
        }
        mxct = max(ct, mxct);
    }
    for (j=0;j<n;j++) {
        ct=0;
        tp = sizes[j]+k;
        lw = sizes[j];
        for (i=0;i<n;i++) {
            if (sizes[i]<=tp && sizes[i]>=lw) {
                ct++;
            }
        }
        mxct = max(ct, mxct);
    }
    cout << mxct;
    system("pause");
    return 0;
}