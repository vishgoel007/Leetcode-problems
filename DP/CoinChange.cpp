// https://leetcode.com/problems/coin-change/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// By recursion
class Solution1 {
 public:
  int helper(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      if (amount >= coins[i]) {
        int smallAns = helper(coins, amount - coins[i]);
        if (smallAns != INT_MAX)
          ans = min(ans, smallAns + 1);    // need to increment coin for this turn
      }
    }
    return ans;
  }
  int coinChange(vector<int>& coins, int amount) {
    int coinsNeeded = helper(coins, amount);
    if (coinsNeeded == INT_MAX) return -1;
    return coinsNeeded;
  }
};

// Top down 1
class Solution2 {
 public:
  unordered_map<int, int> dp;
  int helper(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    if (dp.count(amount)) return dp[amount];
    int coinsNeeded = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      if (amount >= coins[i]) {
        int smallAns = helper(coins, amount - coins[i]);
        if (smallAns != INT_MAX)
          coinsNeeded = min(coinsNeeded, smallAns + 1);
      }
    }
    dp[amount] = coinsNeeded;
    return dp[amount];
  }
  int coinChange(vector<int>& coins, int amount) {
    int coinsNeeded = helper(coins, amount);
    return coinsNeeded == INT_MAX ? -1 : coinsNeeded;
  }
};

// Top down 2
class Solution3 {
 public:
  vector<int> dp;
  int helper(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    if (dp[amount] != INT_MAX) return dp[amount];

    int coinsNeeded = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
      if (amount >= coins[i]) {
        int smallAns = helper(coins, amount - coins[i]);
        if (smallAns != -1)
          coinsNeeded = min(coinsNeeded, smallAns);
      }
    }
    if (coinsNeeded == INT_MAX) {
      dp[amount] = -1;
      return -1;
    }
    dp[amount] = coinsNeeded + 1;
    return dp[amount];
  }
  int coinChange(vector<int>& coins, int amount) {
    dp.resize(amount + 1, INT_MAX);
    int coinsNeeded = helper(coins, amount);
    return coinsNeeded == INT_MAX ? -1 : coinsNeeded;
  }
};

// Bottom up
class Solution4 {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int len = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int p = 1; p <= amount; p++) {
      for (int c = 0; c < len; c++) {
        if (p >= coins[c]) {
          int smallAns = dp[p - coins[c]];
          if (smallAns != INT_MAX) {
            dp[p] = min(dp[p], smallAns + 1);
          }
        }
      }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

// using bfs
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int len = coins.size();
    queue<int> q;
    int level = 0;
    unordered_set<int> visited;
    q.push(amount);
    while (!q.empty()) {
      int size = q.size();
      level++;
      for (int s = 0; s < size; s++) {
        int curr = q.front();
        q.pop();

        if (curr == 0) return level - 1;
        if (visited.count(curr)) continue;

        visited.insert(curr);

        for (int c = 0; c < len; c++) {
          if (curr >= c)
            q.push(curr - coins[c]);
        }
      }
    }
    return -1;
  }
};