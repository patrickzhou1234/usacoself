// http://www.usaco.org/index.php?page=viewproblem2&cpid=987
#include <string>
#include <iostream>

using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k, i, charcount=0;
    cin >> n >> k;
    string essay[n], outputstr;
    for (i=0;i<n;i++) {
        cin >> essay[i];
    }
    for (i=0;i<n;i++) {
        if (charcount+essay[i].length()>k) {
            outputstr.erase(outputstr.size() - 1);
            outputstr+="\n";
            charcount=0;
            i--;
        } else {
            outputstr+=essay[i]+" ";
            charcount+=essay[i].length();
            if (i==n-1) {
                outputstr.erase(outputstr.size() - 1);
            }
        }
    }
    cout << outputstr;
    system("pause");
    return 0;
}