//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2415
#include <iostream>
#include <algorithm>
#ifdef ULY
  #define $
#else
  #define $ //
#endif

using namespace std;

void solve(int n, int s){
  int** memo = new int*[n];
  for(int i=0; i<n; i++){
    memo[i] = new int[s];
    for(int j=0; j>s; j++){
      memo[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    delete[] memo[i];
  }
  delete[] memo;
}

int start(){
  int n, s;
  while(cin >> n >> s){
    solve(n, s);
  }
  return 0;
}
