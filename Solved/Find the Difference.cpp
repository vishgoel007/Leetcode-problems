// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3471/

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
  char findTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    int i = -1, len = s.length();
    while (++i < len) {
      if (s[i] != t[i]) return t[i];
    }
    return t[len];
  }
};

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int len = s.length();
    char a;
    for (int i = 0; i < len; i++) {
      a = a ^ s[i];
      a = a ^ t[i];
    }
    a = a ^ t[len];

    return a;
  }
};

class Solution {
 public:
  char findTheDifference(string s, string t) {
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++) {
      sum -= (s[i] - 'a');
      sum += (t[i] - 'a');
    }
    sum += (t[len] - 'a');

    return (char)sum + 'a';
  }
};