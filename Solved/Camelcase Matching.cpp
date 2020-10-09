// https://leetcode.com/problems/camelcase-matching/

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
  bool checkSubsequence(string& s, string& pattern) {
    int sLen = s.length();
    int pLen = pattern.length();
    int si = 0, pi = 0;
    while (si < sLen && pi < pLen) {
      if (s[si] == pattern[pi]) {
        si++;
        pi++;
        continue;
      }
      if (isupper(s[si])) return false;
      si++;
    }

    while (si < sLen)
      if (isupper(s[si++])) return false;

    return pi == pLen;
  }
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> res;
    for (string& q : queries) {
      res.push_back(checkSubsequence(q, pattern));
    }
    return res;
  }
};