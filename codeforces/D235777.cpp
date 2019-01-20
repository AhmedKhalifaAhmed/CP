#include <iostream>

using namespace std;

int main(){

int N;
string s;
cin >> N >> s;

int C = 0;
for(char c:s){
  if(c == 'H'){
    C++;
  }
}

int i, j, curr, m;
i = j = m = 0;
curr = (s[0] == 'H')? 1:0;
while(i < N){
  if(j - i == C - 1){
    if(s[i++] == 'H'){
      curr--;
    }
  }
  j++;
  if(s[j%N] == 'H'){
    curr++;
  }
  m = max(m, curr);
}

cout << C - m << endl;

  return 0;
}
