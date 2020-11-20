// https://leetcode.com/problems/path-sum/

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

class Solution {
 public:
  bool dfs(TreeNode *root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right && root->val == sum) return true;
    return dfs(root->left, sum - root->val) || dfs(root->right, sum - root->val);
  }
  bool hasPathSum(TreeNode *root, int sum) {
    return dfs(root, sum);
  }
};