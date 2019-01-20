#include <iostream>
#include <algorithm>
using namespace std;

struct event{
  int i, j;
  bool operator < (const event& e1) const{
    return (i < e1.i);
  }
};

int main(){
  int n;
  cin >> n;
  event* arr = new event[n];
  for(int i=0; i<n; i++){
    cin >> arr[i].i >> arr[i].j;
  }
  sort(arr, arr+n);

  int count = 0;

  int end=arr[0].j;
  for(int i=1; i<n; i++){
    if(arr[i].j < end){
      count++;
    }else{
      end = arr[i].j;
    }
  }

  cout << count << endl;

  delete[] arr;
  return 0;
}
