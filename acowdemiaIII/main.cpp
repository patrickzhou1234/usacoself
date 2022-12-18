// http://www.usaco.org/index.php?page=viewproblem2&cpid=1133
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, m, i, j, cwct;
    cin >> n >> m;
    char mat[n][m];
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cin >> mat[i][j];
        }
    }
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (mat[i][j]=='G') {
                cwct=0;
                if (i+1<n && mat[i+1][j]=='C') {
                    cwct++;
                }
                if (i-1>=0 && mat[i-1][j]=='C') {
                    cwct++;
                }
                if (j+1<m && mat[i][j+1]=='C') {
                    cwct++;
                }
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}