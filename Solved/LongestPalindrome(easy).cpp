// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3423/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    int len = s.length();
    vector<int> vec(60, 0);
    int count = 0;

    for (int i = 0; i < len; i++) {
      int c = s[i] - 'A';
      vec[c]++;
      if (vec[c] == 2) {
        count += 2;
        vec[c] = 0;
      }
    }

    return len == count ? count : count + 1;
  }
};