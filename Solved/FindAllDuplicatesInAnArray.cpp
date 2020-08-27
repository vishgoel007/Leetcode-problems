// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3414/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> output;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (nums[abs(nums[i]) - 1] < 0)
        output.push_back(abs(nums[i]));
      nums[abs(nums[i]) - 1] *= -1;
    }
    return output;
  }
};