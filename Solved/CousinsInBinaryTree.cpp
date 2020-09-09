// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

#include <iostream>
#include <map>
#include <queue>
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
  bool isCousins(TreeNode *root, int x, int y) {
    if (!root) return false;

    TreeNode *nodeX = NULL, *nodeY = NULL;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode *curr = q.front();
        q.pop();

        if (curr->left) {
          if (curr->left->val == x)
            nodeX = curr;
          else if (curr->left->val == y)
            nodeY = curr;
          q.push(curr->left);
        }
        if (curr->right) {
          if (curr->right->val == x)
            nodeX = curr;
          else if (curr->right->val == y)
            nodeY = curr;
          q.push(curr->right);
        }
      }
      if (nodeX || nodeY) break;
    }

    if (nodeX && nodeY && nodeX != nodeY) return true;

    return false;
  }
};