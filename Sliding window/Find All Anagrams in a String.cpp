// https://leetcode.com/problems/find-all-anagrams-in-a-string/

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
  vector<int> findAnagrams(string s, string p) {
    int slen = s.length();
    int plen = p.length();
    if (slen == 0 || plen == 0) return {};

    vector<int> mp(26, 0);
    for (char c : p) mp[c - 'a']++;

    vector<int> res;
    int start = 0, end = 0;
    int count = 0;
    while (end < slen) {
      int endInd = s[end] - 'a';
      if (mp[endInd] > 0) count++;
      mp[endInd]--;
      end++;
      while (count >= plen) {
        int startInd = s[start] - 'a';
        mp[startInd]++;
        if (mp[startInd] > 0) count--;
        if (end - start == plen) res.push_back(start);
        start++;
      }
    }

    return res;
  }
};