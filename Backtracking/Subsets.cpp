// https://leetcode.com/problems/subsets/

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
  void helper(vector<int>& nums, vector<int> aux, int currIndex) {
    output.push_back(aux);
    for (int i = currIndex; i < nums.size(); i++) {
      aux.push_back(nums[i]);
      helper(nums, aux, i + 1);
      aux.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> aux;
    helper(nums, aux, 0);
    return output;
  }
};

// another way to do is generate all subsets by length wise