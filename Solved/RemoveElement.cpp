// https://leetcode.com/problems/remove-element/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int> &nums, int val) {
    int len = nums.size();
    int repeatIndex = 0, nonRepeatIndex = 0;
    int index = 0;

    while (repeatIndex < len && nonRepeatIndex < len) {
      while (repeatIndex < len && nums[repeatIndex] != val) repeatIndex++;
      while (nonRepeatIndex < len && nums[nonRepeatIndex] == val) nonRepeatIndex++;
      if (nonRepeatIndex < repeatIndex) {
        nonRepeatIndex++;
        continue;
      }
      if (repeatIndex < len && nonRepeatIndex < len)
        swap(nums[repeatIndex], nums[nonRepeatIndex]);
    }
    return repeatIndex;
  }
};