// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

// premium problem

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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int findCount = 0;
  TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    TreeNode* left = dfs(root->left, p, q);
    TreeNode* right = dfs(root->right, p, q);

    if (root == p || root == q) {
      if (root == p) findCount++;
      if (root == q) findCount++;
      return root;
    }

    if (left && right) return root;
    return left ? left : right;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca = dfs(root, p, q);
    return findCount == 2 ? lca : nullptr;
  }
};