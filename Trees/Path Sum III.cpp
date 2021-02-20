// https://leetcode.com/problems/path-sum-iii/

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

class Solution {
 public:
  int dfs(TreeNode *root, int sum) {
    if (!root) return 0;

    return (sum == root->val) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
  }
  int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;

    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
};

// Like continuous subarray that sums to to target
// consider it as a subarray problem
class Solution {
 public:
  unordered_map<int, int> mp;
  int count = 0;
  void dfs(TreeNode *root, int currSum, int sum) {
    if (!root) return;

    currSum += root->val;

    if (currSum == sum) count++;

    if (mp[currSum - sum]) count += mp[currSum - sum];

    mp[currSum]++;

    dfs(root->left, currSum, sum);
    dfs(root->right, currSum, sum);

    /* 
      remove the current sum from the hashmap
      in order not to use it during
      the parallel subtree processing
    */
    mp[currSum]--;
  }
  int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;
    dfs(root, 0, sum);
    return count;
  }
};