// http://usaco.org/index.php?page=viewproblem2&cpid=1205
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, j, m, k;
    cin >> n;
    string blocks[n], words[n];
    vector<string> comb;
    string tmp;
    for (i=0;i<4;i++) {
        cin >> blocks[i];
    }
    for (i=0;i<n;i++) {
        cin >> words[i];
    }
    for (i=0;i<4;i++) {
        for (j=0;j<4;j++) {
            for (m=0;m<4;m++) {
                for (k=0;k<4;k++) {
                    if (i!=j && i!=m && i!=k && j!=m && j!=k && m!=k) {
                        tmp=to_string(i)+to_string(j)+to_string(m)+to_string(k);
                        comb.push_back(tmp);
                    }
                }
            }
        }
    }
    for (i=0;i<n;i++) {
        bool spelledword=false;
        for (j=0;j<comb.size();j++) {
            bool charfailed = false;
            for (m=0;m<words[i].length();m++) {
                bool fd=false;
                for (k=0;k<6;k++) {
                    if (blocks[int(comb[j].at(m))-48].at(k)==words[i].at(m)) {
                        fd=true;
                        break;
                    }
                }
                if (!fd) {
                    charfailed=true;
                    break;
                }
            }
            if (!charfailed) {
                spelledword=true;
                break;
            }
        }
        if (spelledword) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
for (i=0;i<4;i++) {
    for (j=0;j<4;j++) {
        for (m=0;m<4;m++) {
            for (k=0;j<4;k++) {
                if (i!=j && i!=m && i!=k && j!=m && j!=k && m!=k) {

                }
            }
        }
    }
}
*/