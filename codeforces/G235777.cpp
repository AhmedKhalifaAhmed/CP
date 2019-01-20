#include <iostream>

using namespace std;

struct swap{
  int i, j;
}

int main(){

  int n, m;
  cin >> n >> m;
  int * arr = new int[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  swap* swaps = new swap[m];
  for(int i=0; i<m; i++){
    cin >> swaps[m].i >> swaps[m].j;
  }

  

  delete[] arr;
  delete[] swaps;
  return 0;
}
