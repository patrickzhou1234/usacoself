// http://www.usaco.org/index.php?page=viewproblem2&cpid=1203
#include <iostream>

using namespace std;


int main() {
    int T;
    cin >> T;

  for (int t=0;t<T;t++) {
       int n; 
       cin >> n;
    
       int A[n];
       for (int j=0;j<n;j++) {
            cin >> A[j];
        }
    
    
        for (int last_added=1;last_added<=n; last_added++) {
           int desired_sum = 0;
           for (int i=0; i<last_added; ++i)
             desired_sum += A[i];
          
           int cnt = 0; 
           int idx = 0;
           int tmp_sum;
          
          //  1 2 3 1 1
          
          
           while(idx<n){
              tmp_sum = A[idx++];
              while (idx<n && tmp_sum < desired_sum){
                 tmp_sum += A[idx++];
                 cnt++;  // we do not need to 'count' for ffirst element
              }
              if (tmp_sum != desired_sum) break;
           }
          
           if (tmp_sum == desired_sum){
                 cout << cnt << endl;
				break; 
           }
          
          
        } // last_added
    
    
  }
    system("pause");
    return 0;
}