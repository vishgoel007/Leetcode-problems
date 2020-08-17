// https://leetcode.com/problems/powx-n/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    double result = 1.0;
    bool isNegative = n < 0;
    n = abs(n);
    while (n) {
      if (n & 1)
        result *= x;
      x *= x;
      n /= 2;
    }

    result = isNegative ? 1 / result : result;
    return result;
  }
};

// Recursive
class Solution2 {
 public:
  double myPow(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) {
      x = 1 / x;
      if (n & 1)
        return x * myPow(x * x, (n / 2) * -1);
      else
        return myPow(x * x, (n / 2) * -1);
    } else {
      if (n & 1)
        return x * myPow(x * x, (n / 2));
      else
        return myPow(x * x, (n / 2));
    }
  }
};