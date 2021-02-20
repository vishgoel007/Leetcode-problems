// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
  TreeNode *prev = nullptr;
  void flatten(TreeNode *root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);

    if (prev) {
      root->right = prev;
      root->left = nullptr;
    }
    prev = root;
  }
};

// TODO - using iterative approach