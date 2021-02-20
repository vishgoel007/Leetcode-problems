// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// premium problem

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
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<int> mp(256, 0);
    int n = s.length();
    int start = 0, end = 0, count = 0, res = 0, currDistinct = 0;

    while (end < n) {
      if (currDistinct <= k) {
        int index = s[end];
        if (mp[index] == 0) currDistinct++;
        mp[index]++;
        end++;
      } else {
        int index = s[start];
        mp[index]--;
        if (mp[index] == 0) currDistinct--;
        start++;
      }
      if (currDistinct <= k) {
        res = max(res, end - start);
      }
    }
    return res;
  }
};

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<int> mp(256, 0);
    int n = s.length();
    int start = 0, end = 0, currDistinct = 0, res = 0;

    while (end < n) {
      int ind = s[end];
      if (mp[ind] == 0) currDistinct++;
      mp[ind]++;
      end++;

      while (currDistinct > k) {
        int ind = s[start];
        mp[ind]--;
        if (mp[ind] == 0) currDistinct--;
        start++;
      }
      res = max(res, end - start);
    }
    return res;
  }
};