// http://www.usaco.org/index.php?page=viewproblem2&cpid=1204
#include <bits/stdc++.h>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, ct=0;
    cin >> n;
    int a[n], b[n];
    unordered_set <int> moved;
    for (i=0;i<n;i++) {
        cin >> a[i];
    }
    for (i=0;i<n;i++) {
        cin >> b[i];
    }
    for (i=0;i<n;i++) {
        while (moved.find(a[i-ct])!=moved.end()) {
            ct--;
        }
        if (b[i]!=a[i-ct]) {
            ct++;
            moved.insert(b[i]);
        }
    }
    cout << moved.size();
    return 0;
}