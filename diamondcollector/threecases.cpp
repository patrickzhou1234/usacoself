// http://www.usaco.org/index.php?page=viewproblem2&cpid=639
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k, i, j, ct=0;
    cin >> n >> k;
    int sizes[n];
    for (i=0;i<n;i++) {
        cin >> sizes[i];
    }
    sort(sizes, sizes+n);
    for (i=0;i<n;i++) {
        if(i!=0 && sizes[i]-sizes[0]>k) {
            break;
        } else {
            ct++;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}