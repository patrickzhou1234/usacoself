// http://www.usaco.org/index.php?page=viewproblem2&cpid=1155
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int i, j, m, gct, hct, ct=0;
    cin >> i;
    string inp, tmp;
    cin >> inp;
    for (i=2;i<inp.length();i++) {
        for (j=0;j<inp.length()-i;j++) {
            tmp=inp.substr(j, j+i);
            gct=0;
            hct=0;
            for (m=0;m<tmp.length();m++) {
                if (tmp[m]=='G') {
                    gct++;
                }
                if (tmp[m]=='H') {
                    hct++;
                }
            }
            if (gct==1 || hct==1) {
                ct++;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}