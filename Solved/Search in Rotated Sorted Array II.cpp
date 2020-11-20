// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3537/

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
  bool search(vector<int>& nums, int target) {
    int len = nums.size();
    int low = 0, high = len - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) return true;

      while (nums[low] == nums[mid] && low != mid) low++;
      while (nums[high] == nums[mid] && high != mid) high--;

      if (nums[mid] >= nums[low]) {
        if (nums[mid] > target && nums[low] <= target) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (nums[mid] < target && nums[high] >= target) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return false;
  }
};