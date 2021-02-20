// https://leetcode.com/problems/combinations/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// can be done using bit masking (iterative way) TODO and time complexity too
class Solution {
 public:
  vector<vector<int>> output;
  void helper(vector<int>& num, vector<int>& aux, int k, int currIndex) {
    if (aux.size() == k) {
      output.push_back(aux);
      return;
    }
    for (int i = currIndex; i < num.size(); i++) {
      aux.push_back(num[i]);
      helper(num, aux, k, i + 1);
      aux.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> num, aux;
    for (int i = 0; i < n; ++i) num.push_back(i + 1);
    helper(num, aux, k, 0);
    return output;
  }
};