#include <iostream>
#define INF ((int)1e9);

using namespace std;

struct SegTree{
  int N;
  int *arr, *sTree, *lazy;
  SegTree(int *arr, int size){
    this->arr = arr;
    N = size-1;
    sTree = new int[N<<1];
    lazy = new int[N<<1];
    for(int i=0; i<N<<1; i++){
      sTree[i] = INF;
      lazy[i] = INF; 
    }
    build(1, 1, N);
  }

  void build(int node, int b, int e){
    if(b == e){
      sTree[node] = arr[b];
    } else {
      int mid = (b + e) >> 1;
      build(node<<1, b, mid);
      build(node<<1|1, mid+1, e);
      sTree[node] = min(sTree[node<<1], sTree[node<<1|1]);
    }
  }

  void update_range(int i, int j, int val){
    if(j >= i){
      update_range(1, 1, N, i, j, val);
    } else {
      update_range(1, 1, N, i, N, val);
      update_range(1, 1, N, 0, j, val);
    }
  }

  void propagate(int node, int b, int mid, int e){
    lazy[node<<1] += lazy[node];
    lazy[node<<1|1] += lazy[node];
    sTree[node<<1] += (mid-b+1)*lazy[node];
    sTree[node<<1|1] += (e-mid)*lazy[node];
    lazy[node] = 0;
  }

  void update_range(int node, int b, int e, int i, int j, int val){
    if(i > e || j < b){
      return;
    } else {
      int mid = (b + e) >> 1;
      propagate(node, b, mid, e);
      update_range(node<<1, b, mid, i, j, val);
      update_range(node<<1|1, mid+1, e, i, j, val);
      sTree[node] = min(sTree[node<<1], sTree[node<<1|1]);
    }
  }

    int query(int i, int j){
      if(i <= j){
        return query(1, 1, N, i, j);
      } else {
        return min(query(1, 1, N, i, N), query(1, 1, N, 0, j));
      }
    }

    int query(int node, int b, int e, int i, int j){
      if(i > e || j < b){
        return 0;
      } else if(b >= i && e <= j){
        return sTree[node];
      }
      int mid = (b + e) >> 1;
      propagate(node, b, mid, e);
      int q1 = query(node<<1, b, mid, i, j);
      int q2 = query(node<<1|1, mid+1, e, i, j);
      return min(q1, q2);
    }
};

int main(){
  return 0;
}