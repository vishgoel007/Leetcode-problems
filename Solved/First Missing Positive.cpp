// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/558/week-5-september-29th-september-30th/3478/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    int it = 0;
    while (it < len) {
      if (nums[it] > 0 && nums[it] <= len && (nums[it] - 1) != it && nums[nums[it] - 1] != nums[it]) {
        swap(nums[it], nums[nums[it] - 1]);
      } else
        it++;
    }
    for (int i = 0; i < len; i++) {
      if (i != nums[i] - 1) return i + 1;
    }
    return len + 1;
  }
};