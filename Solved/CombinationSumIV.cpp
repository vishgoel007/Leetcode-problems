// https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using recursion
class Solution {
 public:
  int helper(vector<int>& nums, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans += helper(nums, target - nums[i]);
    }
    return ans;
  }
  int combinationSum4(vector<int>& nums, int target) {
    return helper(nums, target);
  }
};

// using top down dp 1
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(vector<int>& nums, int target, int index) {
    if (target < 0) return 0;
    if (target == 0) return 1;

    if (dp[index][target] != -1) return dp[index][target];

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans += helper(nums, target - nums[i], i);
    }

    return dp[index][target] = ans;
  }
  int combinationSum4(vector<int>& nums, int target) {
    dp.resize(nums.size() + 1, vector<int>(target + 1, -1));

    return helper(nums, target, 0);
  }
};

// using top down dp 2 ??
class Solution {
 public:
  vector<int> dp;
  void print() {
    for (int n : dp)
      cout << n << " ";
  }
  int helper(vector<int>& nums, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;

    if (dp[target] != -1) return dp[target];

    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans += helper(nums, target - nums[i]);
    }

    return dp[target] = ans;
  }
  int combinationSum4(vector<int>& nums, int target) {
    dp.resize(target + 1, -1);

    return helper(nums, target);
  }
};

// using bottom up dp
class Solution {
 public:
  vector<int> dp;

  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int t = 1; t <= target; t++) {
      for (int i = 0; i < nums.size(); i++) {
        if (t >= nums[i])
          dp[t] = (long)dp[t] + dp[t - nums[i]];
      }
    }
    return dp[target];
  }
};

/**
 * Follow up question
 * What if negative numbers are allowed in the given array?
 * 
 * if there are negative numbers in the array, we must add a requirement
 *  that each number is only used one time, or either positive number 
 * or negative number should be used only one time, 
 * otherwise there would be infinite possible combinations.
 *  For example, we are given:
 *  {1, -1}, target = 1
*/
