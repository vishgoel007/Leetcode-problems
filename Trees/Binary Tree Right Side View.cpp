// https://leetcode.com/problems/binary-tree-right-side-view/

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

// Using BFS
class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);
    res.push_back(root->val);

    while (!q.empty()) {
      int size = q.size();
      bool flag = false;
      while (size--) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->right) {
          q.push(curr->right);
          // only 1 value will push to res per level or just add last node
          // to res in normal BFS
          if (!flag) {
            res.push_back(curr->right->val);
            flag = true;
          }
        }
        if (curr->left) {
          q.push(curr->left);
          if (!flag) {
            res.push_back(curr->left->val);
            flag = true;
          }
        }
      }
    }
    return res;
  }
};

// Using DFS
class Solution {
 public:
  void dfs(TreeNode *root, vector<int> &res, int level) {
    if (!root) return;

    if (res.size() == level) res.push_back(root->val);
    dfs(root->right, res, level + 1);
    dfs(root->left, res, level + 1);
  }
  vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};
    vector<int> res;
    dfs(root, res, 0);
    return res;
  }
};