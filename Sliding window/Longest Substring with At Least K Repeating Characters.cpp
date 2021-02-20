// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3544/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using divide and conquer
class Solution {
 public:
  int divideAndConquer(string_view s, int k) {
    if (s.length() == 0 || k > s.length()) return 0;

    vector<int> mp(26);
    for (char c : s) mp[c - 'a']++;

    int idx = 0;
    while (idx < s.length() && (mp[s[idx] - 'a'] == 0 || mp[s[idx] - 'a'] >= k)) idx++;
    if (idx == s.length()) return s.length();

    int left = divideAndConquer(s.substr(0, idx), k);
    int right = divideAndConquer(s.substr(idx + 1), k);

    return max(left, right);
  }
  int longestSubstring(string s, int k) {
    return divideAndConquer(s, k);
  }
};

// using sliding window method
class Solution {
 public:
  int maxUnique(string &s) {
    unordered_set<char> uniques(s.begin(), s.end());
    return uniques.size();
  }
  int longestWithUnique(string &s, int unique, int k) {
    int n = s.length();
    vector<int> mp(26, 0);
    int start = 0, end = 0, currUnique = 0, ans = 0, countK = 0;
    while (end < n) {
      // expand
      if (currUnique <= unique) {
        int index = s[end] - 'a';
        if (mp[index] == 0) currUnique++;
        mp[index]++;
        if (mp[index] == k) countK++;
        end++;
      } else {
        // shrink
        int index = s[start] - 'a';
        if (mp[index] == k) countK--;
        mp[index]--;
        if (mp[index] == 0) currUnique--;
        start++;
      }
      if (currUnique == unique && countK == currUnique) {
        ans = max(ans, end - start);
      }
    }
    return ans;
  }
  int longestSubstring(string s, int k) {
    int uniqueCount = maxUnique(s);
    int res = 0;
    for (int i = 1; i <= uniqueCount; i++) {
      res = max(res, longestWithUnique(s, i, k));
    }
    return res;
  }
};
