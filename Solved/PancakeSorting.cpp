// https://leetcode.com/explore/featured/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3441/

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
  int getMaxEleIndex(vector<int>& A, int size) {
    int mx = INT_MIN;
    int index = -1;
    for (int i = 0; i <= size; i++) {
      if (A[i] > mx) {
        mx = A[i];
        index = i;
      }
    }
    return index;
  }
  
  vector<int> pancakeSort(vector<int>& A) {
    int len = A.size() - 1;
    vector<int> output;

    while (len > 0) {
      int maxIndex = getMaxEleIndex(A, len);

      if (maxIndex == len) {
        len--;
        continue;
      }

      auto it = A.begin();

      output.push_back(maxIndex + 1);
      reverse(it, it + maxIndex + 1);
      output.push_back(len + 1);
      reverse(it, it + len + 1);
      len--;
    }

    return output;
  }
};