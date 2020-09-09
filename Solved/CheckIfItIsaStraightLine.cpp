// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using Ax+By+C = 0

// A = y2 - y1
// B = x1 - x2
// C = -A*x1 - B*y1

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int len = coordinates.size();
    if (len < 3) return true;

    int A = coordinates[1][1] - coordinates[0][1];
    int B = coordinates[0][0] - coordinates[1][0];
    int C = -A * coordinates[0][0] - B * coordinates[0][1];
    for (int i = 2; i < len; i++) {
      if (A * coordinates[i][0] + B * coordinates[i][1] + C != 0) return false;
    }
    return true;
  }
};

// using slopes
class Solution1 {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int len = coordinates.size();
    if (len < 3) return true;

    int xDiff = coordinates[1][0] - coordinates[0][0];
    int yDiff = coordinates[1][1] - coordinates[0][1];
    for (int i = 2; i < len; i++) {
      if (yDiff * (coordinates[i][0] - coordinates[0][0]) != xDiff * (coordinates[i][1] - coordinates[0][1]))
        return false;
    }
    return true;
  }
};