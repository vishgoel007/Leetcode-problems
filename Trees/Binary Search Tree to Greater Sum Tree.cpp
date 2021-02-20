// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
  void helper(TreeNode *root, int &sum) {
    if (!root) return;
    helper(root->right, sum);
    sum += root->val;
    root->val = sum;
    helper(root->left, sum);
  }
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    helper(root, sum);
    return root;
  }
};