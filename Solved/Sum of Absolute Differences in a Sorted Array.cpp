// https://leetcode.com/contest/biweekly-contest-41/problems/sum-of-absolute-differences-in-a-sorted-array/

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
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int len = nums.size();
    vector<int> prefix(len), res(len);

    prefix[0] = nums[0];
    for (int i = 1; i < len; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    for (int i = 0; i < len; i++) {
      int left = (i + 1) * nums[i] - prefix[i];
      int right = (prefix[len - 1] - prefix[i]) - nums[i] * (len - i - 1);
      res[i] = left + right;
    }

    return res;
  }
};