// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

// Moore’s Voting Algorithm

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0, ele = -1;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (count == 0) {
        ele = nums[i];
        count++;
      } else if (ele == nums[i])
        count++;
      else
        count--;
    }
    count = 0;
    for (int i = 0; i < len; i++) {
      if (ele == nums[i]) count++;
      if (count >= len / 2) return ele;
    }
    return ele;
  }
};