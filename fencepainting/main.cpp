// http://www.usaco.org/index.php?page=viewproblem2&cpid=567
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d, mn,mx, ans;
    cin >> a >> b >> c >> d;
    if (a<=c && b>=d) {
        ans = b-a;
    } else if (c<=a && d>=b) {
        ans = d-c;
    }
    else if (c<a && d>=a) {
        ans=b-c;
    }
    else if (a<c && b>=c) {
        ans=d-a;
    }
    else {
        ans = (b-a)+(d-c);
    }
    cout << ans;
    system("pause");
    return 0;
}