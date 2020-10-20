// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
  return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int len = intervals.size();
    if (len == 0 || len == 1) return intervals;

    sort(intervals.begin(), intervals.end(), compare);
    vector<vector<int>> output;

    output.push_back(intervals[0]);

    for (int i = 1; i < len; i++) {
      auto prev = output.back();
      auto curr = intervals[i];
      if (curr[0] > prev[1]) {
        output.push_back(curr);
      } else {
        output.pop_back();
        output.push_back({prev[0], max(prev[1], curr[1])});
      }
    }

    return output;
  }
};

/** Follow up Question**/
// https://leetcode.com/problems/merge-intervals/solution/321556