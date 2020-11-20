// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

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
  int searchPivot(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;

      if (mid < high && nums[mid] > nums[mid + 1]) return nums[mid + 1];
      if (mid > low && nums[mid] < nums[mid - 1]) return nums[mid];

      while (nums[low] == nums[mid] && low != mid) low++;
      while (nums[high] == nums[mid] && high != mid) high--;

      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return nums[low];
  }
  int findMin(vector<int>& nums) {
    return searchPivot(nums);
  }
};