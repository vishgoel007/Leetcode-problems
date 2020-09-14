// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3459/

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
  int helper(vector<int>& nums, int index) {
    if (index < 0 || index >= nums.size()) return 0;

    // if current home is not robbed
    int a = helper(nums, index - 1);

    // if current home is robbed
    int b = helper(nums, index - 2);

    return max(a, b + nums[index]);
  }
  int rob(vector<int>& nums) {
    return helper(nums, nums.size() - 1);
  }
};

// using top down dp
// was calculating multiple time for a index
class Solution {
 public:
  vector<int> dp;
  int helper(vector<int>& nums, int index) {
    if (index < 0 || index >= nums.size()) return 0;

    if (dp[index] != -1) return dp[index];

    // if current home is not robbed
    int a = helper(nums, index - 1);

    // if current home is robbed
    int b = helper(nums, index - 2);

    return dp[index] = max(a, b + nums[index]);
  }
  int rob(vector<int>& nums) {
    dp.resize(nums.size(), -1);
    return helper(nums, nums.size() - 1);
  }
};

// using bottom up dp
class Solution {
 public:
  vector<int> dp;
  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 2; i <= len; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[len];
  }
};