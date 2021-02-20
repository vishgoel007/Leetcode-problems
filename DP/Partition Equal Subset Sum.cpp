// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3545/

#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

//  top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  bool helper(vector<int>& nums, int target, int curr) {
    if (target < 0 || curr == nums.size()) return false;
    if (target == 0) return true;

    if (dp[curr][target] != -1) return dp[curr][target];

    bool include = helper(nums, target - nums[curr], curr + 1);
    bool exclude = helper(nums, target, curr + 1);

    return dp[curr][target] = include || exclude;
  }
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    dp.resize(nums.size() + 1, vector<int>(target + 1, -1));
    return helper(nums, target, 0);
  }
};

// ****  using bitset nice solution  *****
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/simple-c-4-line-solution-using-a-bitset

// TODO bottom up dp