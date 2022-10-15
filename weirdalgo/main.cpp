// https://cses.fi/problemset/task/1068

#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    cout << n << " ";
    while (true) {
        if (n==1) {
            system("pause");
            return 0;
        }
        if (n%2==0) {
            n/=2;
        } else {
            n=n*3+1;
        }
        cout << n << " ";
    }
    system("pause");
    return 0;
}