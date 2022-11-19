// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, j, even=0, odd=0, ct=0, tmpval;
    bool ev=true;
    cin >> n;
    vector<int> a;
    for (i=0;i<n;i++) {
        cin >> tmpval;
        a.push_back(tmpval);
    }
    for (i=0;i<n;i++) {
        if (a[i]%2==0) {
            even++;
        } else {
            odd++;
        }
    }
    even=0;
    odd=0;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (i%2==0 && j%2==0 && ev) {
                even++;
                ev=false;
                if (j>=i) {
                    a.erase(a.begin()+i, a.begin()+i+1);
                    a.erase(a.begin()+j, a.begin()+j+1);
                } else {
                    a.erase(a.begin()+j, a.begin()+j+1);
                    a.erase(a.begin()+i, a.begin()+i+1);
                }
            } else if (i%2!=0 && j%2!=0 && ev) {
                even++;
                ev = false;
                if (j>=i) {
                    a.erase(a.begin()+i, a.begin()+i+1);
                    a.erase(a.begin()+j, a.begin()+j+1);
                } else {
                    a.erase(a.begin()+j, a.begin()+j+1);
                    a.erase(a.begin()+i, a.begin()+i+1);
                }
            } else if (i%2!=0 && j%2==0 && !ev) {
                odd++;
                ev = true;
                if (j>=i) {
                    a.erase(a.begin()+i, a.begin()+i+1);
                    a.erase(a.begin()+j, a.begin()+j+1);
                } else {
                    a.erase(a.begin()+j, a.begin()+j+1);
                    a.erase(a.begin()+i, a.begin()+i+1);
                }
            } else if (i%2==0 && j%2!=0 && !ev) {
                odd++;
                ev = true;
                if (j>=i) {
                    a.erase(a.begin()+i, a.begin()+i+1);
                    a.erase(a.begin()+j, a.begin()+j+1);
                } else {
                    a.erase(a.begin()+j, a.begin()+j+1);
                    a.erase(a.begin()+i, a.begin()+i+1);
                }
            }
        }
    }
    cout << min(odd, even);
    system("pause");
    return 0;
}