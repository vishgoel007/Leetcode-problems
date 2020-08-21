// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int len = A.size();
    int oddIndex = 0, evenIndex = 0;
    while (oddIndex < len && evenIndex < len) {
      while (oddIndex < len && A[oddIndex] % 2 == 0) oddIndex++;
      while (evenIndex < len && A[evenIndex] % 2 != 0) evenIndex++;
      if (oddIndex < len && evenIndex < len && oddIndex < evenIndex) {
        swap(A[oddIndex], A[evenIndex]);
        oddIndex++;
      } else {
        evenIndex++;
      }
    }
    return A;
  }
};