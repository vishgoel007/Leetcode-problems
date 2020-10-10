// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3490/

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
  int findMinArrowShots(vector<vector<int>>& points) {
    int len = points.size();
    if (len == 0 || len == 1) return len;
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int count = 0, end = INT_MIN;
    for (auto p : points) {
      if (p[0] > end) {
        count++;
        end = p[1];
      }
    }
    return count;
  }
};