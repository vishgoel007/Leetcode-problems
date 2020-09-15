// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3461/

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
  int lengthOfLastWord(string s) {
    if (s.length() == 0) return 0;
    int i = s.length() - 1;
    int count = 0;

    while (i >= 0 && s[i] == ' ') i--;
    while (i >= 0 && s[i--] != ' ') count++;

    return count;
  }
};