// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3525/

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

// mine -> Brute force
class Solution {
 public:
  int maxValue = 0;
  void dfs(TreeNode *root, int rootVal) {
    if (!root) return;
    maxValue = max(maxValue, abs(root->val - rootVal));
    dfs(root->left, rootVal);
    dfs(root->right, rootVal);
  }
  void helper(TreeNode *root) {
    if (!root) return;
    dfs(root, root->val);
    helper(root->left);
    helper(root->right);
  }
  int maxAncestorDiff(TreeNode *root) {
    if (!root) return 0;
    helper(root);
    return maxValue;
  }
};

class Solution {
 public:
  void helper(TreeNode *root, int maxDesc, int minDesc, int &res) {
    if (!root) return;

    res = max(res, max(abs(maxDesc - root->val), abs(minDesc - root->val)));
    int currMax = max(maxDesc, root->val);
    int currMin = min(minDesc, root->val);

    helper(root->left, currMax, currMin, res);
    helper(root->right, currMax, currMin, res);
  }
  int maxAncestorDiff(TreeNode *root) {
    int res = 0;
    helper(root, root->val, root->val, res);
    return res;
  }
};