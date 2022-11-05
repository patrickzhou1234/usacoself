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
    int n, i, ansct=0, mncur=MAX_INT, mxcur=-MAX_INT, mxrec=-MAX_INT, mnrec=MAX_INT, mnexit=MAX_INT, mxexit=-MAX_INT;
    cin >> n;
    string arr[n];
    segment segs[n];
    for (i=0;i<n;i++) {
        cin >> arr[i] >> segs[i].a >> segs[i].b;
    }
    for (i=n-1;i>=0;i--) {
        if (arr[i]=="on") {
            if (i!=n-1 && arr[i+1]!="on") {
                mxrec = -MAX_INT;
                mnrec = MAX_INT;
            }
            mxrec = max(segs[i].a, mxrec);
            mnrec = min(segs[i].b, mnrec);
        }
        if (arr[i]=="none") {
            if (i!=n-1 && arr[i+1]!="none") {
                mxcur = -MAX_INT;
                mncur = MAX_INT;
            }
            mxcur = max(mxcur, segs[i].a);
            mncur = min(mncur, segs[i].b);
        }
        if (arr[i]=="off") {
            if (i!=n-1 && arr[i+1]!="off") {
                mxexit = -MAX_INT;
                mnexit = MAX_INT;
            }
            mxexit = max(segs[i].a, mxexit);
            mnexit = min(segs[i].b, mnexit);
        }
    }
    cout << max(mxcur-mnrec, 0) << " " << max(mncur-mxrec, 0) << endl << max(mxcur-mnexit, 0) << " " << max(mncur-mxexit, 0);
    return 0;
}