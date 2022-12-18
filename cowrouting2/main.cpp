// http://www.usaco.org/index.php?page=viewproblem2&cpid=506
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

struct route {
    int cst, ln;
    vector<int> rt;
};

struct loc {
    int cst, lc;
};

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);
    int a,b,n,i,j,m,tmploc, mncst=MAX_INT, afi,cstref;
    bool af, bf;
    cin >> a >> b >> n;
    route mat[n];
    vector<loc> searchls;
    loc tmplc;
    for (i=0;i<n;i++) {
        cin >> mat[i].cst >> mat[i].ln;
        for (j=0;j<mat[i].ln;j++) {
            cin >> tmploc;
            mat[i].rt.push_back(tmploc);
        }
    }
    for (i=0;i<n;i++) {
        af=false;
        bf=false;
        for (j=0;j<mat[i].ln;j++) {
            if (mat[i].rt[j]==a) {
                af=true;
                afi=j;
            }
            if (af && mat[i].rt[j]==b) {
                bf=true;
            }
        }
        if (af) {
            if (bf) {
                mncst = min(mncst, mat[i].cst);
            } else {
                for (j=afi+1;j<mat[i].ln;j++) {
                    tmplc.cst=mat[i].cst;
                    tmplc.lc=mat[i].rt[j];
                    searchls.push_back(tmplc);
                }
            }
        }
    }
    for (i=0;i<n;i++) {
        af=false;
        bf=false;
        cstref=MAX_INT;
        for (j=0;j<mat[i].ln;j++) {
            for (m=0;m<searchls.size();m++) {
                if (mat[i].rt[j]==searchls[m].lc && searchls[m].cst<cstref && !bf) {
                    af=true;
                    cstref=searchls[m].cst;
                }
            }
            if (af && mat[i].rt[j]==b) {
                bf=true;
            }
        }
        cstref+=mat[i].cst;
        if (af && bf) {
            mncst=min(mncst, cstref);
        }
    }
    if (mncst==MAX_INT) {
        mncst=-1;
    }
    cout << mncst;
    return 0;
}