// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int titleToNumber(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++) {
      ans += (s[i] - 'A' + 1) * pow(26, len - i - 1);
    }
    return ans;
  }
};