// http://www.usaco.org/index.php?page=viewproblem2&cpid=1228
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct matrix {
    char comp;
    int pi;
};

int main() {
    int n, i, j, maxp=-1, minp=MAX_INT, ct=0, minct=MAX_INT, bp;
    cin >> n;
    matrix arr[n];
    for (i=0;i<n;i++) {
        cin >> arr[i].comp >> arr[i].pi;
        maxp = max(arr[i].pi, maxp);
        minp = min(arr[i].pi, minp);
    }
    for (j=0;j<n;j++) {
        bp = arr[j].pi;
        ct=0;
        for (i=0;i<n;i++) {
            if (arr[i].comp == 'L' && bp>arr[i].pi) {
                ct++;
            } else if (arr[i].comp == 'G' && bp<arr[i].pi) {
                ct++;
            }
        }
        minct = min(minct, ct);
    }
    cout << minct;
    system("pause");
    return 0;
}