// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3425/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool sortByFirst(vector<int> a, vector<int> b) {
    return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
  }
  int eraseOverlapIntervals(vector<vector<int> >& intervals) {
    int len = intervals.size();
    if (len == 0) return 0;
    sort(intervals.begin(), intervals.end(), sortByFirst);
    int end = intervals[0][1], count = 0;

    for (int i = 1; i < len; i++) {
      if (end <= intervals[i][0]) {
        end = intervals[i][1];
      } else if (end > intervals[i][0]) {
        count++;
      }
    }

    return count;
  }
};
