// https://leetcode.com/contest/weekly-contest-213/problems/count-sorted-vowel-strings/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// mine
class Solution {
 public:
  vector<char> v{'a', 'e', 'i', 'o', 'u'};
  int res = 0;
  int helper(int n, int curr, string& aux) {
    if (curr >= v.size()) return 0;
    if (aux.length() == n) return 1;

    int ans = 0;
    for (int i = curr; i < v.size(); i++) {
      aux += v[i];
      ans += helper(n, i, aux);
      aux.pop_back();
    }
    return ans;
  }
  int countVowelStrings(int n) {
    string s = "";
    return helper(n, 0, s);
  }
};

// top down
class Solution {
 public:
  vector<vector<int>> dp;
  int helper(int n, int vowel) {
    if (n == 0) return 1;
    if (vowel >= 5) return 0;

    if (dp[n][vowel] != -1) return dp[n][vowel];

    int ans = 0;
    ans += helper(n, vowel + 1);    // skip
    ans += helper(n - 1, vowel);    // include

    return dp[n][vowel] = ans;
  }
  int countVowelStrings(int n) {
    dp.resize(n + 1, vector<int>(6, -1));
    return helper(n, 0);
  }
};

// bottom up
class Solution {
 public:
  int countVowelStrings(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6, -1));

    // for n = 1
    for (int i = 1; i <= 5; i++) dp[1][i] = i;

    for (int nVal = 2; nVal <= n; nVal++) {
      dp[nVal][1] = 1;
      for (int vowel = 2; vowel <= 5; vowel++) {
        dp[nVal][vowel] = dp[nVal][vowel - 1] + dp[nVal - 1][vowel];    // skip + include
      }
    }

    return dp[n][5];
  }
};

// can be done by binomial (n+k-1)C (k-1) i.e (n+4)C4