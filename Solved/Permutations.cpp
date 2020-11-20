// https://leetcode.com/problems/permutations/

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
  vector<vector<int>> output;
  unordered_set<int> set;
  void helper(vector<int>& nums, vector<int>& aux) {
    if (aux.size() == nums.size()) {
      output.push_back(aux);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (set.count(nums[i])) continue;
      set.insert(nums[i]);
      aux.push_back(nums[i]);
      helper(nums, aux);
      set.erase(nums[i]);
      aux.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> aux;
    helper(nums, aux);
    return output;
  }
};

// alternate method
class Solution {
 public:
  vector<vector<int>> output;
  void helper(vector<int>& nums, int start) {
    if (start == nums.size()) {
      output.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);
      helper(nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    helper(nums, 0);
    return output;
  }
};