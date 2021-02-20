// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> output;
    if (!root) return output;

    queue<TreeNode *> q;
    q.push(root);
    bool ltr = true;
    while (!q.empty()) {
      int size = q.size();
      vector<int> aux(size);
      for (int s = 0; s < size; s++) {
        TreeNode *curr = q.front();
        q.pop();
        int index = ltr ? s : size - 1 - s;
        aux[index] = curr->val;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      //   if (!ltr) reverse(aux.begin(), aux.end());
      output.push_back(aux);
      ltr = !ltr;
    }
    return output;
  }
};