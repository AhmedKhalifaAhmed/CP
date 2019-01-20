#include <iostream>

using namespace std;

// Helper for each test case
void foo(){
  int N, M;
  cin >> N >> M;
  int**table_0 = new int*[N];
  int**table_1 = new int*[N;]

  for(int i=0; i<N; i++){
    table_0[i] = new int[M];
    table_1[i] = new int[M];
    for(int j=0; j<M; j++){
      cin >> table_0[i][j];

    }
  }

  for(int i=0; i<M; i++){
    table_1[0][i] = (table_0[0][i] < 4)? 0:table_0[0][i];
  }

  for(int i=1; i<N; i++){
    for(int j=0; j<M; j++){
      //
    }
  }

  for(int )

  for(int i=0; i<N; i++){
    delete[] table_0[i];
    delete[] table_1[i];
  }
  delete[] table_0;
  delete[] table_1;
}

// Main function
int main(){
  int T;
  cin >> T;
  while(T--){ foo(); }
  return 0;
}
