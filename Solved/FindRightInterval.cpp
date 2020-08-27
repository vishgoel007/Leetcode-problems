// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3438/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  static bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
  }

  static bool lbCompare(vector<int> a, int val) {
    return a[0] < val;
  }

  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int len = intervals.size();
    vector<int> output(len, -1);

    vector<vector<int>> startPos;

    for (int i = 0; i < len; i++)
      startPos.push_back({intervals[i][0], i});

    sort(startPos.begin(), startPos.end(), compare);

    for (int i = 0; i < len; i++) {
      int pos = lower_bound(startPos.begin(), startPos.end(), intervals[i][1], lbCompare) - startPos.begin();
      if (pos < len)
        output[i] = startPos[pos][1];
    }

    return output;
  }
};