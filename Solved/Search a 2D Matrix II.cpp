// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// O(m+n)
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;

    int n = matrix[0].size();
    if (n == 0) return false;

    int r = m - 1, c = 0;
    while (r >= 0 && c < n) {
      if (matrix[r][c] == target)
        return true;
      else if (matrix[r][c] > target)
        r--;
      else
        c++;
    }
    return false;
  }
};

// using binary search
class Solution {
 public:
  bool search(vector<vector<int>>& matrix, int target, int rl, int rh, int cl, int ch) {
    if (rl > rh || cl > ch) return false;

    int rMid = rl + (rh - rl) / 2;
    int cMid = cl + (ch - cl) / 2;
    int val = matrix[rMid][cMid];

    if (val == target) return true;

    if (target > val)
      return search(matrix, target, rl, rMid, cMid + 1, ch) ||    // search in upper right matrix from val
             search(matrix, target, rMid + 1, rh, cl, ch);        // search in lower side matrix from val

    return search(matrix, target, rl, rh, cl, cMid - 1) ||    // search in left side matrix from val
           search(matrix, target, rl, rMid - 1, cl, ch);      // search in upper right matrix from val
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;

    int n = matrix[0].size();
    if (n == 0) return false;

    return search(matrix, target, 0, m - 1, 0, n - 1);
  }
};