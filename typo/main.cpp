// http://www.usaco.org/index.php?page=viewproblem2&cpid=188
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);
    string ln;
    cin >> ln;
    int ct=0, i, j, ans=0;
    for (i=0;i<ln.length();i++) {
        if (ln[i]=='(') {
            ct++;
        } else {
            ct--;
        }
        if (ct<0) {
            break;
        }
    }
    if (i!=ln.length()) {
        for (j=i;j>=0;j--) {
            if (ln[j]==')') {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    ct=0;
    for (i=ln.length()-1;i>=0;i--) {
        if (ln[i]==')') {
            ct++;
        } else {
            ct--;
        }
        if (ct<0) {
            break;
        }
    }
    for (j=i;j<ln.length();j++) {
        if (ln[j]=='(') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

/*
// http://www.usaco.org/index.php?page=viewproblem2&cpid=188
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);
    string ln;
    cin >> ln;
    int ct=0, i, j, ans=0;
    for (i=0;i<ln.length();i++) {
        if (ln[i]=='(') {
            ct++;
        } else {
            ct--;
        }
        if (ct<0) {
            break;
        }
    }
    if (i!=ln.length()) {
        for (i=i;i>=0;i--) {
            if (ln[j]==')') {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    ct=0;
    for (i=ln.length()-1;i>=0;i--) {
        if (ln[i]==')') {
            ct++;
        } else {
            ct--;
        }
        if (ct<0) {
            break;
        }
    }
    for (;i<ln.length();i++) {
        if (ln[j]=='(') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
*/