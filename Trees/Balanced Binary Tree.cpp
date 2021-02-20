// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3577/

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
  bool res = true;
  int height(TreeNode *root) {
    if (!root) return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (abs(left - right) > 1) {
      res = false;
    }

    return 1 + max(left, right);
  }
  bool isBalanced(TreeNode *root) {
    if (!root) return true;

    height(root);
    return res;
  }
};