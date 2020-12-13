// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include <iostream>
#include <istream>
#include <map>
#include <queue>
#include <sstream>
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

// DFS
class Solution {
 public:
  // first-> height and second -> subtree
  pair<int, TreeNode *> dfs(TreeNode *root) {
    if (!root) return {0, nullptr};
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int leftHeight = left.first, rightHeight = right.first;
    TreeNode *leftTree = left.second, *rightTree = right.second;

    if (leftHeight == rightHeight) {
      return {leftHeight + 1, root};
    }

    if (leftHeight > rightHeight) {
      return {leftHeight + 1, leftTree};
    }
    return {rightHeight + 1, rightTree};
  }
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    auto res = dfs(root);
    return res.second;
  }
};