// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/558/week-5-september-29th-september-30th/3477/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using recursion
class Solution {
 public:
  bool helper(string s, unordered_set<string>& words) {
    if (s.length() == 0) return true;
    if (words.count(s)) return true;

    // cuts
    for (int i = 1; i <= s.length(); i++) {
      string left = s.substr(0, i);

      // if left word is present in words then only make more cuts
      if (words.count(left)) {
        if (helper(s.substr(i), words))
          return true;
      }
    }
    return false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    return helper(s, words);
  }
};

/**
 * instead of using substr as it takes O(n) time 
 * we can pass a extra parameter in helper which will tells us 
 * the current cut postion, so we can avoid the substr time factor here
 * and also we can able to pass string as an refernce
 */

// using recursion 2 (without using substr)
class Solution {
 public:
  bool helper(string& s, unordered_set<string>& words, int start) {
    if (start == s.length()) return true;
    if (words.count(s)) return true;

    string left = "";
    // cuts
    for (int i = start; i < s.length(); i++) {
      left += s[i];
      // if left word is present in words then only make more cuts
      if (words.count(left)) {
        if (helper(s, words, i + 1))
          return true;
      }
    }
    return false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    return helper(s, words, 0);
  }
};

// using top down
class Solution {
 public:
  unordered_map<string, bool> visited;
  bool helper(string s, unordered_set<string>& words) {
    if (s.length() == 0) return true;
    if (words.count(s)) return true;

    if (visited.find(s) != visited.end()) return visited[s];

    // cuts
    for (int i = 1; i <= s.length(); i++) {
      string left = s.substr(0, i);

      // if left word is present in words then only make more cuts
      if (words.count(left)) {
        if (helper(s.substr(i), words)) {
          // if we are able to find the solution set it to true
          visited[s] = true;
          return true;
        }
      }
    }
    // if we are not able to find the solution set it to false
    visited[s] = false;
    return false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    return helper(s, words);
  }
};

// using top down 2 (without using substr)
class Solution {
 public:
  vector<bool> dp;
  bool helper(string& s, unordered_set<string>& words, int start) {
    if (start == s.length()) return true;
    if (words.count(s)) return true;
    if (dp[start] != -1) return dp[start];

    string left = "";
    // cuts
    for (int i = start; i < s.length(); i++) {
      left += s[i];
      // if left word is present in words then only make more cuts
      if (words.count(left)) {
        if (helper(s, words, i + 1)) {
          dp[start] = 1;
          return true;
        }
      }
    }
    dp[start] = 0;
    return false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    dp.resize(s.length() + 1, -1);
    return helper(s, words, 0);
  }
};

// using bottom up
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    int len = s.length();
    vector<bool> dp(len + 1, 0);
    dp[0] = 1;

    // string length
    for (int si = 1; si <= len; si++) {
      // cuts
      for (int j = 0; j < si; j++) {
        if (words.count(s.substr(j, si - j))) {
          if (dp[j]) {
            dp[si] = 1;
            break;
          }
        }
      }
    }
    return dp[len];
  }
};

// using BFS
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    unordered_set<string> words(wordDict.begin(), wordDict.end());

    vector<bool> visited(len + 1, 0);
    queue<int> q;

    q.push(0);    // start just like dp

    while (!q.empty()) {
      int start = q.front();
      q.pop();
      if (visited[start]) continue;
      if (start == len) return true;
      visited[start] = true;
      string left = "";
      for (int i = start; i < len; i++) {
        left += s[i];
        if (words.count(left)) q.push(i + 1);
      }
    }
    return false;
  }
};