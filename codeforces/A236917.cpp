#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct Node{
  Node *a, *b; // Parent, left child, right child
  int l, r; // left boundary, right boundary
  long long v; // Value
  bool op; // Operation
  // Constructor
  Node(Node *a, Node *b, int l, int r, long long v, bool op){
    this->a = a;
    this->b = b;
    this->l = l;
    this->r = r;
    this->v = v;
    this->op = op;
  }

  Node* get_child(long long* arr, int begin, int end){
    // reached a leaf
    if(begin == end){
      Node new_node(nullptr, nullptr, begin, begin, arr[begin], true);
      Node* output = &new_node;
      return output;
    }
    int mid = (begin + end) / 2;
    Node *a = get_child(arr, begin, mid);
    Node *b = get_child(arr, mid+1, end);
    if(a->op){
      Node new_node(a, b, begin, end, a->v | b->v, !op);
      Node* output = &new_node;
      return output;
    } else{
      Node new_node(a, b, begin, end, a->v ^ b->v, !op);
      Node* output = &new_node;
      return output;
    }
  }

  void print_tree(Node *node){
    if(node->a == nullptr){
      cout << node->v << " ";
      return;
    }
    node->print_tree(node->a);
    node->print_tree(node->b);
  }
};

//Code starts here
int main(){
  int n, m;
  cin >> n >> m;

  long long *arr = new long long[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  Node* root;
  root = root->get_child(arr, 0, (int)(pow(2, n)-1));
  root->print_tree(root);


  delete[] arr;
  return 0;
}
