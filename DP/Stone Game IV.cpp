// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3507/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// top down
class Solution {
 public:
  vector<int> dp;
  bool helper(int n) {
    if (n == 0) return false;

    if (dp[n] != -1) return dp[n];

    bool ans = false;
    for (int i = 1; i * i <= n; i++) {
      // first player took i*i
      // now next player turn with n - i*i
      ans = !helper(n - i * i);
      if (ans) break;
    }
    return dp[n] = ans;
  }
  bool winnerSquareGame(int n) {
    dp.resize(n + 1, -1);
    return helper(n);
  }
};

// bottom up
class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, 0);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};