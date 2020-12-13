// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3563/

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
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    auto res = dfs(root);
    return res.second;
  }
};

// using BFS
class Solution {
 public:
  TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return nullptr;

    if (root->val == q->val || root->val == p->val) return root;

    TreeNode *left = lca(root->left, p, q);
    TreeNode *right = lca(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
  }

  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    if (!root) return root;

    queue<TreeNode *> q;

    q.push(root);

    TreeNode *deepestLeftMost = NULL;
    TreeNode *deepestRightMost = NULL;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *curr = q.front();
        q.pop();

        if (i == 0) deepestLeftMost = curr;
        if (i == size - 1) deepestRightMost = curr;

        if (curr->left) {
          q.push(curr->left);
        }

        if (curr->right) {
          q.push(curr->right);
        }
      }
    }
    return lca(root, deepestLeftMost, deepestRightMost);
  }
};