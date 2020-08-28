// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> output;
    if (!root) return output;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> temp;
      for (int i = 0; i < size; i++) {
        Node* curr = q.front();
        q.pop();
        if (curr) temp.push_back(curr->val);
        for (int i = 0; i < curr->children.size(); i++) q.push(curr->children[i]);
      }
      output.push_back(temp);
    }
    return output;
  }
};