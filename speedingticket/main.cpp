// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
#include <iostream>

using namespace std;

// used advanced 'technique'
// structure, array of structure.

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;
  
    int l,s;
    int mile = 0;
    int road[100];
    for (int i=0; i<n; ++i){
       cin >> l >> s;
       for (int j=0; j<l; ++j){
         road[mile++] = s;
       }
    }
  
    mile = 0;
    int max_speed  = 0;
    for (int i=0; i<m; ++i){
       cin >> l >> s;
       for (int j=0; j<l ; ++j ){
         max_speed = max (max_speed, s-road[mile++]); 
       }
    }
  
    cout << max_speed << endl;
  
   return 0;

}