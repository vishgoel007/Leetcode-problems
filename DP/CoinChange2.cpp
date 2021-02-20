// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/

// Unbounded Knapsack problem

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Using recursion
class Solution1 {
 public:
  int helper(int amount, vector<int>& coins, int index) {
    if (amount < 0) return 0;
    if (amount == 0) return 1;

    if (index == coins.size() && amount > 0) return 0;

    int includedCount = helper(amount - coins[index], coins, index);
    int excludedCount = helper(amount, coins, index + 1);

    return includedCount + excludedCount;
  }
  int change(int amount, vector<int>& coins) {
    int index = 0;
    return helper(amount, coins, index);
  }
};

// Using top down
class Solution2 {
 public:
  vector<vector<int> > dp;
  int helper(int amount, vector<int>& coins, int index) {
    if (amount < 0) return 0;
    if (amount == 0) return 1;

    if (index == coins.size() && amount > 0) return 0;

    if (dp[index][amount] != -1) return dp[index][amount];

    int includedCount = 0;
    if (amount >= coins[index])
      includedCount = helper(amount - coins[index], coins, index);
    int excludedCount = helper(amount, coins, index + 1);

    dp[index][amount] = includedCount + excludedCount;

    return dp[index][amount];
  }

  int change(int amount, vector<int>& coins) {
    int index = 0;
    dp.assign(coins.size() + 1, vector<int>(amount + 1, -1));
    return helper(amount, coins, index);
  }
};

// Using bottom up approach
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    int len = coins.size();
    vector<vector<int> > dp(len + 1, vector<int>(amount + 1, -1));

    for (int i = 0; i <= amount; i++) {
      dp[0][i] = 0;
    }
    for (int i = 0; i <= len; i++) {
      dp[i][0] = 1;
    }

    for (int p = 1; p <= amount; p++) {
      for (int c = 1; c <= len; c++) {
        int includedCount = 0;
        if (p >= coins[c - 1])
          includedCount = dp[c][p - coins[c - 1]];
        int excludedCount = dp[c - 1][p];
        dp[c][p] = includedCount + excludedCount;
      }
    }
    return dp[len][amount];
  }
};