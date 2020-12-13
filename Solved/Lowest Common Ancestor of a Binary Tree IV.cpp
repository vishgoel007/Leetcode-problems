// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/

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
  unordered_map<TreeNode*, bool> mp;

  TreeNode* dfs(TreeNode* root) {
    if (!root) return nullptr;

    if (mp[root]) {
      mp[root] = false;
      return root;
    }

    TreeNode* left = dfs(root->left);
    TreeNode* right = dfs(root->right);

    if (left && right) return root;

    return left ? left : right;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    for (TreeNode* node : nodes) mp[node] = true;
    return dfs(root);
  }
};