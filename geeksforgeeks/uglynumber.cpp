//https://practice.geeksforgeeks.org/problems/number-that-are-not-divisible/0
#include <iostream>
#include <unordered_map>

using namespace std;

const int divisors[] = {2, 3, 5, 7};

unordered_map<string, long long> dp;
long long n;

void run(int a, int b, int c, int d){
  string key = ((string)a) + "-" + ((string)b) + "-" + ((string)c) + "-" + ((string)d);
  if(dp.contains(key))
    return;
  long long val = pow(2, a)+pow(3, b)+pow(5, c)+pow(7, d);
  if(val > n)
    return;
  dp[key] = val;
  run(a+1, b, c, d);
  run(a, b+1, c, d);
  run(a, b, c+1, d);
  run(a, b, c, d+1);
}

int main(){
  dp.reserve(53040);
  int T;
  cin >> T;
  while(T--){
    dp.clear();
    cin >> n;
    run(0, 0, 0, 0);
    cout << divisors.size();
  }
  return 0;
}
