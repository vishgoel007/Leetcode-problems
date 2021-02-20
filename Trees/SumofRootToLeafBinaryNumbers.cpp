// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3453/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Method 1 (find all leaf nodes and convert it into decimal)
class Solution {
 public:
  vector<string> v;

  void PreOrder(TreeNode *root, string &s) {
    if (!root) return;

    s += to_string(root->val);

    if (!root->right && !root->left) {
      v.push_back(s);
      s = s.substr(0, s.length() - 1);
    } else {
      PreOrder(root->left, s);
      PreOrder(root->right, s);
      s = s.substr(0, s.length() - 1);
    }
  }
  int sumRootToLeaf(TreeNode *root) {
    string s = "";
    PreOrder(root, s);
    unsigned long ans = 0;
    for (int i = 0; i < v.size(); i++) {
      unsigned long value = stoul(v[i], 0, 2);
      ans += value;
    }
    return ans;
  }
};

// Method 2 (calculating decimal value with in function)
class Solution {
 public:
  vector<string> v;

  int sum = 0;
  void PreOrder(TreeNode *root, int curr) {
    if (!root) return;

    curr = curr * 2 + root->val;

    if (!root->right && !root->left) {
      sum += curr;
    } else {
      PreOrder(root->left, curr);
      PreOrder(root->right, curr);
    }
  }
  int sumRootToLeaf(TreeNode *root) {
    PreOrder(root, 0);
    return sum;
  }
};