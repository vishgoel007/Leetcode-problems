// https://leetcode.com/problems/spiral-matrix-iii/

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
  int m, n;
  bool isValid(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
  }
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    this->m = R, this->n = C;

    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> res;

    int d = 0, r = r0, c = c0;

    res.push_back({r, c});
    if (R * C == 1) return res;

    for (int step = 1; res.size() < R * C; step++) {
      // for (top and left) and (bottom, right)
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < step; j++) {
          r += dir[d][0];
          c += dir[d][1];
          if (isValid(r, c)) res.push_back({r, c});
        }
        d = (d + 1) % 4;
      }
    }
    return res;
  }
};