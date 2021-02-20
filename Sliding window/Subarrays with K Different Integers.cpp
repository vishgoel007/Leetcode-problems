// https://leetcode.com/problems/subarrays-with-k-different-integers/

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
  int atMostKDistinct(vector<int>& A, int k) {
    int len = A.size();
    vector<int> mp(len + 1, 0);
    int start = 0, end = 0, res = 0, currDistinct = 0;

    while (end < len) {
      // expand window till currDistinct > k
      int endNum = A[end];
      if (mp[endNum] == 0) currDistinct++;
      mp[endNum]++;
      end++;

      // shrink window from start till currDistinct <=k
      while (currDistinct > k) {
        int startNum = A[start];
        mp[startNum]--;
        if (mp[startNum] == 0) currDistinct--;
        start++;
      }

      // adding all contiguous subarrays from start to end
      // explanation - https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC++Python-Sliding-Window/556706
      if (currDistinct <= k) res += (end - start);
    }
    return res;
  }
  int subarraysWithKDistinct(vector<int>& A, int K) {
    return atMostKDistinct(A, K) - atMostKDistinct(A, K - 1);
  }
};


// alternate method (with one pass)
// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/638798/c%2B%2B-code-with-through-explanation
