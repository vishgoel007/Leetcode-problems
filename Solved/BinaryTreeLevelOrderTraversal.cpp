// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> output;
    if (!root) return output;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> temp;
      for (int i = 0; i < size; i++) {
        TreeNode *curr = q.front();
        q.pop();
        if (curr)
          temp.push_back(curr->val);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      output.push_back(temp);
    }
    return output;
  }
};