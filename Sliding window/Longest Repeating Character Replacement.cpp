// https://leetcode.com/problems/longest-repeating-character-replacement/

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
  int characterReplacement(string s, int k) {
    int n = s.length();
    vector<int> mp(26, 0);

    int start = 0, end = 0;
    int maxLen = 0, count = 0;

    while (end < n) {
      mp[s[end] - 'A']++;
      count = max(count, mp[s[end] - 'A']);
      end++;
      
      // (end - start - count)
      // helpful in telling how many different char in start to end
      // count of most repeatable character + no. of allowed replacements <= length of the window

      while (end - start - count > k) {
        mp[s[start] - 'A']--;
        start++;
      }

      maxLen = max(maxLen, end - start);
    }

    return maxLen;
  }
};