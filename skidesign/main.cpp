// http://www.usaco.org/index.php?page=viewproblem2&cpid=376
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int n;
    cin >> n;
    int elevation[n];
    for (int i=0;i<n;i++) {
        cin >> elevation[i];
    }

  int min_pay = 999999;
  for (int bottom_hill = 0;bottom_hill<=83;bottom_hill++) {
        int top_hill = bottom_hill+17;

        int pay=0;
    	for (int j=0; j<n; ++j) {
            if (elevation[j]<bottom_hill) {
                pay+=pow(bottom_hill-elevation[j], 2);
            } else if (elevation[j]>top_hill) {
                pay+=pow(elevation[j]-top_hill, 2);
            }
        }
    
    	min_pay = min(pay, min_pay);
    }
  
    cout << min_pay;
    return 0;
}