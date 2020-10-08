// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3488/

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
  int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] > target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
  int search(vector<int>& nums, int target) {
    return binarySearch(nums, target);
  }
};
