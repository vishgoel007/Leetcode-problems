// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    bool isFirstCapital = false;
    bool isSecondCapital = false;
    int len = word.length();

    for (int i = 0; i < len; i++) {
      if (i == 0) {
        if (word[i] >= 'A' && word[i] <= 'Z')
          isFirstCapital = true;
        continue;
      }

      if (i == 1) {
        if (word[i] >= 'A' && word[i] <= 'Z')
          isSecondCapital = true;
        continue;
      }

      if (!isFirstCapital && isSecondCapital) return false;
      if (!isFirstCapital && !isSecondCapital && (word[i] >= 'A' && word[i] <= 'Z')) return false;
      if ((isFirstCapital && isSecondCapital) && (word[i] < 'A' || word[i] > 'Z')) return false;
      if ((isFirstCapital && !isSecondCapital) && (word[i] < 'a' || word[i] > 'z')) return false;
    }

    if (!isFirstCapital && isSecondCapital)
      return false;
    return true;
  }
};