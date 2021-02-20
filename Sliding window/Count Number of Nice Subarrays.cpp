// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// mine
class Solution {
 public:
  int atMostK(vector<int>& nums, int k) {
    int len = nums.size();
    int start = 0, end = 0;
    int ans = 0, odds = 0;

    while (end < len) {
      if (nums[end] & 1) odds++;
      end++;

      while (odds > k) {
        if (nums[start] & 1) odds--;
        start++;
      }
      ans += (end - start);
    }
    return ans;
  }
  int numberOfSubarrays(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
  }
};

// with one pass
class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int len = nums.size();
    int start = 0, end = 0;
    int ans = 0, subrrayCount = 0;
    while (end < len) {
      if (nums[end] & 1) {
        subrrayCount = 0;
        k--;
      }
      end++;

      while (k <= 0) {
        if (nums[start] & 1) k++;
        start++;
        subrrayCount++;
      }

      ans += subrrayCount;
    }
    return ans;
  }
};

/** 
 * Alternate method
 * 
 * Replace even elements with 0 and odd elements with 1.
 * The problem is then reduced to the number of subarrays with sum k.
 */
