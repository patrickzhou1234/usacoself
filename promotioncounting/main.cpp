// http://www.usaco.org/index.php?page=viewproblem2&cpid=591
#include <iostream>

using namespace std;

struct inp {
    long long before, after;  
};

int main() {
    long long i, val;
    long long ans[3];
    inp matrix[4];
    for (i=0;i<4;i++) {
        cin >> matrix[i].before >> matrix[i].after;
    }
    for (i=0;i<3;i++) {
        ans[i] = 0;
    }
    for (i=1;i<4;i++) {
        val = matrix[i].after-matrix[i].before;
        if (i==1) {
            ans[0]+=val;
        }
        if (i==2) {
            ans[0]+=val;
            ans[1]+=val;
        }
        if (i==3) {
            ans[0]+=val;
            ans[1]+=val;
            ans[2]+=val;
        }
    }
    for (i=0;i<3;i++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}