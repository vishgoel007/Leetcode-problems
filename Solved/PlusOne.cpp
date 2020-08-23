// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();
    int carry = 1;
    for (int i = len - 1; i >= 0; i--) {
      digits[i] = digits[i] + carry;
      carry = digits[i] / 10;
      digits[i] = digits[i] % 10;
    }
    if (carry != 0) digits.insert(digits.begin(), carry);
    return digits;
  }
};
