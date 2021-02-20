// https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1389/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// follow 0/1 knapsack

/**
 * This problem can be reduced to find 
 * number of sub arrays whose sum is equal to target eg
 * sum(postives) - sum(negatives) = target and  ---> 1
 * sum(postives) + sums(negatives) = sum(array)  ---> 2
 * using equation 1 and 2 sum(postives) = (target + sum(array)) / 2
 * So we need to find all possible sum(postives) i.e 
 * all the subsets of array whose sum is (target + sum(array)) / 2
*/

// subset array sum
// using 1D bottom up dp
class Solution {
 public:
  int subsetSum(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < len; i++) {
      for (int s = target; s >= nums[i]; s--)
        dp[s] = dp[s] + dp[s - nums[i]];
    }
    return dp[target];
  }

  int findTargetSumWays(vector<int>& nums, int S) {
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++) totalSum += nums[i];

    if (((long)S + totalSum) % 2 == 1 || abs(totalSum) < S) return 0;

    int newTarget = ((long)S + totalSum) / 2;

    return subsetSum(nums, newTarget);
  }
};

// using bottom up dp
class Solution {
 public:
  vector<vector<int>> dp;
  int findTargetSumWays(vector<int>& nums, int S) {
    int len = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];

    if (S < -sum || S > sum) return 0;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum * 2 + 1, 0));

    dp[0][sum] = 1;    // means dp[0][0] = 1 , sum is using to avoid negative index

    for (int i = 1; i <= nums.size(); i++) {
      for (int k = 0; k <= sum * 2; k++) {
        if (k - nums[i - 1] >= 0)
          dp[i][k] += dp[i - 1][k - nums[i - 1]];
        if (k + nums[i - 1] <= 2 * sum)
          dp[i][k] += dp[i - 1][k + nums[i - 1]];
      }
    }

    return dp[len][sum + S];
  }
};

// using top down dp
class Solution {
 public:
  vector<vector<int>> dp;
  int constant;
  int ways(vector<int>& nums, int S, int index, int totalSum) {
    if (index == nums.size()) {
      if (totalSum == S)
        return 1;
      return 0;
    }

    // constant offset is added to avoid negative index
    if (dp[index][totalSum + constant] != INT_MIN) return dp[index][totalSum + constant];

    // total ways calculated when number is added
    int add = ways(nums, S, index + 1, totalSum + nums[index]);

    // total ways calculated when number is subtracted
    int subtract = ways(nums, S, index + 1, totalSum - nums[index]);

    dp[index][totalSum + constant] = add + subtract;

    return dp[index][totalSum + constant];
  }
  int findTargetSumWays(vector<int>& nums, int S) {
    constant = 0;
    for (int i = 0; i < nums.size(); i++) constant += nums[i];
    dp.resize(nums.size() + 1, vector<int>(constant * 2 + 1, INT_MIN));
    return ways(nums, S, 0, 0);
  }
};

// using recursion
class Solution {
 public:
  int count;
  void ways(vector<int>& nums, int S, int index, int totalSum) {
    if (index == nums.size()) {
      if (totalSum == S) count++;
      return;
    }
    ways(nums, S, index + 1, totalSum + nums[index]);
    ways(nums, S, index + 1, totalSum - nums[index]);
  }
  int findTargetSumWays(vector<int>& nums, int S) {
    count = 0;
    ways(nums, S, 0, 0);
    return count;
  }
};

//https://leetcode.com/problems/target-sum/discuss/97363/C%2B%2B-iterative-with-unordered_map
// https://leetcode.com/problems/target-sum/discuss/832275/java-simple-accepted-solution(2ms)-faster-than-96.78-.Top-down-DP(using-subsetSum)