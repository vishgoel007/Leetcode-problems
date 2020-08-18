// https://leetcode.com/problems/power-of-three/

#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

#define ep

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    double d = log10(n) / log10(3);
    return d == int(d);
  }
};
