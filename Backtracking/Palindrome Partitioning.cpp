// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3565/

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
  vector<vector<string>> res;
  bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) return false;
    }
    return true;
  }

  void dfs(string& s, int start, vector<string>& aux) {
    // if start ends at s.size() it means it contains all
    // palindromic substrings starting form start
    if (start == s.length()) {
      res.push_back(aux);
      return;
    }

    string ss = "";
    // generate all substrings starting from start
    for (int i = start; i < s.length(); i++) {
      ss += s[i];
      if (isPalindrome(s, start, i)) {
        // string ss = s.substr(start, i - start + 1);
        aux.push_back(ss);
        dfs(s, i + 1, aux);
        aux.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    int len = s.length();
    vector<string> aux;
    dfs(s, 0, aux);
    return res;
  }
};