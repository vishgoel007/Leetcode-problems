// https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3475/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using sliding window
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int len = nums.size();
    if (k <= 1) return 0;

    int count = 0, r = 0, prod = 1;
    for (int l = 0; l < len; l++) {
      while (r < len && prod < k) prod *= nums[r++];
      count += (r - l);
      if (prod >= k) count--;
      prod = prod / nums[l];
    }
    return count;
  }
};

/**
 * can be done using log property
 * as log(a*b*c) = log(a) + log(b) + log(c)
 * take a prefix array of sums of log(nums)
 * this can deduce the problem to find subarrays
 * to prefix[j] - prefix[i] < log(k). 
 */