// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

// iterative
class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> st;

    while (root != NULL || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      k--;
      if (k == 0) break;
      root = root->right;
    }
    return root->val;
  }
};

// recursive
class Solution {
 public:
  void inorder(TreeNode *root, int &ans, int &k) {
    if (!root) return;
    inorder(root->left, ans, k);
    k--;
    if (k == 0) {
      ans = root->val;
    }
    inorder(root->right, ans, k);
  }
  int kthSmallest(TreeNode *root, int k) {
    int ans = -1;
    inorder(root, ans, k);
    return ans;
  }
};