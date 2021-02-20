// https://leetcode.com/problems/palindromic-substrings/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// expand around corners for both odd/even length palindrome
class Solution {
 public:
  int countPalindrome(string s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
      count++;
    }
    return count;
  }
  int countSubstrings(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++) {
      ans += countPalindrome(s, i, i);
      ans += countPalindrome(s, i, i + 1);
    }
    return ans;
  }
};

// Using DP

// recursion
class Solution {
 public:
  int helper(string& s, int l, int r) {
    if (l >= r) return 1;
    return s[l] == s[r] ? helper(s, l + 1, r - 1) : 0;
  }
  int countSubstrings(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
        ans += helper(s, i, j);
      }
    }

    return ans;
  }
};

// top-down
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(string& s, int l, int r) {
    if (l >= r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    int res = s[l] == s[r] ? helper(s, l + 1, r - 1) : 0;
    return dp[l][r] = res;
  }
  int countSubstrings(string s) {
    int len = s.length();
    dp.resize(len, vector<int>(len, -1));
    int ans = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i; j < len; j++) {
        ans += helper(s, i, j);
      }
    }

    return ans;
  }
};

// bottom-up
class Solution {
 public:
  int countSubstrings(string s) {
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, 0));

    int ans = 0;

    // only need to calculate for upper half of matrix i.e for i >=j
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i; j < len; j++) {
        if (i == j)
          dp[i][j] = 1;

        else if (i + 1 == j)
          dp[i][j] = s[i] == s[j] ? 1 : 0;

        else
          dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;

        ans += dp[i][j];
      }
    }

    return ans;
  }
};