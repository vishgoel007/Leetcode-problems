// https://leetcode.com/problems/longest-palindromic-substring/

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
  pair<int, int> countPalindrome(string& s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      l--;
      r++;
    }
    return {r - l - 1, l + 1};
  }
  string longestPalindrome(string s) {
    int len = s.length();
    int start = 0, maxLen = 0;
    for (int i = 0; i < len; i++) {
      pair<int, int> p1 = countPalindrome(s, i, i);
      pair<int, int> p2 = countPalindrome(s, i, i + 1);
      pair<int, int> p = max(p1, p2);
      if (p.first > maxLen) {
        start = p.second;
        maxLen = p.first;
      }
    }
    return s.substr(start, maxLen - start + 1);
  }
};

// using dp
class Solution {
 public:
  string longestPalindrome(string s) {
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, 0));

    int start = 0, end = 0;
    for (int i = len - 1; i >= 0; i--) {
      for (int j = i; j < len; j++) {
        if (i == j)
          dp[i][j] = 1;
        else if (i + 1 == j)
          dp[i][j] = s[i] == s[j] ? 1 : 0;
        else
          dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;

        if (dp[i][j] && j - i > end - start) {
          start = i;
          end = j;
        }
      }
    }
    return s.substr(start, end - start + 1);
  }
};