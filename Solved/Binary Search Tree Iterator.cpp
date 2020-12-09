// https://leetcode.com/problems/binary-search-tree-iterator/

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

class BSTIterator {
 private:
  stack<TreeNode *> st;

  void traverseLeft(TreeNode *node) {
    while (node) {
      st.push(node);
      node = node->left;
    }
  }

 public:
  BSTIterator(TreeNode *root) {
    traverseLeft(root);
  }
  int next() {
    TreeNode *node = st.top();
    st.pop();
    if (node->right) traverseLeft(node->right);
    return node->val;
  }

  bool hasNext() {
    return st.size() > 0;
  }
};