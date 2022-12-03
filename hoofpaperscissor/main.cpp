// http://www.usaco.org/index.php?page=viewproblem2&cpid=688
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct match {
    int a, b;
};

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, i, ct=-1, tmpct=0;
    cin >> n;
    match x[n], y[n], z[n];
    for (i=0;i<n;i++) {
        cin >> x[i].a >> x[i].b;
    }
    for (i=0;i<n;i++) {
        if (x[i].a==1) {
            y[i].a=2;
        } else if (x[i].a==2) {
            y[i].a=1;
        } else {
            y[i].a=x[i].a;
        }
        if (x[i].b==1) {
            y[i].b=2;
        } else if (x[i].b==2) {
            y[i].b=1;
        } else {
            y[i].b=x[i].b;
        }
    }
    for (i=0;i<n;i++) {
        if (x[i].a==1) {
            z[i].a=3;
        } else if (x[i].a==3) {
            z[i].a=1;
        } else {
            z[i].a=x[i].a;
        }
        if (x[i].b==1) {
            z[i].b=3;
        } else if (x[i].b==3) {
            z[i].b=1;
        } else {
            z[i].b=x[i].b;
        }
    }
    for (i=0;i<n;i++) {
        if ((x[i].a==1 && x[i].b==2) || (x[i].a==2 && x[i].b==3) || (x[i].a==3 && x[i].b==1)) {
            tmpct++;
        }
    }
    ct = max(tmpct, ct);
    tmpct=0;
    for (i=0;i<n;i++) {
        if ((y[i].a==1 && y[i].b==2) || (y[i].a==2 && y[i].b==3) || (y[i].a==3 && y[i].b==1)) {
            tmpct++;
        }
    }
    ct = max(tmpct, ct);
    tmpct=0;
    for (i=0;i<n;i++) {
        if ((z[i].a==1 && z[i].b==2) || (z[i].a==2 && z[i].b==3) || (z[i].a==3 && z[i].b==1)) {
            tmpct++;
        }
    }
    ct = max(tmpct, ct);
    cout << ct;
    system("pause");
    return 0;
}