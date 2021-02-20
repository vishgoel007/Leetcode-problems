// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3568/

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

// using inorder
class Solution {
 public:
  bool inorder(TreeNode *root, TreeNode **prev) {
    if (!root) return true;

    bool left = inorder(root->left, prev);
    if (!left) return false;

    if (prev && (*prev)->val >= root->val) return false;
    *prev = root;

    return inorder(root->right, prev);
  }
  bool isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr;
    return inorder(root, &prev);
  }
};

// using iterative inorder
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    TreeNode *prev = nullptr;
    stack<TreeNode *> st;

    while (root != nullptr || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      TreeNode *curr = st.top();
      st.pop();
      if (prev && prev->val >= curr->val) return false;
      prev = curr;
      root = curr->right;
    }
    return true;
  }
};