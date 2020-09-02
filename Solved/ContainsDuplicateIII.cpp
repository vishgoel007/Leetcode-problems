// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3446/

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int len = nums.size();
    set<long> s;
    set<long>::iterator it;
    for (int i = 0; i < len; i++) {
      if (i > k) s.erase(nums[i - k - 1]);
      it = s.lower_bound(nums[i] - t);
      if (it != s.end() && t >= *it - nums[i]) return true;
      s.insert(nums[i]);
    }
    return false;
  }
};

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int len = nums.size();
    vector<pair<long, long>> vec(len);
    for (int i = 0; i < len; i++) vec[i] = make_pair(nums[i], i);

    sort(vec.begin(), vec.end());

    for (int i = 0; i < len; i++) {
      int j = i + 1;
      while (j < len && abs((long)vec[j].first - vec[i].first) <= t) {
        if (abs(vec[i].second - vec[j].second) <= k) return true;
        j++;
      }
    }

    return false;
  }
};

// using bucket
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int len = nums.size();

    if (len == 0 || k < 0 || t < 0) return false;

    // Buckets ensure absolute difference between two numbers is at most t
    unordered_map<long, long> buckets;

    for (int i = 0; i < len; i++) {
      int bucket = nums[i] / ((long)t + 1);

      // negative belongs to negative key bucket
      if (nums[i] < 0) bucket--;

      if (buckets.find(bucket) != buckets.end())
        return true;
      else {
        buckets[bucket] = nums[i];

        // check immediate neighbouring buckets also
        if (buckets.find(bucket - 1) != buckets.end() && (long)(nums[i] - buckets[bucket - 1]) <= t) return true;
        if (buckets.find(bucket + 1) != buckets.end() && (long)(buckets[bucket + 1] - nums[i]) <= t) return true;

        if (buckets.size() > k) {
          int key = nums[i - k] / ((long)t + 1);
          if (nums[i - k] < 0) key--;
          buckets.erase(key);
        }
      }
    }

    return false;
  }
};