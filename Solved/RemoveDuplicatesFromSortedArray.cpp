// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    int index = 0;
    for (int i = 0; i < len - 1; i++) {
      if (nums[i] != nums[i + 1])
        nums[index++] = nums[i];
    }
    nums[index++] = nums[len - 1];

    return index;
  }
};