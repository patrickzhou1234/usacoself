// http://www.usaco.org/index.php?page=viewproblem2&cpid=1229
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct klist {
    int l, m;
    vector<int> vec;
};

int main() {
    int n, i, k, j, tmp;
    cin >> n;
    int a[n];
    for (i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >> k;
    klist mat[k];
    for (i=0;i<k;i++) {
        cin >> mat[i].l >> mat[i].m;
        for (j=0;j<mat[i].m;j++) {
            cin >> tmp;
            mat[i].vec.push_back(tmp);
        }
    }
    cout << n << "\n";
    for (i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << "\n" << k << "\n";
    for (i=0;i<k;i++) {
        cout << mat[i].l << " " << mat[i].m << " ";
        for (j=0;j<mat[i].m;j++) {
            cout << mat[i].vec[j] << " ";
        }
        cout << "\n";
    }
    
    system("pause");
    return 0;
}