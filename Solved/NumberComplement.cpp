// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findComplement(int num) {
    int res = 0, power = 0;
    while (num) {
      int bit = num % 2;
      bit ^= 1;
      res += (bit * 1 << power); // 1<<2 = 1*2*2
      num /= 2;
      power++;
    }
    return res;
  }
};