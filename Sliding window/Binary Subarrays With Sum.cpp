// https://leetcode.com/problems/binary-subarrays-with-sum/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using map
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    unordered_map<int, int> mp;
    int currSum = 0, count = 0;

    for (int i = 0; i < A.size(); i++) {
      currSum += A[i];
      if (currSum == S) count++;
      if (mp[currSum - S]) count += mp[currSum - S];
      mp[currSum - S]++;
    }
    return count;
  }
};

// using sliding window
class Solution {
 public:
  int atMost(vector<int>& A, int K) {
    if (K < 0) return 0;
    int start = 0, end = 0;
    int count = 0;

    while (end < A.size()) {
      K -= A[end];
      end++;
      while (K < 0) {
        K += A[start];
        start++;
      }
      count += end - start;
    }
    return count;
  }
  int numSubarraysWithSum(vector<int>& A, int S) {
    return atMost(A, S) - atMost(A, S - 1);
  }
};