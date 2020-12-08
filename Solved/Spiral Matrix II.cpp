// https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3557/

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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));

    int colStart = 0, colEnd = n - 1, rowStart = 0, rowEnd = n - 1, count = 1;

    while (colStart <= colEnd && rowStart <= rowEnd) {
      // top
      for (int i = colStart; i <= colEnd; i++) {
        res[rowStart][i] = count++;
      }
      rowStart++;

      // right
      for (int i = rowStart; i <= rowEnd; i++) {
        res[i][colEnd] = count++;
      }
      colEnd--;

      // bottom
      for (int i = colEnd; i >= colStart; i--) {
        res[rowEnd][i] = count++;
      }
      rowEnd--;

      // left
      for (int i = rowEnd; i >= rowStart; i--) {
        res[i][colStart] = count++;
      }
      colStart++;
    }

    return res;
  }
};