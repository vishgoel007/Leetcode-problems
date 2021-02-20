// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3532/

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

class Solution {
 public:
  int sum = 0;
  void helper(TreeNode *root, int low, int high) {
    if (!root) return;
    if (root->val >= low and root->val <= high) sum += root->val;
    helper(root->left, low, high);
    helper(root->right, low, high);
  }
  int rangeSumBST(TreeNode *root, int low, int high) {
    helper(root, low, high);
    return sum; 
  }
};
