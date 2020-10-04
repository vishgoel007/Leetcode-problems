// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3483/

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
  static bool compare(vector<int>& a, vector<int>& b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
  }
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int res = intervals.size(), end = -1;
    for (auto interval : intervals) {
      if (interval[1] <= end)
        res--;
      else
        end = interval[1];
    }
    return res;
  }
};