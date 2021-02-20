// https://leetcode.com/problems/house-robber-iii/

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

// using recursion
class Solution {
 public:
  int helper(TreeNode *root) {
    if (!root) return 0;

    int totalWithRoot = 0;

    // robbing root grand children
    if (root->left) {
      int a = helper(root->left->left);
      int b = helper(root->left->right);
      totalWithRoot += (a + b);
    }

    // robbing root grand children
    if (root->right) {
      int a = helper(root->right->right);
      int b = helper(root->right->left);
      totalWithRoot += (a + b);
    }

    return max(root->val + totalWithRoot, helper(root->left) + helper(root->right));
  }
  int rob(TreeNode *root) {
    return helper(root);
  }
};

// using top down dp
class Solution {
 public:
  unordered_map<int, int> dp;
  int helper(TreeNode *root) {
    if (!root) return 0;

    if (dp.find(root->val) != dp.end()) return dp[root->val];

    int totalWithRoot = 0;
    // robbing root grand children
    if (root->left) {
      int a = helper(root->left->left);
      int b = helper(root->left->right);
      totalWithRoot += (a + b);
    }

    // robbing root grand children
    if (root->right) {
      int a = helper(root->right->right);
      int b = helper(root->right->left);
      totalWithRoot += (a + b);
    }

    return dp[root->val] = max(root->val + totalWithRoot, helper(root->left) + helper(root->right));
  }
  int rob(TreeNode *root) {
    return helper(root);
  }
};

// using top down dp 2 (more optimized and reduced overlapping)
/*
    Input: [3,4,5,1,3,null,1]
 input tree            dp tree:
     3                  [3+3+1,4+5]
    / \                /        \
   4   5            [4,3]      [5,1]
  / \   \          /     \          \
 1   2   1      [1,0]    [2,0]     [1,0]
                / \       /  \        /  \
           [0,0] [0,0] [0,0] [0,0]  [0,0] [0,0]
    
*/
class Solution {
 public:
  vector<int> helper(TreeNode *root) {
    if (!root) return vector<int>(2, 0);

    vector<int> left = helper(root->left);
    vector<int> right = helper(root->right);

    vector<int> res(2, 0);
    res[0] = root->val + left[1] + right[1];
    res[1] = max(left[0], left[1]) + max(right[0], right[1]);

    return res;
  }
  int rob(TreeNode *root) {
    vector<int> ans = helper(root);
    return max(ans[0], ans[1]);
  }
};