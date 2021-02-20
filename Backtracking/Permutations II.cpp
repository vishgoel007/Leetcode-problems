// https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// iterative
class Solution {
 public:
  bool nextPermutation(vector<int>& nums) {
    int len = nums.size();
    int index = len - 2;

    // Step1: Find the first non increasing element from the right
    while (index >= 0) {
      if (nums[index] < nums[index + 1]) break;
      index--;
    }

    // if all elements are in decreasing order (or increasing from right)
    if (index == -1) return false;

    // Step2: Find the just increasing element in right of element found in step1
    // and swap each other
    int j = len - 1;
    for (; j > index; j--) {
      if (nums[index] < nums[j]) {
        swap(nums[index], nums[j]);
        break;
      }
    }

    // Step3: reverse all elements right elements from element fount in step1
    reverse(nums.begin() + index + 1, nums.end());

    return true;
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    res.push_back(nums);
    while (nextPermutation(nums)) {
      res.push_back(nums);
    }
    return res;
  }
};

// recursive
class Solution {
 private:
  vector<vector<int>> res;
  map<int, int> mp;

 public:
  void helper(int size, vector<int>& aux) {
    if (aux.size() == size) {
      res.push_back(aux);
      return;
    }
    for (auto m : mp) {
      if (m.second == 0) continue;
      mp[m.first]--;
      aux.push_back(m.first);
      helper(size, aux);
      mp[m.first]++;
      aux.pop_back();
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    for (int n : nums) mp[n]++;
    vector<int> aux;
    helper(nums.size(), aux);
    return res;
  }
};