package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class B236917 {

  public static void main(String[] args) throws IOException {
    /*
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    int n = Integer.parseInt(bf.readLine());
    int[] arr = new int[n];
    String[] line = bf.readLine().split(" ");
    for(int i=0; i<n; i++){
      arr[i] = Integer.parseInt(line[i]);
    }
    Node root = getChildren(arr, 0, n-1);
    printTree(root);
    System.out.println();
    int m = Integer.parseInt(bf.readLine());
    for(int i=0; i<m; i++){
      line = bf.readLine().split(" ");
      int lf = Integer.parseInt(line[0]);
      int rg = Integer.parseInt(line[1]);
      Node subtree = getSubtree(root, lf, rg, n);
      if(line.length == 3){
        int v = Integer.parseInt(line[2]);
        increment(subtree, v);
      }else{
        pw.println(subtree.value);
      }
      printTree(root);
      System.out.println();
    }
    bf.close();
    pw.flush();
    pw.close();*/
    int[] arr = {0, 1, 2, 3, 4};
    Node root = getChildren(arr, 0, 4);
    printTree(root);
    System.out.println();
    Node sub = getSubtree(root, 1, 3, 5);
    printTree(sub);
    System.out.println();
  }

  private static Node getSubtree(Node root, int lf, int rg, int size){
    if(lf <= rg) {
      Node subtree = root;
      while (true) {
        int mid = (subtree.begin + subtree.end) / 2;
        if (subtree.begin > mid) {
          subtree = subtree.childB;
        } else if(subtree.end <= mid) {
          subtree = subtree.childA;
        } else{
          break;
        }
      }
      return subtree;
    } else{
      Node childA = getSubtree(root, lf, size-1, size);
      Node childB = getSubtree(root, 0, rg, size);
      return new Node(childA, childB, lf, rg, Math.min(childA.value, childB.value));
    }
  }

  private static void increment(Node node, int v) {
    if(node.begin == node.end){
      node.value += v;
      return;
    }
    increment(node.childA, v);
    increment(node.childB, v);
    node.value = Math.min(node.childA.value, node.childB.value);
  }

  private static void printTree(Node node){
    if(node.begin == node.end){
      System.out.print(node.value+" ");
      return;
    }
    printTree(node.childA);
    printTree(node.childB);
  }

  private static Node getChildren(int[] arr, int begin, int end) {
    if (begin == end) {
      return new Node(null, null, begin, end, arr[begin]);
    }
    int mid = (begin + end) / 2;
    Node a = getChildren(arr, begin, mid);
    Node b = getChildren(arr, mid + 1, end);
    return new Node(a, b, begin, end, Math.min(a.value, b.value));
  }

  static class Node {
    Node childA, childB;
    int begin, end, value;

    Node(Node childA, Node childB, int begin, int end, int value) {
      this.childA = childA;
      this.childB = childB;
      this.begin = begin;
      this.end = end;
      this.value = value;
    }
  }
}
