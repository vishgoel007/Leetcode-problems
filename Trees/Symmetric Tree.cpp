// https://leetcode.com/problems/symmetric-tree/

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

// recursive
class Solution {
 public:
  bool helper(TreeNode *leftTree, TreeNode *rightTree) {
    if (!leftTree && !rightTree) return true;
    if (!leftTree || !rightTree) return false;
    return leftTree->val == rightTree->val && helper(leftTree->left, rightTree->right) && helper(leftTree->right, rightTree->left);
  }
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    return helper(root->left, root->right);
  }
};

// iterative
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;

    queue<TreeNode *> q;
    q.push(root);
    q.push(root);

    while (!q.empty()) {
      TreeNode *curr1 = q.front();
      q.pop();
      TreeNode *curr2 = q.front();
      q.pop();

      if (!curr1 && !curr2) continue;

      if (!curr1 || !curr2) return false;

      if (curr1->val != curr2->val) return false;

      q.push(curr1->left);
      q.push(curr2->right);

      q.push(curr1->right);
      q.push(curr2->left);
    }
    return true;
  }
};

