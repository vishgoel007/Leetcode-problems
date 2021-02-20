// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/563/week-5-october-29th-october-31st/3514/

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

/*
 * Need to find which two elemnts are swapped
 * for example inorder traversal of tree is 6, 3, 4, 5, 2
 * so in that case out first will be 6 and second will be 2
 * and then swap their
 */
class Solution {
 public:
  TreeNode *first = NULL, *second = NULL, *prev = NULL;
  void inorder(TreeNode *root) {
    if (!root) return;
    inorder(root->left);

    if (prev && prev->val > root->val) {
      if (!first) first = prev;
      second = root;
    }
    prev = root;
    
    inorder(root->right);
  }
  void recoverTree(TreeNode *root) {
    inorder(root);
    swap(first->val, second->val);
  }
};

// TODO using morris inorder traversal in space o(1)