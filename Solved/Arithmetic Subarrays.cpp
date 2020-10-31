// https://leetcode.com/contest/weekly-contest-212/problems/arithmetic-subarrays/

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
  bool checkIsAP(vector<int>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int d = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
      if (arr[i] - arr[i - 1] != d)
        return false;

    return true;
  }

  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int n = nums.size(), m = l.size();

    vector<bool> res;
    for (int i = 0; i < m; i++) {
      int ll = l[i], rr = r[i];
      vector<int> aux(nums.begin() + ll, nums.begin() + rr + 1);
      res.push_back(checkIsAP(aux));
    }

    return res;
  }
};