// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// sliding window O(n)
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int len = nums.size();
    int start = 0, end = 0, res = len + 1, currSum = 0;

    while (start < len) {
      if (end < len && currSum < s) {
        currSum += nums[end];
        end++;
      } else {
        currSum -= nums[start];
        start++;
      }
      if (currSum >= s) res = min(res, end - start);
    }
    return res % (len + 1);
  }
};

// above simplified (sliding window) O(n)
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int len = nums.size();
    int start = 0, end = 0, res = len + 1, currSum = 0;

    while (end < len) {
      currSum += nums[end];
      end++;
      while (currSum >= s) {
        res = min(res, end - start);
        currSum -= nums[start];
        start++;
      }
    }
    return res % (len + 1);
  }
};

// using binary search (nlogn)
class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int len = nums.size();

    vector<int> prefix(len + 1, 0);
    for (int i = 1; i <= len; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int res = len + 1;
    for (int i = 1; i <= len; i++) {
      int toFind = s + prefix[i - 1];
      auto bound = lower_bound(prefix.begin(), prefix.end(), toFind);
      if (bound != prefix.end()) {
        int j = bound - prefix.begin();
        res = min(res, j - (i - 1));
      }
    }

    return res % (len + 1);
  }
};