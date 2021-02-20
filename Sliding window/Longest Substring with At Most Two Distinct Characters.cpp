// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

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
  int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> mp;
    int n = s.length();
    int start = 0, end = 0, count = 0, res = 0, currDistinct = 0;
    const int distinct = 2;

    while (end < n) {
      if (currDistinct <= distinct) {
        int index = s[end] - 'a';
        if (mp[index] == 0) currDistinct++;
        mp[index]++;
        end++;
      } else {
        int index = s[start] - 'a';
        mp[index]--;
        if (mp[index] == 0) currDistinct--;
        start++;
      }
      if (currDistinct <= distinct) {
        res = max(res, end - start);
      }
    }
    return res;
  }
};