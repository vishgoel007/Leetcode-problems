// https://leetcode.com/problems/longest-substring-without-repeating-characters/

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
  int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, 0);
    int n = s.length();
    int start = 0, end = 0, repeatCount = 0, res = 0;
    while (end < n) {
      if (repeatCount == 0) {
        if (mp[s[end]] >= 1) repeatCount++;
        mp[s[end]]++;
        end++;
      } else {
        mp[s[start]]--;
        if (mp[s[start]] >= 1) repeatCount--;
        start++;
      }
      if (repeatCount == 0) {
        res = max(res, end - start);
      }
    }
    return res;
  }
};