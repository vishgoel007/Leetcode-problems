// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;

    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    } else
      return root;
  }
};