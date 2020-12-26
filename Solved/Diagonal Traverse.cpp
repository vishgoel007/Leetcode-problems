// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3580/

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
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return {};

    int n = matrix[0].size();

    vector<int> res(m * n);

    int r = 0, c = 0;
    for (int i = 0; i < m * n; i++) {
      res[i] = matrix[r][c];

      // going upwards
      if ((r + c) % 2 == 0) {
        if (r > 0 && c < n - 1) {
          r = r - 1;
          c = c + 1;
        } else if (r <= 0 && c < n - 1) {
          c = c + 1;
        } else if (r < m - 1 && c >= n - 1) {
          r = r + 1;
        }
      }

      // going downards
      else {
        if (r < m - 1 && c > 0) {
          r = r + 1;
          c = c - 1;
        } else if (r < m - 1 && c <= 0) {
          r = r + 1;
        } else if (r >= m - 1 && c < n - 1) {
          c = c + 1;
        }
      }
    }

    return res;
  }
};