// https://leetcode.com/problems/next-permutation/

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
  void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    int index = len - 2;

    // Step1: Find the first non increasing element from the right
    while (index >= 0) {
      if (nums[index] < nums[index + 1]) break;
      index--;
    }

    // if all elements are in decreasing order (or increasing from right)
    if (index == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // Step2: Find the just increasing element in right of element found in step1
    // and swap each other
    int j = len - 1;
    for (; j > index; j--) {
      if (nums[index] < nums[j]) {
        swap(nums[index], nums[j]);
        break;
      }
    }

    // Step3: reverse all elements right elements from element fount in step1
    reverse(nums.begin() + index + 1, nums.end());
  }
};