// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3435/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
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
  int sum;

  void calculateSum(TreeNode *root) {
    if (!root) return;
    if (root->left && root->left->left && !root->left->right) {
      sum += root->left->val;
    }
    calculateSum(root->left);
    calculateSum(root->right);
  }

  int sumOfLeftLeaves(TreeNode *root) {
    sum = 0;
    calculateSum(root);
    return sum;
  }
};