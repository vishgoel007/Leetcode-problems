// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// TC O(N^(T/M +1))
// N = len(candidates), T = target, M = minimal value in candidates.
// SC O(T/M)
// Backtracking
class Solution {
 public:
  vector<vector<int>> output;

  void helper(vector<int>& candidates, int target, vector<int> aux) {
    if (target == 0) {
      output.push_back(aux);
      return;
    }
    for (int i = 0; i < candidates.size(); i++) {
      if (target - candidates[i] >= 0) {
        aux.push_back(candidates[i]);
        helper(candidates, target - candidates[i], aux);
        aux.pop_back();
      }
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> aux;
    helper(candidates, target, aux);
    return output;
  }
};