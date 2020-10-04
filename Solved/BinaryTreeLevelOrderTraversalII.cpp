// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/

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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> output;
    if (!root) return output;

    stack<vector<int>> st;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      vector<int> temp;
      for (int i = 0; i < size; i++) {
        TreeNode *curr = q.front();
        q.pop();
        temp.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
      st.push(temp);
    }
    vector<int> temp;
    while (!st.empty()) {
      output.push_back(st.top());
      st.pop();
    }
    return output;
  }
};