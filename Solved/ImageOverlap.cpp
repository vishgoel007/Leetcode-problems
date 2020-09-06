// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3450/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// drawback of thus algorithm is that we would scan through those zones that are
// filled with zeros over and over, even though these zones are not of our interests.
// to avoid this take map of all ONE's cell pos of A and B in map
class Solution {
 public:
  int overlapCount(vector<vector<int>>& A, vector<vector<int>>& B, int xShift, int yShift) {
    int count = 0;
    int len = A.size();
    for (int xRow = xShift, row = 0; xRow < len; xRow++, row++) {
      for (int yCol = yShift, col = 0; yCol < len; yCol++, col++) {
        if (A[xRow][yCol] & B[row][col]) count++;
      }
    }
    return count;
  }

  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int len = A.size();
    int ans = -1;
    for (int row = 0; row < len; row++) {
      for (int col = 0; col < len; col++) {
        ans = max(ans, overlapCount(A, B, row, col));
        ans = max(ans, overlapCount(B, A, row, col));
      }
    }
    return ans;
  }
};
