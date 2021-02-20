// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3553/

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
  void inorder(TreeNode *root, TreeNode **node) {
    if (!root) return;
    inorder(root->left, node);
    (*node)->right = new TreeNode(root->val);
    (*node) = (*node)->right;
    inorder(root->right, node);
  }
  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *node = new TreeNode();
    TreeNode *temp = node;
    inorder(root, &temp);
    return node->right;
  }
};