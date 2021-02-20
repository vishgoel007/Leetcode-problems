// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3581/

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
  vector<int> memo;
  int helper(string& s, int curr) {
    if (curr == s.length()) return 1;

    if (s[curr] == '0') return 0;

    if (curr == s.length() - 1) return 1;

    if (memo[curr] != -1) return memo[curr];

    int ans = helper(s, curr + 1);
    if (s.length() >= 2 && stoi(s.substr(curr, 2)) <= 26) {
      ans += helper(s, curr + 2);
    }

    return memo[curr] = ans;
  }

  int numDecodings(string s) {
    memo.assign(s.size(), -1);
    return helper(s, 0);
  }
};

// bottom up dp
class Solution {
 public:
  vector<int> memo;

  int numDecodings(string s) {
    int len = s.length();
    if (len == 0) return 0;

    vector<int> dp(len + 1);

    dp[0] = 1;
    dp[1] = s[0] != '0';

    for (int i = 2; i <= len; i++) {
      dp[i] += s[i - 1] != '0' ? dp[i - 1] : 0;

      int twoDigit = stoi(s.substr(i - 2, 2));
      dp[i] += twoDigit >= 10 and twoDigit <= 26 ? dp[i - 2] : 0;
    }

    return dp[len];
  }
};