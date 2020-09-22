// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3469/

#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Note : Even we can use the same moore voting algo to find n/k elements in array
 * using O(K) space, taking element ans its count in consideration, all four steps
 * will be processed as below for n/k too.
 */
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int len = nums.size();

    int first = -1, second = -1;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < len; i++) {
      // step 1
      if (first == nums[i]) {
        first = nums[i];
        count1++;
      } else if (second == nums[i]) {
        second = nums[i];
        count2++;
      }
      // step 2
      else if (count1 == 0) {
        first = nums[i];
        count1++;
      } else if (count2 == 0) {
        second = nums[i];
        count2++;
      }
      // step 3
      else if (first != nums[i] && second != nums[i]) {
        count1--;
        count2--;
      }
    }

    count1 = 0;
    count2 = 0;
    // step 4
    for (int i = 0; i < len; i++) {
      if (nums[i] == first) count1++;
      if (nums[i] == second) count2++;
    }
    vector<int> res;
    if (count1 > len / 3) res.push_back(first);
    if (count2 > len / 3) res.push_back(second);

    return res;
  }
};