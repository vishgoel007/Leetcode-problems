// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// sliding window
class Solution {
 public:
  int numberOfSubstrings(string s) {
    int len = s.length();
    int count[3] = {0, 0, 0};

    int start = 0, end = 0;
    int res = 0;

    while (end < len) {
      count[s[end] - 'a']++;
      end++;

      while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        count[s[start] - 'a']--;
        start++;
      }
      res += start;
    }
    return res;
  }
};

// alternate
class Solution {
 public:
  int numberOfSubstrings(string s) {
    int len = s.length();
    int lastInd[3] = {-1, -1, -1};
    int res = 0;

    for (int i = 0; i < len; i++) {
      lastInd[s[i] - 'a'] = i;
      if (lastInd[0] >= 0 && lastInd[1] >= 0 && lastInd[2] >= 0) {
        res += min(lastInd[0], min(lastInd[1], lastInd[2])) + 1;
      }
    }
    return res;
  }
};