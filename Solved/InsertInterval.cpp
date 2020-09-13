// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3458/

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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int len = intervals.size();
    vector<vector<int>> output;
    int it = 0;

    // first phase -> insert all non-overlapping intervals
    while (it < len && newInterval[0] > intervals[it][1]) {
      output.push_back(intervals[it]);
      it++;
    }

    // second phase -> insert/merge all overlapping intervals
    int mergeMinStart = newInterval[0];
    int mergeMaxEnd = newInterval[1];
    while (it < len && newInterval[1] >= intervals[it][0]) {
      mergeMinStart = min(mergeMinStart, intervals[it][0]);
      mergeMaxEnd = max(mergeMaxEnd, intervals[it][1]);
      it++;
    }
    output.push_back({mergeMinStart, mergeMaxEnd});

    // third phase -> insert all non-overlapping intervals
    while (it < len) {
      output.push_back(intervals[it]);
      it++;
    }

    return output;
  }
};