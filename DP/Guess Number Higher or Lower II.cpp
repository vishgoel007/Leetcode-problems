// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = INT_MAX;
    for (int x = l; x <= r; x++) {
      int a = helper(l, x - 1);
      int b = helper(x + 1, r);
      // we don't know wether x lies in left or right so just pick the worst case
      // that's why we are taking max
      ans = min(ans, x + max(a, b));
    }
    return dp[l][r] = ans;
  }
  int getMoneyAmount(int n) {
    dp.resize(n + 1, vector<int>(n + 1, -1));
    return helper(1, n);
  }
};

// using bottom up dp
class Solution {
 public:
  int getMoneyAmount(int n) {
    if (n == 1) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int r = 2; r <= n; r++) {
      for (int l = r - 1; l > 0; l--) {
        if (l == r - 1) {
          dp[l][r] = l;
          continue;
        }
        int ans = INT_MAX;
        for (int x = l + 1; x < r; x++) {
          int localMax = x + max(dp[l][x - 1], dp[x + 1][r]);
          ans = min(ans, localMax);
        }
        dp[l][r] = ans;
      }
    }
    return dp[1][n];
  }
};