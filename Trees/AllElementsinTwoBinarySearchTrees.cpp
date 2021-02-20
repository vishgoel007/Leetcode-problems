// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3449/

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

// another nice way
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/576476/Non-Recursive-Approach-Using-Input-Trees-Directly

// Method 2 (merge both tree and do in-order)

// Method 1 (in-order traversal)
class Solution {
 public:
  void ascending(TreeNode *root, vector<int> &v) {
    if (!root) return;
    ascending(root->left, v);
    v.push_back(root->val);
    ascending(root->right, v);
  }
  vector<int> mergeArray(vector<int> &v1, vector<int> &v2) {
    vector<int> output;
    int i = 0, j = 0, n = v1.size(), m = v2.size();
    while (i < n && j < m) {
      v1[i] < v2[j] ? output.push_back(v1[i++]) : output.push_back(v2[j++]);
    }
    while (i < n) output.push_back(v1[i++]);
    while (j < m) output.push_back(v2[j++]);
    return output;
  }
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v1, v2;
    ascending(root1, v1);
    ascending(root2, v2);
    return mergeArray(v1, v2);
  }
};