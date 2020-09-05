// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeBackspace(string s) {
    int len = s.length();
    int asteriskCount = 0;
    string m = "";
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == '#')
        asteriskCount++;
      else {
        if (asteriskCount > 0)
          asteriskCount--;
        else
          m += s[i];
      }
    }
    return m;
  }

  bool backspaceCompare(string S, string T) {
    int sLen = S.length();
    int tLen = T.length();
    string s = removeBackspace(S);
    string t = removeBackspace(T);
    return s.compare(t) == 0;
  }
};