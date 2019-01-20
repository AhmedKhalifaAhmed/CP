#include <iostream>

using namespace std;

struct target{
  double x, y, p;
}

void foo(int N){
  target* targets = new target[N];
  for(int i=0; i<N; i++){
    target t = targets[i];
    cin >> t.x >> t.y >> t.p;
  }

  delete[] targets;
}

int main(){
  int N;
  while(cin >> N){
    foo(N);
  }
  return 0;
}
