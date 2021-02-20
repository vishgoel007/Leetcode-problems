// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3485/

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

// using recursion
class Solution {
 public:
  TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (root->val > val)
      root->left = insert(root->left, val);
    else
      root->right = insert(root->right, val);
    return root;
  }
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    return insert(root, val);
  }
};

// using iterative
class Solution {
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == NULL) return new TreeNode(val);

    TreeNode *temp = root;

    while (true) {
      if (temp->val > val) {
        if (temp->left)
          temp = temp->left;
        else {
          temp->left = new TreeNode(val);
          break;
        }
      } else {
        if (temp->right)
          temp = temp->right;
        else {
          temp->right = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};