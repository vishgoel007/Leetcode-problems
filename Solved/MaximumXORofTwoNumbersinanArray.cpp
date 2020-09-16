// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/556/week-3-september-15th-september-21st/3462/

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
  int findMaximumXOR(vector<int>& nums) {
    int maxRes = 0, mask = 0;

    for (int bit = 31; bit >= 0; bit--) {
      // mask = {1000...000} {1100....000} {1110....000} .... {1111...1111}
      mask = mask | (1 << bit);

      unordered_set<int> set;

      for (int n : nums) {
        // insert num values with 'and'
        // operation with mask so that we know whose num value's MSB set
        set.insert(n & mask);
      }

      // check nextSetBit(to the right) in sets
      int checkNextMaxRes = maxRes | (1 << bit);

      for (auto s : set) {
        // if nextset bit to maxRes number is present in set, we found out next maxRes
        if (set.count(s ^ checkNextMaxRes)) {
          maxRes = checkNextMaxRes;
          break;
        }
      }
    }
    return maxRes;
  }
};

// TODO -> solve using trie