// https://leetcode.com/contest/biweekly-contest-33/problems/minimum-numbers-of-function-calls-to-make-target-array/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int len = nums.size();
    int maxEle = INT_MIN;
    int count = 0;
    for (int i = 0; i < len; i++) {
      maxEle = max(maxEle, nums[i]);
      int t = nums[i];

      // or count += __builtin_popcount(nums[i]);
      while (t) {
        if (t & 1) count++;
        t >>= 1;
      }
    }
    
    while (maxEle != 1) {
      maxEle /= 2;
      count++;
    }
    return count;
  }
};