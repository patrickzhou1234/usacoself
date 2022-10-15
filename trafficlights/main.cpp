// https://cses.fi/problemset/task/1163 unfinished

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long x,n,i,j,count=0;
    cin >> x >> n;
    long long lights[n], ans[n];
    for (i=0;i<n;i++) {
        lights[i] = 9223372036854775807;
    }
    for (i=0;i<n;i++) {
        cin >> lights[i];
        sort(lights, lights+n);
        count=0;
        if (lights[0]-0>count) {
            count = lights[0]-0;
        }
        for (j=0;j<=i;j++) {
            if (j>0) {
                if (lights[j]-lights[j-1]>count) {
                    count = lights[j]-lights[j-1];
                }
            }
        }
        if (x-lights[i]>count) {
            count=x-lights[i];
        }
        ans[i]=count;
    }
    for (i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    system("pause");
    return 0;
}