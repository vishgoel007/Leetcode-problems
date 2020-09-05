// https://leetcode.com/contest/biweekly-contest-34/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

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
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int len = arr.size();
    if (len == 1) return 0;

    int l = 0;
    while (l < len - 1 && arr[l] <= arr[l + 1]) l++;
    if (l == len - 1) return 0;

    int r = len - 1;
    while (r >= 1 && arr[r] >= arr[r - 1]) r--;
    if (r == 0) return len - 1;

    // cout << "left" << l << endl;
    // cout << "right" << r << endl;

    int ans = min(len - l - 1, r);
    int s = 0;

    while (s <= l && r < len) {
      if (arr[s] > arr[r]) {
        r++;
      } else {
        ans = min(ans, r - s - 1);
        s++;
      }
    }
    return ans;
  }
};