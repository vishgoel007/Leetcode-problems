// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3412/

#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int num) {
    if (num == 0) return false;
    return floor(log(num) / log(4)) == ceil(log(num) / log(4));
  }
};