// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> output(len);

    int prod = 1;
    for (int i = 0; i < len; i++) {
      output[i] = prod;
      prod *= nums[i];
    }

    prod = 1;
    for (int i = len - 1; i >= 0; i--) {
      output[i] = output[i] * prod;
      prod *= nums[i];
    }

    return output;
  }
};