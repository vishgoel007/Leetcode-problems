// https://leetcode.com/problems/binary-search-tree-iterator-ii/

// premium problem

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

class BSTIterator {
 private:
  stack<TreeNode *> stNext;
  stack<TreeNode *> stPrev;
  TreeNode *curr = nullptr;

  void traverseLeft(TreeNode *node) {
    while (node) {
      stNext.push(node);
      node = node->left;
    }
  }

 public:
  BSTIterator(TreeNode *root) {
    traverseLeft(root);
  }

  int next() {
    if (curr != nullptr) stPrev.push(curr);

    TreeNode *node = stNext.top();
    stNext.pop();

    curr = node;

    if (node->right) traverseLeft(node->right);
    return node->val;
  }

  int prev() {
    TreeNode *node = stPrev.top();
    stPrev.pop();

    if (curr->right != nullptr) {
      while (stNext.top() != curr->right) stNext.pop();

      // remove curr->right
      stNext.pop();
    }

    stNext.push(curr);
    curr = node;

    return node->val;
  }

  bool hasNext() {
    return stNext.size() > 0;
  }

  bool hasPrev() {
    return stPrev.size() > 0;
  }
};