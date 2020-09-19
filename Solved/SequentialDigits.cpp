// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3465/

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
  vector<int> res;
  void helper(int num, int low, int high) {
    if (num > high) return;
    if (num >= low && num <= high) {
      res.push_back(num);
    }
    int lastDigit = num % 10;

    // reached at the end of the current iteration
    if (lastDigit < 9) {
      int next = num * 10 + lastDigit + 1;
      helper(next, low, high);
    }
  }
  vector<int> sequentialDigits(int low, int high) {
    for (int i = 1; i < 9; i++) {
      helper(i, low, high);
    }
    sort(res.begin(), res.end());
    return res;
  }
};