// https://leetcode.com/problems/range-sum-query-2d-mutable/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Using BIT
class NumMatrix {
 public:
  vector<vector<int>> mat;
  vector<vector<int>> bit;
  int rows, cols;

  NumMatrix(vector<vector<int>>& matrix) {
    rows = matrix.size();
    if (rows == 0) return;
    cols = matrix[0].size();

    mat.resize(rows, vector<int>(cols, 0));
    bit.resize(rows + 1, vector<int>(cols + 1, 0));

    buildBit(matrix);
  }

  int queryBit(int r, int c) {
    r++, c++;
    int sum = 0;
    for (int i = r; i > 0; i -= (i & -i)) {
      for (int j = c; j > 0; j -= (j & -j)) {
        sum += bit[i][j];
      }
    }
    return sum;
  }

  void updateBit(int r, int c, int val) {
    int delta = val - mat[r][c];
    mat[r][c] = val;

    r++, c++;
    for (int i = r; i <= rows; i += (i & -i)) {
      for (int j = c; j <= cols; j += (j & -j)) {
        bit[i][j] += delta;
      }
    }
  }

  void buildBit(vector<vector<int>>& matrix) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        updateBit(i, j, matrix[i][j]);
      }
    }
  }

  void update(int row, int col, int val) {
    updateBit(row, col, val);
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int a = queryBit(row2, col2);
    int b = queryBit(row1 - 1, col1 - 1);
    int c = queryBit(row2, col1 - 1);
    int d = queryBit(row1 - 1, col2);

    return (a + b) - (c + d);
  }
};
