// https://leetcode.com/problems/house-robber-ii/

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
  int helper(vector<int>& nums, int start, int end) {
    if (start > end) return 0;
    int a = helper(nums, start + 1, end);
    int b = helper(nums, start + 2, end);
    return max(a, b + nums[start]);
  }
  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];
    int includeFirstHouse = helper(nums, 0, len - 2);
    int excludedFirstHouse = helper(nums, 1, len - 1);
    return max(includeFirstHouse, excludedFirstHouse);
  }
};

// using top down dp
class Solution {
 public:
  vector<int> dp;
  int helper(vector<int>& nums, int start, int end) {
    if (start > end) return 0;

    if (dp[start] != -1) return dp[start];
    int a = helper(nums, start + 1, end);
    int b = helper(nums, start + 2, end);
    return dp[start] = max(a, b + nums[start]);
  }
  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0];

    dp.resize(nums.size() + 1, -1);
    int includeFirstHouse = helper(nums, 0, len - 2);

    dp.assign(nums.size() + 1, -1);
    int excludedFirstHouse = helper(nums, 1, len - 1);

    return max(includeFirstHouse, excludedFirstHouse);
  }
};

// using bottom up dp
class Solution {
 public:
  vector<int> dp;

  int helper(vector<int> nums) {
    int len = nums.size();

    // can be done using three variables
    vector<int> dp(len + 1, 0);

    if (len >= 1)
      dp[0] = nums[0];
    if (len >= 2)
      dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < len; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[len - 1];
  }
  int rob(vector<int>& nums) {
    int len = nums.size();

    if (len == 0) return 0;
    if (len == 1) return nums[0];

    int includeFirstHouse = helper(vector<int>(nums.begin(), nums.end() - 1));
    int excludedFirstHouse = helper(vector<int>(nums.begin() + 1, nums.end()));

    return max(includeFirstHouse, excludedFirstHouse);
  }
};