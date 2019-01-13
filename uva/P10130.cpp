//
// Created by medod on 1/13/2019.
//
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071
#include <iostream>
#include <algorithm>
#ifdef ULY
  #define $
#else
  #define $ //
#endif

using namespace std;

pair<int, int> *objs;// First = price, Second = weight

// Calculate the maximum value a member can carry and remove the objects from the array
long long run_2(int N, int W) {
  auto **memo = new long long *[N];
  for (int i = 1; i < N; i++) {
    memo[i] = new long long[W];
    for (int j = 0; j < W; j++) {
      memo[i][j] = 0;
    }
  }
  // Filling the memoization table
  // Setting the base for the bottom up traversal
  for (int w = 0; w < W; w++) {
    memo[0][w] = (objs[0].second <= w + 1) ? objs[0].first : 0;
  }
  // Completing the traversal
  for (int i=1; i < N; i++) {
    int curr_p = objs[i].first;
    int curr_w = objs[i].second;
    for (int w = 0; w < W; w++) {
      if (curr_w > w + 1) {
        memo[i][w] = memo[i-1][w];
      } else if (curr_w == w + 1) {
        memo[i][w] = max((long long) curr_p, memo[i-1][w]);
      } else {
        memo[i][w] = max(memo[i-1][w], curr_p + memo[i-1][w - curr_w]);
      }
    }
  }
$ for(int i=0; i<W; i++){
$   cout << i+1 << " - ";
$   for(int j=0; j<N; j++){
$      cout << memo[j][i] << " ";
$   }
$   cout << endl;
$ }
$  cout << endl;
$  cout << memo[N-1][W - 1] << endl;
  return memo[N-1][W - 1];
}

void run_1() {// Handle each test case
  int N;// Number of objects in the super market
  cin >> N;
  objs = new pair<int, int>[N];
  for (int i = 0; i < N; i++) {
    cin >> objs[i].first >> objs[i].second;
  }
  int G;// Number of people in the family
  cin >> G;
  int* people = new int[G];
  for(int i=0; i<G; i++){
    cin >> people[i];
  }
  sort(people, people+G);
  long long value = 0;
  for (int i = 0; i < G; i++) {
    value += run_2(N, people[i]);
  }
  cout << value << endl;
  delete[] objs;
  delete[] people;
}

int start() {
  int T;// Number of test cases
  cin >> T;
  for (int t = 0; t < T; t++) { run_1(); }
  return 0;
}

