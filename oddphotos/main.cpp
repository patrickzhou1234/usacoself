// http://www.usaco.org/index.php?page=viewproblem2&cpid=1084
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, inp, even=0, odd=0;
    cin >> n;
    for (i=0;i<n;i++) {
        cin >> inp;
        if (inp%2==0) {
            even++;
        } else {
            odd++;
        }
    }
    while(odd>even) {
        odd-=2;
        even++;
    }
    if (even>odd+1) {
        even=odd+1;
    }
    cout << even+odd;
    system("pause");
    return 0;
}