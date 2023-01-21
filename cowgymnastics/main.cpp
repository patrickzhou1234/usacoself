// http://www.usaco.org/index.php?page=viewproblem2&cpid=963
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_INT 2147483647

struct combo {
    int a, b;
};

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n, i, j, m, ct=0;
    cin >> k >> n;
    int mat[k][n];
    for (i=0;i<k;i++) {
        for (j=0;j<n;j++) {
            cin >> mat[i][j];
        }
    }
    vector<combo> pairs;
    combo tmp;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) {
            if (i!=j) {
                tmp.a = i;
                tmp.b = j;
                pairs.push_back(tmp);
            }
        }
    }
    bool af;
    bool alltrue[k];
    for (i=0;i<pairs.size();i++) {
        memset(alltrue, false, sizeof(alltrue));
        for (j=0;j<k;j++) {
            af=false;
            for (m=0;m<n;m++) {
                if (mat[j][m]==pairs.at(i).a) {
                    af=true;
                }
                if (mat[j][m]==pairs.at(i).b && af) {
                    alltrue[j]=true;
                }
            }
        }
        for (j=0;j<k;j++) {
            if (!alltrue[j]) {
                break;
            }
        }
        if (j==k) {
            ct++;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}