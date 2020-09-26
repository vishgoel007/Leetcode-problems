// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int arrangeCoins(int n) {
    double ans;
    ans = (-0.5 + sqrt(0.25 + (long)2 * n));
    return (int)ans;
  }
};