// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive
class Solution {
 public:
  vector<int> res;
  void preorder(TreeNode *root) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
  }
  vector<int> preorderTraversal(TreeNode *root) {
    preorder(root);
    return res;
  }
};

// iterative
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (!root) return {};
  
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *curr = st.top();
      st.pop();
      res.push_back(curr->val);
      if (curr->right) st.push(curr->right);
      if (curr->left) st.push(curr->left);
    }
    return res;
  }
};
