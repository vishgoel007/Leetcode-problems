// https://leetcode.com/problems/path-sum-ii/

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

// using dfs
class Solution {
 public:
  vector<vector<int>> res;
  void dfs(TreeNode *root, int sum, vector<int> &aux) {
    if (!root) return;

    aux.push_back(root->val);

    if (!root->left && !root->right && sum == root->val) {
      res.push_back(aux);
    }

    dfs(root->left, sum - root->val, aux);
    dfs(root->right, sum - root->val, aux);
    aux.pop_back();
  }
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<int> aux;
    dfs(root, sum, aux);
    return res;
  }
};

// using BFS
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<tuple<TreeNode *, vector<int>, int>> q;
    q.push({root, {}, sum});

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      TreeNode *node = get<0>(curr);
      get<1>(curr).push_back(node->val);
      int remSum = get<2>(curr);

      if (!node->left && !node->right && remSum == node->val) {
        res.push_back(get<1>(curr));
      } else {
        if (node->left) q.push({node->left, get<1>(curr), remSum - node->val});
        if (node->right) q.push({node->right, get<1>(curr), remSum - node->val});
      }
    }
    return res;
  }
};
