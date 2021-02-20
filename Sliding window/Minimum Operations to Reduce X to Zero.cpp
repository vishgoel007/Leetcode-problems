// https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/

#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using top down dp (TLE)
class Solution {
 public:
  vector<vector<int>> dp;
  const int maxVal = 1e5;
  int helper(vector<int>& nums, int x, int i, int j) {
    if (x < 0) return maxVal;

    if (x == 0) return 0;

    if (i > j && x > 0) return maxVal;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = maxVal;
    ans = min(ans, 1 + helper(nums, x - nums[i], i + 1, j));
    ans = min(ans, 1 + helper(nums, x - nums[j], i, j - 1));

    return dp[i][j] = ans;
  }
  int minOperations(vector<int>& nums, int x) {
    int length = nums.size();
    dp.resize(length, vector<int>(length, -1));
    int res = helper(nums, x, 0, nums.size() - 1);
    return res >= maxVal ? -1 : res;
  }
};

// using sliding window
// tranformed into longest subarray of sum K
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int len = nums.size();

    int total = accumulate(nums.begin(), nums.end(), 0);
    int start = 0, end = 0;
    int res = -1, k = total - x, sum = 0;

    while (end < len) {
      sum += nums[end];
      end++;

      while (sum > k && start < end && end < len) {
        sum -= nums[start];
        start++;
      }

      if (sum == k) res = max(res, end - start);
    }

    return res == -1 ? res : len - res;
  }
};

// using sliding window
// as per the question
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int len = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int start = 0, end = 0;
    int res = INT_MAX;

    while (end < len) {
      sum -= nums[end];
      end++;

      while (sum < x && start <= end && end < len) {
        sum += nums[start];
        start++;
      }

      if (sum == x) res = min(res, (len - end) + start);
    }

    return res == INT_MAX ? -1 : res;
  }
};