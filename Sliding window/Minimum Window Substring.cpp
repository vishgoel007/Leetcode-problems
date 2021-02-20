// https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> mp(128);

    for (char c : t) mp[c]++;

    int n = s.length();
    int resStart = 0, resEnd = n + 1;
    int start = 0, end = 0, count = 0;

    while (end < n) {
      if (mp[s[end]] > 0) count++;
      mp[s[end]]--;
      end++;

      while (count >= t.length()) {
        if (resEnd - resStart > end - start) {
          resStart = start;
          resEnd = end;
        }
        mp[s[start]]++;
        if (mp[s[start]] > 0) count--;
        start++;
      }
    }

    if (resEnd - resStart == n + 1) return "";
    return s.substr(resStart, (resEnd - resStart) + 1);
  }
};