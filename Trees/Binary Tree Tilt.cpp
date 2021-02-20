// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3524/

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
  int postOrder(TreeNode *root, int &res) {
    if (!root) return 0;

    int l = postOrder(root->left, res);
    int r = postOrder(root->right, res);

    res += abs(l - r);
    return l + r + root->val;
  }
  int findTilt(TreeNode *root) {
    int res = 0;
    postOrder(root, res);
    return res;
  }
};
