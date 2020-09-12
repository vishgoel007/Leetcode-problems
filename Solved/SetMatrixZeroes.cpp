// https://leetcode.com/problems/set-matrix-zeroes/

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
  void setZeroes(vector<vector<int>>& matrix) {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    bool isRowZero = false, isColZero = false;

    for (int row = 0; row < rowSize; row++) {
      for (int col = 0; col < colSize; col++) {
        if (matrix[row][col] == 0) {
          if (row == 0 && col == 0) {
            isColZero = true;
            isRowZero = true;
          } else if (row == 0)
            isColZero = true;
          else if (col == 0)
            isRowZero = true;
          matrix[row][0] = 0;
          matrix[0][col] = 0;
        }
      }
    }

    for (int row = 1; row < rowSize; row++) {
      for (int col = 1; col < colSize; col++) {
        if (matrix[0][col] == 0 || matrix[row][0] == 0)
          matrix[row][col] = 0;
      }
    }

    if (isRowZero) {
      for (int row = 0; row < rowSize; row++) {
        matrix[row][0] = 0;
      }
    }

    if (isColZero) {
      for (int col = 0; col < colSize; col++) {
        matrix[0][col] = 0;
      }
    }
  }
};