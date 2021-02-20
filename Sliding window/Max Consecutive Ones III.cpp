// https://leetcode.com/problems/max-consecutive-ones-iii/

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
  int longestOnes(vector<int>& A, int k) {
    int len = A.size();

    int start = 0, end = 0;
    int maxLen = 0;

    while (end < len) {
      if (k >= 0) {
        if (A[end] == 0) k--;
        end++;
      } else {
        if (A[start] == 0) k++;
        start++;
      }
      if (k >= 0) {
        maxLen = max(maxLen, end - start);
      }
    }
    return maxLen;
  }
};

// alternate
class Solution {
 public:
  int longestOnes(vector<int>& A, int k) {
    int len = A.size();

    int start = 0, end = 0;
    int maxLen = 0;

    while (end < len) {
      if (A[end] == 0) k--;
      end++;
      while (k < 0) {
        if (A[start] == 0) k++;
        start++;
      }

      maxLen = max(maxLen, end - start);
    }
    return maxLen;
  }
};