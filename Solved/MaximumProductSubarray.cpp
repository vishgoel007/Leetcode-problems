// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3456/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// method 1 (my own)
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int pos = 1, nevFront = 1, nevBack = 1;
    int ans = 0;

    if (len == 1 && nums[0] < 0) return nums[0];

    for (int i = 0; i < len; i++) {
      pos = pos == 0 ? nums[i] : pos * nums[i];
      pos = pos == 0 ? 0 : pos;

      nevFront = nevFront == 0 ? nums[i] : nevFront * nums[i];

      nevBack = nevBack == 0 ? nums[len - i - 1] : nevBack * nums[len - i - 1];

      ans = max(max(ans, pos), max(nevFront, nevBack));
    }

    return ans;
  }
};

// method 2 (calculating max from both sides)
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int len = nums.size();
    int left = 0, right = 0;
    int ans = nums[0];

    for (int i = 0; i < len; i++) {
      left = (left == 0 ? 1 : left) * nums[i];
      right = (right == 0 ? 1 : right) * nums[len - 1 - i];
      ans = max(ans, max(left, right));
    }
    return ans;
  }
};