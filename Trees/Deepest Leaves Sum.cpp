// https://leetcode.com/problems/deepest-leaves-sum/

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
  int deepestLeavesSum(TreeNode *root) {
    if (!root) return 0;

    queue<TreeNode *> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
      int size = q.size();
      sum = 0;
      for (int s = 0; s < size; s++) {
        TreeNode *curr = q.front();
        q.pop();

        if (!curr->left && !curr->right) sum += curr->val;

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return sum;
  }
};