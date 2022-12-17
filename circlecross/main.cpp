// http://www.usaco.org/index.php?page=viewproblem2&cpid=712
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    bool found;
    int i, j, m, sz=0;
    vector<char> ls;
    string inp;
    cin >> inp;
    for (i=0;i<inp.length();i++) {
        for (j=i+1;j<inp.length();j++) {
            if (inp[j]!=inp[i]) {
                found=false;
                for (m=0;m<ls.size();m++) {
                    if (ls[m]==inp[j]) {
                        ls.erase(ls.begin()+m);
                        found=true;
                    }
                }
                if (!found) {
                    ls.push_back(inp[j]);
                }
            } else {
                i=j;
                break;
            }
        }
        sz+=ls.size();
        ls.clear();
    }
    cout << sz;
    return 0;
}