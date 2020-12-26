// https://leetcode.com/problems/sort-the-matrix-diagonally/

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
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m == 0) return {{}};
    int n = mat[0].size();
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    vector<vector<int>> res(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mp[i - j].push(mat[i][j]);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res[i][j] = mp[i - j].top();
        mp[i - j].pop();
      }
    }

    return res;
  }
};