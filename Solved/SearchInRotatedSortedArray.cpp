// https://leetcode.com/problems/search-in-rotated-sorted-array/


// can be done in single iteration by compairing mid,target with low/high
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchPivot(vector<int> nums) {
    int len = nums.size();
    int low = 0, high = len - 1;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (mid < high && nums[mid] > nums[mid + 1])
        return mid;
      else if (mid > low && nums[mid] < nums[mid - 1])
        return mid - 1;
      else if (nums[low] > nums[mid])
        high = mid - 1;
      else if (nums[high] < nums[mid])
        low = mid + 1;
      else
        return -1;
    }
    return -1;
  }

  int binarySearch(vector<int> nums, int low, int high, int target) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }

  int search(vector<int>& nums, int target) {
    int len = nums.size();

    int pivot = searchPivot(nums);

    if (pivot != -1) {
      if (nums[pivot] == target) return pivot;

      int right = binarySearch(nums, pivot + 1, len - 1, target);
      int left = binarySearch(nums, 0, pivot - 1, target);
      if (left != -1) return left;
      if (right != -1) return right;
    } else {
      int index = binarySearch(nums, 0, len - 1, target);
      if (index != -1) return index;
    }

    return -1;
  }
};

// simple one pass approach
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
