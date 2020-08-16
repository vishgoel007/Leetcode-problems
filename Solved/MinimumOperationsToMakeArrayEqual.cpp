// https://leetcode.com/contest/weekly-contest-202/problems/minimum-operations-to-make-array-equal/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(int n) {
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
      count += (n - (2 * i + 1));
    }
    return count;
  }
};