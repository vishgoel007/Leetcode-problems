// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3463/

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
  bool isRobotBounded(string s) {
    int len = s.length();
    int x = 0, y = 0;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;

    for (int i = 0; i < len; i++) {
      if (s[i] == 'L') {
        // arrange coords in dir by iterating and arranging according to mod(i.e 4)
        d = (d + 3) % 4;
      } else if (s[i] == 'R') {
        d = (d + 1) % 4;
      } else {
        x += dir[d][0];
        y += dir[d][1];
      }
    }

    return (x == 0 && y == 0) || (d != 0);
  }
};