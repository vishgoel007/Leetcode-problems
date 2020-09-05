// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3447/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// method 4 (can use kmp too)

//  method 3 ( shifting)
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    for (int i = 0; i <= len / 2; i++) {
      // shifting by i towards left
      string ss = s.substr(i, len) + s.substr(0, i);
      if (ss == s) return true;
    }
    return false;
  }
};

//  method 2
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    string ss = s.substr(1, len) + s.substr(0, len - 1);
    size_t found = ss.find(s);
    return found != string::npos;
  }
};

//  method 1
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    int count = 1;

    while (count < len) {
      string t = s.substr(0, count);
      int start = count;
      string a = s.substr(start, count);
      while (a == t) {
        start += count;
        if (start == len) return true;
        a = s.substr(start, count);
      }
      count++;
    }
    return false;
  }
};