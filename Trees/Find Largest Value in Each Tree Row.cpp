// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
  vector<int> largestValues(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      int maxVal = INT_MIN;
      while (size--) {
        TreeNode *curr = q.front();
        q.pop();

        maxVal = max(maxVal, curr->val);

        if (curr->left) {
          q.push(curr->left);
        }

        if (curr->right) {
          q.push(curr->right);
        }
      }
      res.push_back(maxVal);
    }

    return res;
  }
};