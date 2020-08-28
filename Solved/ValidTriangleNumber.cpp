// https://leetcode.com/problems/valid-triangle-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int result = 0;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    for (int i = 0; i < len - 2; i++) {
      for (int j = i + 1; j < len; j++) {
        int sum = nums[i] + nums[j];
        int k = j + 1;
        while (k < len && sum > nums[k]) {
          result++;
          k++;
        }
      }
    }
    return result;
  }
};

class Solution2 {
 public:
  int triangleNumber(vector<int>& nums) {
    int result = 0;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right;
    for (int i = len - 1; i >= 0; i--) {
      int left = 0, right = i - 1;
      while (left < right) {
        if (nums[left] + nums[right] > nums[i]) {
          result += right - left;
          right--;
        } else
          left++;
      }
    }
    return result;
  }
};