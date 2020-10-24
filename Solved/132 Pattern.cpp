// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3505/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// O(N^2)
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int len = nums.size();
    int minI = INT_MAX;
    for (int j = 0; j < len; j++) {
      minI = min(minI, nums[j]);
      for (int k = j + 1; k < len; k++) {
        if (nums[j] > nums[k] && minI < nums[k]) return true;
      }
    }
    return false;
  }
};

// O(N)
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int len = nums.size();
    if (len < 3) return false;

    vector<int> leftMin(len);
    leftMin[0] = nums[0];
    for (int i = 1; i < len; i++) {
      leftMin[i] = min(nums[i], leftMin[i - 1]);
    }

    stack<int> st;
    for (int j = len - 1; j >= 0; j--) {
      // found nums[j] element
      if (nums[j] > leftMin[j]) {
        // searching for num[k] element
        while (!st.empty() && st.top() <= leftMin[j]) st.pop();

        if (!st.empty() && st.top() < nums[j]) return true;

        st.push(nums[j]);
      }
    }

    return false;
  }
};