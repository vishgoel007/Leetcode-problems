// https://leetcode.com/problems/range-sum-query-mutable/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using BIT
class NumArray {
 public:
  vector<int> BIT;
  vector<int> input;
  int BITSize;

  int queryBIT(int index) {
    index++;
    int sum = 0;
    while (index > 0) {
      sum += BIT[index];
      index = index - (index & -index);
    }
    return sum;
  }

  void updateBIT(int index, int val) {
    index++;
    while (index < BITSize) {
      BIT[index] += val;
      index = index + (index & -index);
    }
  }

  void buildBIT() {
    for (int i = 0; i < input.size(); i++) {
      updateBIT(i, input[i]);
    }
  }

  NumArray(vector<int>& nums) {
    int len = nums.size();
    this->BITSize = len + 2;
    this->input = nums;
    BIT.resize(this->BITSize, 0);
    buildBIT();
  }

  void update(int i, int val) {
    updateBIT(i, val - input[i]);
    input[i] = val;
  }

  int sumRange(int i, int j) {
    return queryBIT(j) - queryBIT(i - 1);
  }
};

// TODO using  segment tree
// TODO using square root decomposition