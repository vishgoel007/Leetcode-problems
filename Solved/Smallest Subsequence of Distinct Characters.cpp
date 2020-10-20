// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

#include <deque>
#include <iostream>
#include <list>
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
  string smallestSubsequence(string s) {
    int len = s.length();
    if (len == 1) return s;

    unordered_map<char, bool> visited;
    unordered_map<char, int> lastIndex;

    for (int i = 0; i < len; i++) lastIndex[s[i]] = i;

    string res = "";
    for (int i = 0; i < len; i++) {
      if (visited[s[i]]) continue;

      while (!res.empty() && res.back() > s[i] && lastIndex[res.back()] > i) {
        visited[res.back()] = false;
        res.pop_back();
      }
      res += s[i];
      visited[s[i]] = true;
    }
    return res;
  }
};
