// http://www.usaco.org/index.php?page=viewproblem2&cpid=1157
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {

    int N, K;
    cin >> N >> K;

    char A[N][N];
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        cin >> A[r][c];
      }
    }

    int cnt = 0;

    if (K >= 1) {
      bool path = true;
      for (int c = 0; c < N; ++c) {
        if (A[0][c] == 'H') path = false;
      }
      for (int r = 0; r < N; ++r) {
        if (A[r][N - 1] == 'H') path = false;
      }
      if (path) cnt++;

      path = true;
      for (int r = 0; r < N; ++r) {
        if (A[r][0] == 'H') path = false;
      }
      for (int c = 0; c < N; ++c) {
        if (A[N - 1][c] == 'H') path = false;
      }

      if (path) cnt++;

    }

    if (K >= 2) {
      for (int turning_column = 1; turning_column < N - 1; ++turning_column) {
        bool path = true;
        for (int c = 0; c <= turning_column; ++c) {
          if (A[0][c] == 'H') path = false;
        }
        for (int r = 0; r < N; ++r) {
          if (A[r][turning_column] == 'H') path = false;
        }
        for (int c = turning_column; c < N; c++) {
          if (A[N - 1][c] == 'H') path = false;
        }
        if (path) cnt++;
      }
      for (int turning_row = 1; turning_row < N - 1; ++turning_row) {
        bool path = true;
        path = true;
        for (int r = 0; r <= turning_row; ++r) {
          if (A[r][0] == 'H') path = false;
        }
        for (int c = 0; c < N; ++c) {
          if (A[turning_row][c] == 'H') path = false;
        }
        for (int r = turning_row; r < N; r++) {
          if (A[r][N - 1] == 'H') path = false;
        }
        if (path) cnt++;
      }
    }

    if (K == 3) {
      for (int turning_column = 1; turning_column < N - 1; ++turning_column) {
        for (int turning_row = 1; turning_row < N - 1; ++turning_row) {
          bool path = true;
          for (int c = 0; c <= turning_column; ++c) {
            if (A[0][c] == 'H') path = false;
          }

          for (int r = 0; r < turning_row; ++r) {
            if (A[r][turning_column] == 'H') path = false;
          }

          for (int c = turning_column; c < N; c++) {
            if (A[turning_row][c] == 'H') path = false;
          }

          for (int r = turning_row; r < N; ++r) {
            if (A[r][N - 1] == 'H') path = false;
          }

          if (path) cnt++;
        }
      }

      // ADD going first on the rows
     for (int turning_row = 1; turning_row < N - 1; ++turning_row) {
	    for (int turning_column = 1; turning_column < N - 1; ++turning_column) {
          bool path = true;
          for (int r = 0; r < turning_row; ++r) {
            if (A[r][0] == 'H') path = false;
          }
          
          for (int c = 0; c <= turning_column; ++c) {
            if (A[turning_row][c] == 'H') path = false;
          }


          for (int r = turning_row; r < N; ++r) {
            if (A[r][turning_column] == 'H') path = false;
          }
          for (int c = turning_column; c < N; c++) {
            if (A[N-1][c] == 'H') path = false;
          }

          if (path) cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

/* if (k==2){
cnt = 0;
for (int turning_column=0; turning_column < n; ++ turning_column){
   
    path = true;
    for (int c = 0; c<=turning_column; ++c){
      if (A[0][c] == 'H') path = false; 
    }
    for (int r=0; r<n ; ++r){
      if (A[r][turning_column]=='H') path = false; 
    }
    for (int c = turning_colomn;c<n;c++) {
     	if (A[n-1][c]=='H') path=false; 
    }
  
    if (path) cnt++;
}



for (int turning_row=0; turning_row < n; ++ turning_row){
   
    path = true;
    for (int r = 0; r<=turning_row; ++r){
      if (A[r][0] == 'H') path = false; 
    }
    for (int c=0; c<n ; ++c){
      if (A[turning_row][c]=='H') path = false; 
    }
    for (int r = turning_row;r<n;r++) {
     	if (A[r][n-1]=='H') path=false; 
    }
  
    if (path) cnt++;
}

}

if (k==3){
// check for 3 turns
cnt = 0;
for (int turning_column=0; turning_column < n; ++ turning_column){
   for (int turning_row=0; turning_row < n; ++ turning_row){
    path = true;
    for (int c = 0; c<=turning_column; ++c){
      if (A[0][c] == 'H') path = false; 
    }

     for (int r=0; r<turning_row ; ++r){
      if (A[r][turning_column]=='H') path = false; 
    }
     
    for (int c = turning_colomn;c<n;c++) {
     	if (A[turning_row][c]=='H') path=false; 
    }

    for (int r=turning_row; r<n ; ++r){
      if (A[r][n-1]=='H') path = false; 
    }
 
     
    if (path) cnt++;
}

  // ADD going first on the rows
    for (int turning_column=0; turning_column < n; ++ turning_column){
     for (int turning_row=0; turning_row < n; ++ turning_row){
      path = true;
      for (int c = 0; c<=turning_column; ++c){
        if (A[0][c] == 'H') path = false; 
      }

       for (int r=0; r<turning_row ; ++r){
        if (A[r][turning_column]=='H') path = false; 
      }

      for (int c = turning_colomn;c<n;c++) {
          if (A[turning_row][c]=='H') path=false; 
      }

      for (int r=turning_row; r<n ; ++r){
        if (A[r][n-1]=='H') path = false; 
      }


      if (path) cnt++;
  }
  
}*/