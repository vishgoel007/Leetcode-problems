// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3497/

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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.size();
    if (rowSize == 0) return false;

    int colSize = matrix[0].size();
    if (colSize == 0) return false;

    int start = 0, end = rowSize * colSize - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int r = mid / colSize;
      int c = mid % colSize;
      if (matrix[r][c] == target) return true;
      if (matrix[r][c] > target)
        end = mid - 1;
      else
        start = mid + 1;
    }
    return false;
  }
};

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowSize = matrix.size();
    if (rowSize == 0) return false;

    int colSize = matrix[0].size();
    if (colSize == 0) return false;

    int row = rowSize - 1, col = 0;
    while (row >= 0 && col < colSize) {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] > target)
        row--;
      else
        col++;
    }
    return false;
  }
};

// another approach -> search for the row usingBS and then apply BS on that row