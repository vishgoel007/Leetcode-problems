// https://leetcode.com/problems/subsets-ii/

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
  vector<vector<int>> output;

  void helper(vector<int>& nums, vector<int>& aux, int currIndex) {
    output.push_back(aux);
    for (int i = currIndex; i < nums.size(); i++) {
      if (i > currIndex && nums[i] == nums[i - 1]) continue;
      aux.push_back(nums[i]);
      helper(nums, aux, i + 1);
      aux.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> aux;
    helper(nums, aux, 0);
    return output;
  }
};