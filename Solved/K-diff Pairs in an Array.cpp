// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int len = nums.size();
    map<int, int> mp;

    int repeated = 0;
    for (int n : nums) {
      mp[n]++;
      if (mp[n] == 2) repeated++;
    }

    if (k == 0) return repeated;

    int count = 0;
    for (auto m : mp) {
      if (mp.count(m.first + k)) count++;
    }
    return count;
  }
};