// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3564/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(vector<int>& a, int l, int r) {
    if (l > r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    int ans = 0;
    // suppose ith ballon is last to burst
    for (int i = l + 1; i < r; i++) {
      int left = helper(a, l, i);
      int right = helper(a, i, r);
      ans = max(ans, a[l] * a[i] * a[r] + left + right);
    }
    return dp[l][r] = ans;
  }

  int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();

    dp.resize(n, vector<int>(n, -1));
    return helper(nums, 0, n - 1);
  }
};

// bottom up dp
class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int numSize = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int len = 1; len <= numSize; len++) {    // window size
      for (int left = 1; left <= numSize - len + 1; left++) {
        int right = left + len - 1;
        int ans = 0;
        for (int i = left; i <= right; i++) {
          int coins = dp[left][i - 1] + dp[i + 1][right] + nums[left - 1] * nums[i] * nums[right + 1];
          ans = max(ans, coins);
        }
        dp[left][right] = ans;
      }
    }
    return dp[1][numSize];
  }
};