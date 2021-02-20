// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/555/week-2-september-8th-september-14th/3457/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// TC O(9!.k/(9-k)!)
// SC O(K)
// Backtracking
class Solution {
 public:
  vector<vector<int>> output;

  void helper(vector<int>& range, vector<int>& aux, int currIndex, int k, int target) {
    if (target == 0 && aux.size() == k) {
      output.push_back(aux);
      return;
    }
    for (int i = currIndex; i < range.size(); i++) {
      if (target - range[i] >= 0) {
        aux.push_back(range[i]);
        helper(range, aux, i + 1, k, target - range[i]);
        aux.pop_back();
      }
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> range = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> aux;
    helper(range, aux, 0, k, n);
    return output;
  }
};