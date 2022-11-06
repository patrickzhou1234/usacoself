// http://www.usaco.org/index.php?page=viewproblem2&cpid=508
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct searchvr {
    int cst, loc;
};

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    vector<searchvr> searchls;
    int a,b,n,i,j,m,tmpcst,tmpln, tmploc, mncst=MAX_INT,pscst=0;
    searchvr tmp;
    bool af=false, bf=false;
    cin >> a >> b >> n;
    for (i=0;i<n;i++) {
        pscst=0;
        cin >> tmpcst >> tmpln;
        for (j=0;j<tmpln;j++) {
            cin >> tmploc;
            for (m=0;m<searchls.size();m++) {
                if (tmploc==searchls[m].loc) {
                    af=true;
                    pscst=searchls[m].cst;
                }
            }
            if (tmploc == a) {
                af=true;
            }
            if (tmploc == b && af) {
                bf=true;
            } else if (af) {
                tmp.cst = tmpcst;
                tmp.loc = tmploc;
                searchls.push_back(tmp);
            }
        }
        if (af && bf) {
            mncst = min(mncst, tmpcst+pscst);
        }
        af=false;
        bf=false;
    }
    if (mncst==MAX_INT) {
        cout << -1;
        return 0;
    }
    cout << mncst;
    
    return 0;
}