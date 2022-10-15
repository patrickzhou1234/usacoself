// http://www.usaco.org/index.php?page=viewproblem2&cpid=807
#include <iostream>

using namespace std;

int main() {
    int start, end, telX, telY, ct=2147483647;
    cin >> start >> end >> telX >> telY;
    if (abs(telX-start)+abs(telY-end)<ct) {
        ct = abs(telX-start)+abs(telY-end);
    }
    if (abs(telY-start)+abs(telX-end)<ct) {
        ct = abs(telY-start)+abs(telX-end);
    }
    if (abs(start-end)<ct) {
        ct = abs(start-end);
    }
    cout << ct;
    system("pause");
    return 0;
}