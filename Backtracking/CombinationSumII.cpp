// https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// for TC
// https://leetcode.com/problems/combination-sum-ii/discuss/205387/JavaScript-O(n*2n)-time-O(2n)-space-backtracking
class Solution {
 public:
  vector<vector<int>> output;
  void helper(vector<int>& candidates, int target, vector<int> aux, int currIndex) {
    if (target == 0) {
      output.push_back(aux);
      return;
    }
    for (int i = currIndex; i < candidates.size(); i++) {
      // skip duplicates candidates
      if (i > currIndex && candidates[i] == candidates[i - 1]) continue;
      if (target - candidates[i] >= 0) {
        aux.push_back(candidates[i]);
        helper(candidates, target - candidates[i], aux, i + 1);
        aux.pop_back();
      }
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> aux;
    helper(candidates, target, aux, 0);
    return output;
  }
};