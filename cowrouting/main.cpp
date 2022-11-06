// http://www.usaco.org/index.php?page=viewproblem2&cpid=507
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int a,b,n,i,j,tmpcst,tmpln, tmploc, mncst=MAX_INT;
    bool af=false, bf=false;
    cin >> a >> b >> n;
    for (i=0;i<n;i++) {
        cin >> tmpcst >> tmpln;
        for (j=0;j<tmpln;j++) {
            cin >> tmploc;
            if (tmploc == a) {
                af=true;
            }
            if (tmploc == b && af) {
                bf=true;
            }
        }
        if (af && bf) {
            mncst = min(mncst, tmpcst);
        }
        af=false;
        bf=false;
    }
    cout << mncst;
    return 0;
}