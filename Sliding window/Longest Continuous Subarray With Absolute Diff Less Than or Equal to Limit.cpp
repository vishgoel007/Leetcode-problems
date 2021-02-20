// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using multiset
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int len = nums.size();
    multiset<int> mset;

    int start = 0, end = 0;
    int maxLen = 0;

    while (end < len) {
      mset.insert(nums[end]);
      end++;
      int maxx = *mset.rbegin();
      int minn = *mset.begin();

      while (maxx - minn > limit) {
        auto it = mset.find(nums[start]);
        mset.erase(it);
        start++;
        maxx = *mset.rbegin();
        minn = *mset.begin();
      }

      maxLen = max(maxLen, end - start);
    }
    return maxLen;
  }
};

// using max/min deque
class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    int len = nums.size();
    deque<int> dmax;
    deque<int> dmin;

    int start = 0, end = 0;
    int maxLen = 0;

    while (end < len) {
      int n = nums[end];

      while (!dmax.empty() && n >= nums[dmax.back()]) dmax.pop_back();
      dmax.push_back(end);

      while (!dmin.empty() && n <= nums[dmin.back()]) dmin.pop_back();
      dmin.push_back(end);

      end++;

      while (nums[dmax.front()] - nums[dmin.front()] > limit) {
        if (start >= dmax.front()) dmax.pop_front();
        if (start >= dmin.front()) dmin.pop_front();
        start++;
      }

      maxLen = max(maxLen, end - start);
    }
    return maxLen;
  }
};