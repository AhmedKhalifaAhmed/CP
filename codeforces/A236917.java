package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class A236917 {

  public static void main(String[] args) throws IOException {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    String[] line = bf.readLine().split(" ");
    int n = Integer.parseInt(line[0]);
    int m = Integer.parseInt(line[1]);
    long[] arr = new long[(int) Math.pow(2, n)];
    line = bf.readLine().split(" ");
    for(int i=0; i<arr.length; i++){
      arr[i] = Long.parseLong(line[i]);
    }
    Node root;
    root = getChildren(arr, 0, arr.length - 1);
    for (int i = 0; i < m; i++) {
      line = bf.readLine().split(" ");
      int p = Integer.parseInt(line[0])-1;
      long b = Long.parseLong(line[1]);
      updateTree(root, p, b);
      pw.println(root.value);
    }

    pw.flush();
    pw.close();
    bf.close();
  }

  public static void printTree(Node node) {
    if (node.childA == null) {
      System.out.print(node.value + " ");
      return;
    }
    printTree(node.childA);
    printTree(node.childB);
  }

  public static void updateTree(Node node, int p, long b) {
    if (node.begin == node.end) {
      node.value = b;
      return;
    }
    int mid = (node.begin + node.end) / 2;
    if (p > mid) {
      updateTree(node.childB, p, b);
    } else {
      updateTree(node.childA, p, b);
    }
    if (node.operator) {
      node.value = node.childA.value ^ node.childB.value;
    } else {
      node.value = node.childA.value | node.childB.value;
    }
  }

  public static Node getChildren(long[] arr, int begin, int end) {
    if (begin == end) {
      Node newNode = new Node(null, null, arr[begin], begin, end, true);
      return newNode;
    }
    int mid = (begin + end) / 2;
    Node a = getChildren(arr, begin, mid);
    Node b = getChildren(arr, mid + 1, end);
    Node newNode;
    if (a.operator) {
      return new Node(a, b, a.value | b.value, begin, end, !a.operator);
    }
    return new Node(a, b, a.value ^ b.value, begin, end, !a.operator);
  }

  static class Node {
    Node childA, childB;
    long value;
    int begin, end;
    boolean operator;

    Node(Node childA, Node childB, long value, int begin, int end, boolean operator) {
      this.childA = childA;
      this.childB = childB;
      this.value = value;
      this.begin = begin;
      this.end = end;
      this.operator = operator;
    }
  }
}