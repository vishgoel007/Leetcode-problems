// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    int level = 0, resLevel = 0, maxSum = INT_MIN;
    while (!q.empty()) {
      level++;
      int sum = 0, size = q.size();
      for (int s = 0; s < size; s++) {
        TreeNode *curr = q.front();
        q.pop();
        sum += curr->val;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      if (sum > maxSum) {
        maxSum = sum;
        resLevel = level;
      }
    }
    return resLevel;
  }
};