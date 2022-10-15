// http://www.usaco.org/index.php?page=viewproblem2&cpid=487

#include <iostream>
#include <limits.h>

using namespace std;

int main() {

    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n, i, maxdiff=INT_MIN;
    cin >> n;
    int arrX[n], arrY[n];
    for (i=0;i<n;i++) {
        cin >> arrX[i] >> arrY[i];
    }
    // for (int skip_point=1;skip_point<n-1;skip_point++) {
      
    //   int d = 0;
    //   int prev_point =0;
    //   for (i=1; i<n; ++i){
    //      if (i== skip_point) continue; 
    //      d += abs(arrX[i]-arrX[prev_point]) + abs(arrY[i]-arrY[prev_point]) ;
        
    //      prev_point = i;
    //   }
    //   distance = min(distance, d);
    // }

    for (int skip_point=1;skip_point<n-1;skip_point++) {
      int skipdistance = abs(arrY[skip_point+1]-arrY[skip_point-1])+abs(arrX[skip_point+1]-arrX[skip_point-1]);
      int originaldistance = abs(arrY[skip_point]-arrY[skip_point-1])+abs(arrX[skip_point]-arrX[skip_point-1])+abs(arrY[skip_point]-arrY[skip_point+1])+abs(arrX[skip_point]-arrX[skip_point+1]);
      int diff = originaldistance-skipdistance;
      
      maxdiff = max(maxdiff, diff);
    }
    int d=0;
    for (i=1; i<n; ++i){
        d += abs(arrX[i]-arrX[i-1]) + abs(arrY[i]-arrY[i-1]);
    }
    
    cout << d-maxdiff;
    return 0;
}