// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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

// recursive
class Solution {
 public:
  vector<int> res;
  void _preorder(Node* root) {
    if (!root) return;
    res.push_back(root->val);
    for (auto n : root->children)
      _preorder(n);
  }
  vector<int> preorder(Node* root) {
    _preorder(root);
    return res;
  }
};

// iterative
class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> res;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
      Node* curr = st.top();
      st.pop();
      res.push_back(curr->val);
      for (auto it = curr->children.rbegin(); it != curr->children.rend(); it++) {
        st.push(*it);
      }
    }

    return res;
  }
};