// http://www.usaco.org/index.php?page=viewproblem2&cpid=858
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INT 2147483647

int n, m, c;
int t[100000];

bool isValid(int T) {
    /*
    int i, j, groupct=0;
    for (i=0;i<n;i++) {
        j=0;
        while (i+j<n && t[i+j]-t[i]<=T && j<=c) {
            j++;
        }
        groupct++;
        i+=j;
    }
    if (groupct<=m) {
        return true;
    }
    return false;
    */
   int passengers = 0;
   int busses = 0;
   int cow_num = 0;
   while (cow_num<n && busses<m){
     int t_start = t[cow_num];
     passengers = 0;
     while (cow_num<n && passengers<c && t[cow_num]-t_start <= T){
       cow_num++;
       passengers++;
     }
     busses++;
   }
   if (cow_num == n) return true;
   return false;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int i;
    cin >> n >> m >> c;
    for (i=0;i<n;i++) {
        cin >> t[i];
    }
    sort(t, t+n);
    // Exhaustive search
    /*
    i=1;
    while(!isValid(i)) {
        i++;
    }
    
    */
  
    // binary search
    int left = 0;
    int right = t[n-1];
    int ans = -1;
    while (left <= right) {
      int mid = (left+right)/2; // integer division
      if (isValid(mid)){
          right = mid-1;
          ans = mid;
      }
      else{
        left = mid+1;
      }
      
    }
    cout << ans;
    system("pause");
    return 0;
}