// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3496/

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
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;
    if (k == 0) return;
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());

    int l = 0, r = len - 1, n = k;
    while (n-- && l <= r) swap(nums[l++], nums[r--]);

    if (n == -1) reverse(nums.begin() + k, nums.end() - k);
  }
};

//  by reversing
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;
    if (k == 0) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

// using aux array
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;
    if (k == 0) return;
    vector<int> aux(nums);
    for (int i = 0; i < len; i++) {
      nums[(i + k) % len] = aux[i];
    }
  }
};

// inspired by this
// http://www.cplusplus.com/reference/algorithm/rotate/
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;
    if (k == 0) return;

    int first = 0, last = len, middle = len - k;
    int next = middle;

    while (first != next) {
      swap(nums[first++], nums[next++]);
      if (next == last)
        next = middle;
      else if (first == middle)
        middle = next;
    }
  }
};