// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3504/

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

// using BFS
class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int s = 0; s < size; s++) {
        TreeNode *curr = q.front();
        q.pop();
        if (!curr->left && !curr->right) return level;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return level;
  }
};

// using DFS
class Solution {
 public:
  int helper(TreeNode *root) {
    if (!root) return 0;
    int left = helper(root->left);
    int right = helper(root->right);
    if (left == 0 || right == 0) return max(left, right) + 1;
    return min(left, right) + 1;
  }
  int minDepth(TreeNode *root) {
    return helper(root);
  }
};
