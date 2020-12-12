// https://leetcode.com/contest/biweekly-contest-41/problems/count-the-number-of-consistent-strings/

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
  vector<int> mp;
  bool check(string& word) {
    for (char c : word) {
      if (!mp[c - 'a']) return false;
    }
    return true;
  }
  int countConsistentStrings(string allowed, vector<string>& words) {
    mp.resize(26, 0);
    for (char c : allowed) mp[c - 'a']++;

    int res = 0;
    for (string& word : words) {
      res += check(word);
    }

    return res;
  }
};