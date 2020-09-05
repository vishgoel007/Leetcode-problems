// https://leetcode.com/contest/biweekly-contest-34/problems/matrix-diagonal-sum/

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
  int diagonalSum(vector<vector<int>>& mat) {
    int len = mat.size();
    int sum = 0;
    for (int i = 0, j = len - 1; i < len, j >= 0; i++, j--) {
      sum += mat[i][i];
      sum += mat[i][j];
    }
    if (len & 1)
      sum -= mat[len / 2][len / 2];
    return sum;
  }
};