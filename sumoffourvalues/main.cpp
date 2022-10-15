// https://cses.fi/problemset/task/1642

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,x,i;
    cin >> n >> x;
    int arr[n], testarr[n];
    for (i=0;i<n;i++) {
        cin >> arr[i];
        testarr[i] = arr[i];
    }
    sort(testarr, testarr+n);
    
    
    system("pause");
    return 0;
}