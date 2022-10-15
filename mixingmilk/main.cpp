// http://www.usaco.org/index.php?page=viewproblem2&cpid=855
#include <iostream>

using namespace std;

struct buck {
    long long capacity, milk;
};

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int i, curind, nextind;
    buck matrix[3];
    for (i=0;i<3;i++) {
        cin >> matrix[i].capacity >> matrix[i].milk;
    }
    for (i=0;i<100;i++) {
        curind = i%3;
        nextind = curind+1;
        if (nextind==3) {
            nextind=0;
        }
        if (matrix[curind].milk<=matrix[nextind].capacity-matrix[nextind].milk) {
            matrix[nextind].milk+=matrix[curind].milk;
            matrix[curind].milk=0;
        } else if (matrix[curind].milk>matrix[nextind].capacity-matrix[nextind].milk) {
            matrix[curind].milk-=(matrix[nextind].capacity-matrix[nextind].milk);
            matrix[nextind].milk=matrix[nextind].capacity;
        }
    }
    for (i=0;i<3;i++) {
        cout << matrix[i].milk << endl;
    }
    system("pause");
    return 0;
}