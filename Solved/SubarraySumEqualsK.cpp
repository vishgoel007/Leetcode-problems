// https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Brute force N^2
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int len = nums.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
      int sum = 0;
      for (int start = i; start < len; start++) {
        sum += nums[start];
        if (sum == k) count++;
      }
    }
    return count;
  }
};

// Using map O(N)
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_map<int, int> mp;    // {prefixSum, count of prefixSum}
    int count = 0;
    int currSum = 0;

    for (int i = 0; i < len; i++) {
      currSum += nums[i];

      // means there is an subarray from 0 to i
      if (currSum == k) count++;

      // means there is subarray(s) from (currSum - k)th index + 1 to i
      if (mp[currSum - k])
        count += mp[currSum - k];
      mp[currSum]++;
    }
    
    return count;
  }
};