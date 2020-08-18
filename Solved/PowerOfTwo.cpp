// https://leetcode.com/problems/power-of-three/

#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return 0;
    return !(n & (n - 1));
  }
};