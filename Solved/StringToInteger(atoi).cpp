// https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int result = 0;
    int len = str.length();
    int index = 0;
    int sign = 1;

    while (index < len && str[index] == ' ') index++;

    if (str[index] == '-') {
      sign = -1;
      index++;
    } else if (str[index] == '+') {
      sign = 1;
      index++;
    }

    while (index < len && str[index] >= '0' && str[index] <= '9') {
      int digit = sign * (str[index] - '0');
      if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return INT_MAX;
      if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return INT_MIN;
      result = result * 10 + digit;
      index++;
    }
    return result;
  }
};