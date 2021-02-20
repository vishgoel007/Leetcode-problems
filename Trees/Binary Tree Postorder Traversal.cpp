// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
  void postorder(TreeNode *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    output.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    postorder(root);
    return output;
  }
};

// iterative using two stacks
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
      TreeNode *curr = st1.top();
      st1.pop();
      st2.push(curr);

      if (curr->left) st1.push(curr->left);
      if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
      res.push_back(st2.top()->val);
      st2.pop();
    }

    return res;
  }
};

// iterative using one stack
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (!st.empty() || curr != nullptr) {
      if (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      } else {
        TreeNode *temp = st.top()->right;
        if (temp == nullptr) {
          // if stack top right is null
          // it means we are done exploring that node
          temp = st.top();
          st.pop();
          res.push_back(temp->val);

          // check if current popped node is
          // right child of now stack top node
          // if it is child node then we also done exploring that node too
          while (!st.empty() && st.top()->right == temp) {
            temp = st.top();
            st.pop();
            res.push_back(temp->val);
          }
        } else {
          // if stack top right is not null
          // it means need to explore right also
          curr = temp;
        }
      }
    }

    return res;
  }
};