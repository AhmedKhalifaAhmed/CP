package structs;

public class SegTree{
    int N;
    int[] arr, sTree, lazy;

    SegTree(int[] arr){
      this.arr = arr;
      N = arr.length - 1;
      sTree = new int[N<<1];
      lazy = new int[N<<1];
      build(1, 1, N);
    }

    void build(int node, int b, int e){
      if(b == e){
        sTree[node] = arr[b];
      } else {
        int mid = (b + e) >> 1;
        int left = node << 1;
        int right = node << 1 | 1;
        build(left, b, mid);
        build(right, mid+1, e);
        sTree[node] = sTree[left] + sTree[right];

      }
    }

    void update_point(int index, int val){
      index += N-1;
      sTree[index] +=val;
      int left, right;
      while(index > 1){
        index >>= 1;
        left = index << 1;
        right = index << 1|1;
        sTree[index] = sTree[left] + sTree[right];
      }
    }

    void update_range(int i, int j, int val){
      update_range(1, 1, N, i, j, val);
    }

    void update_range(int node, int b, int e, int i, int j, int val){
      if(i > e || j < b){
        return;
      }
      if(b >= i && e <= j){
        sTree[node] += (e - b + 1) * val;
        lazy[node] += val;
      } else {
        int mid = (b + e) >> 1;
        int left = node << 1;
        int right = (node << 1) | 1;
        propagate(node, b, mid, e);
        update_range(left, b, mid, i, j, val);
        update_range(right, mid+1, e, i, j, val);
      }
    }

    void propagate(int node, int b, int mid, int e){
      int left = node << 1;
      int right = (node << 1) | 1;
      lazy[left] += lazy[node];
      lazy[right] += lazy[node];
      sTree[left] += (mid - b + 1) * lazy[node];
      sTree[right] += (e - mid) * lazy[node];
      lazy[node] = 0;
    }

    int query(int i, int j){
      return query(1, 1, N, i, j);
    }

    int query(int node, int b, int e, int i, int j){
      if(i > e || j < b){
        return 0;
      }
      if(b >= i && e <= j){
        return sTree[node];
      }
      int mid = (b + e) >> 1;
      propagate(node, b, mid, e);
      int q1 = query(node<<1, b, mid, i, j);
      int q2 = query(node<<1|1, mid+1, e, i, j);
      return q1 + q2;
    }
  }