// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
  int minValue = INT_MAX, prevValue = INT_MAX;
  void helper(TreeNode *root) {
    if (!root) return;

    helper(root->left);
    if (prevValue != INT_MAX)
      minValue = min(minValue, abs(root->val - prevValue));

    prevValue = root->val;

    helper(root->right);
  }
  int minDiffInBST(TreeNode *root) {
    helper(root);
    return minValue;
  }
};