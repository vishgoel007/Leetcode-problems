// https://leetcode.com/problems/contiguous-array/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    int len = nums.size();
    int count = 0;
    int maxLen = 0;

    for (int i = 0; i < len; i++) {
      count += (nums[i] == 1 ? 1 : -1);
      if (count == 0) maxLen = max(maxLen, i + 1);
      if (mp.count(count)) {
        maxLen = max(maxLen, i - mp[count]);
      } else
        mp[count] = i;
    }

    return maxLen;
  }
};