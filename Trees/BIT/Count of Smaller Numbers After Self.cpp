// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * using Binary indexed tree(BIT)
 * Note that BIT only supports prefix information querying,
 * so we can only query from start to a certain element, not any interval.
 */
class Solution {
 public:
  void updateBIT(vector<int>& BIT, int index, int m) {
    index++;
    while (index < m) {
      BIT[index]++;
      index = index + (index & -index);
    }
  }

  int queryBIT(vector<int>& BIT, int index) {
    index++;
    int count = 0;
    while (index > 0) {
      count += BIT[index];
      index = index - (index & -index);
    }
    return count;
  }

  vector<int> countSmaller(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return {};

    vector<int> res(len);

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    // 1 added to avoid 0th index element
    const int m = (maxVal - minVal + 1) + 2;

    vector<int> BIT(m);

    for (int i = len - 1; i >= 0; i--) {
      int value = nums[i] - minVal + 1;
      res[i] = queryBIT(BIT, value - 1);
      updateBIT(BIT, value, m);
    }

    return res;
  }
};

// TODO by other ways