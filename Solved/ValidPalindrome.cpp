// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (j >= i) {
      if (isalnum(s[i]) && isalnum(s[j])) {
        if (tolower(s[i]) == tolower(s[j])) {
          i++;
          j--;
        } else
          return false;
      } else if (!isalnum(s[i]))
        i++;
      else if (!isalnum(s[j]))
        j--;
    }
    return true;
  }
};