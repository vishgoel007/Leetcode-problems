// https://leetcode.com/problems/subarray-sums-divisible-by-k/

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

class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    int len = A.size();
    
    unordered_map<int, int> mp;

    int count = 0, sum = 0;

    for (int i = 0; i < len; i++) {
      sum += A[i];

      sum = sum % K;

      if (sum % K == 0) count++;

      // if k == 5 and sum == -1 look 4
      if (sum < 0) sum += K;

      if (mp.count(sum)) count += mp[sum];

      mp[sum]++;
    }
    return count;
  }
};