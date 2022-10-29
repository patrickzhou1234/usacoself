// http://www.usaco.org/index.php?page=viewproblem2&cpid=809
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n, i;
    cin >> n;
    int arr[n];
    int ans = 0;
    for (i=0;i<n;i++) {
        cin >> arr[i];
    }
    arr[0]=0;
    for (i=n-2;i>=0;i--) {
        if (arr[i+1]>0) {
          if (arr[i] != -1){  
          	if (arr[i] != arr[i+1]-1) {
              ans = -1;
              break;
            }
          }
          else {
            arr[i] = arr[i+1]-1;
          }
        }
    }
    if (ans == -1){
      cout << ans;
      return 0;
    }
     
    int min0=0, max0=0;
    for (i=0; i<n; ++i){
      if (arr[i]==0) { min0++; max0++;}
      if (arr[i]==-1) max0++;
    }
  
    cout << min0 << " " << max0;
    system("pause");
    return 0;
}