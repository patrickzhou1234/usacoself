// http://www.usaco.org/index.php?page=viewproblem2&cpid=508
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct unit {
    int cst, ln;
    vector<int> locls;
};

struct searchunit {
    int cst, loc;
};

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int a,b,n,i,j,m,tmpcst,tmpln, tmploc, mncst=MAX_INT;
    unit matrix[n];
    vector<searchunit> searchls;
    searchunit tmpunit;
    bool af=false, bf=false;
    cin >> a >> b >> n;
    for (i=0;i<n;i++) {
        cin >> tmpcst >> tmpln;
        matrix[i].cst=tmpcst;
        matrix[i].ln=tmpln;
        for (j=0;j<tmpln;j++) {
            cin >> tmploc;
            matrix[i].locls.push_back(tmploc);
        }
    }
    for (i=0;i<n;i++) {
        af=false;
        bf=false;
        for (j=0;j<matrix[i].ln;j++) {
            if (matrix[i].locls[j]==a) {
                af=true;
            }
            if (af && matrix[i].locls[j]==b) {
                bf=true;
            } else if (af) {
                tmpunit.cst = matrix[i].cst;
                tmpunit.loc = matrix[i].locls[j];
                searchls.push_back(tmpunit);
            }
        }
        if (af && bf) {
            mncst = min(mncst, matrix[i].cst);
        }
    }
    for (i=0;i<n;i++) {
        af=false;
        bf=false;
        for (j=matrix[i].ln-1;j>=0;j--) {
            if (matrix[i].locls[j]==b) {
                bf=true;
            }
            for (m=0;m<searchls.size();m++) {
                if (bf && matrix[i].locls[j]==searchls[m].loc) {
                    mncst = min(mncst, matrix[i].cst+searchls[m].cst);
                }
            }
        }
    }
    if (mncst==MAX_INT) {
        cout << -1;
        return 0;
    }
    cout << mncst;
    
    return 0;
}