//https://leetcode.com/contest/biweekly-contest-35/problems/make-sum-divisible-by-p/

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

class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    int len = nums.size();
    int remainder = 0;

    // to avoid overflow
    for (int i = 0; i < len; i++) remainder = (remainder + nums[i]) % p;

    if (!remainder) return 0;

    // need too find shortest array with sum(nums) % p = remainder.
    unordered_map<int, int> mp;
    int curr = 0, ans = len;
    for (int i = 0; i < len; i++) {
      curr = (curr + nums[i]) % p;
      if (curr == remainder) ans = min(ans, i + 1);

      // p is added to avoid (curr - remainder) < 0 situation
      int newRemainderToSearch = (curr - remainder + p) % p;

      if (mp.count(newRemainderToSearch)) {
        ans = min(ans, i - mp[newRemainderToSearch]);
      }
      mp[curr] = i;
    }
    return ans;
  }
};