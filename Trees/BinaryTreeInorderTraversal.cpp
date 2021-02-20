// https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1383/

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

// recursive
class Solution {
 public:
  vector<int> output;
  void traversalRecursive(TreeNode *root) {
    if (!root) return;
    traversalRecursive(root->left);
    output.push_back(root->val);
    traversalRecursive(root->right);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    traversalRecursive(root);
    return output;
  }
};

// iterative
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode *> st;
    while (!st.empty() || root) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      root = st.top();
      st.pop();
      res.push_back(root->val);
      root = root->right;
    }

    return res;
  }
};

// Using morris inorder traversal in space O(1)
// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/148939/CPP-Morris-Traversal
