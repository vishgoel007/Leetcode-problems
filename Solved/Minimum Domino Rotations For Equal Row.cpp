// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3500/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// mine
class Solution {
 public:
  int solve(vector<int>& A, vector<int>& B) {
    int len = A.size();

    vector<int> mpA(7, 0);
    vector<int> mpB(7, 0);

    for (int i = 0; i < len; i++) {
      if (A[i] != B[i]) mpB[B[i]]++;
      mpA[A[i]]++;
    }

    int res = INT_MAX;
    for (int i = 1; i < 7; i++) {
      if (mpA[i] + mpB[i] >= len) {
        res = min(res, len - mpA[i]);
      }
    }

    return res;
  }
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int res = min(solve(A, B), solve(B, A));
    return res == INT_MAX ? -1 : res;
  }
};

// same as above but optimized(single pass)
class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int len = A.size();

    vector<int> mpA(7, 0), mpB(7, 0), same(7, 0);

    for (int i = 0; i < len; i++) {
      mpB[B[i]]++;
      mpA[A[i]]++;
      if (A[i] == B[i]) same[A[i]]++;
    }

    for (int i = 1; i < 7; i++) {
      if (mpA[i] + mpB[i] - same[i] >= len) {
        return min(mpA[i] - same[i], mpB[i] - same[i]);
      }
    }
    return -1;
  }
};