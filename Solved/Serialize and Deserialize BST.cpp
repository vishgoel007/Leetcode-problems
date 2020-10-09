// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3489/

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

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string res = "";
    if (!root) return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int s = 0; s < size; s++) {
        TreeNode *curr = q.front();
        q.pop();
        res += to_string(curr->val);
        res += " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
      }
    }
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *buildBST(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val > val)
      root->left = buildBST(root->left, val);
    else
      root->right = buildBST(root->right, val);

    return root;
  }
  TreeNode *deserialize(string data) {
    if (data.length() == 0) return NULL;
    TreeNode *root = NULL;

    istringstream ss(data);

    for (int i; ss >> i;) {
      root = buildBST(root, i);
      if (ss.peek() == ' ')
        ss.ignore();
    }
    return root;
  }
};

// TODO String can be decompressed more efficiently