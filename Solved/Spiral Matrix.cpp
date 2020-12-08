// https://leetcode.com/problems/spiral-matrix/

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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> res;

    int colStart = 0, colEnd = n - 1, rowStart = 0, rowEnd = m - 1;
    while (colStart <= colEnd && rowStart <= rowEnd) {
      for (int i = colStart; i <= colEnd && res.size() < m * n; i++) {
        res.push_back(matrix[rowStart][i]);
      }
      rowStart++;

      for (int i = rowStart; i <= rowEnd && res.size() < m * n; i++) {
        res.push_back(matrix[i][colEnd]);
      }
      colEnd--;

      for (int i = colEnd; i >= colStart && res.size() < m * n; i--) {
        res.push_back(matrix[rowEnd][i]);
      }
      rowEnd--;

      for (int i = rowEnd; i >= rowStart && res.size() < m * n; i--) {
        res.push_back(matrix[i][colStart]);
      }
      colStart++;
    }

    return res;
  }
};