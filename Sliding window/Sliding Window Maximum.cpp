// https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3546/

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

// using multiset
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();

    multiset<int> mset;
    vector<int> res;

    for (int i = 0; i < len; i++) {
      mset.insert(nums[i]);
      if (i >= k) mset.erase(mset.find(nums[i - k]));
      if (i >= k - 1) res.push_back(*mset.rbegin());
    }
    return res;
  }
};

// using priority queue
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();

    priority_queue<pair<int, int>> pq;
    vector<int> res;

    for (int i = 0; i < len; i++) {
      pq.push({nums[i], i});
      while (!pq.empty() && pq.top().second <= i - k) pq.pop();

      if (i >= k - 1) res.push_back(pq.top().first);
    }
    return res;
  }
};

// using deque O(N) (monotonic queue problem)
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();

    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < len; i++) {
      if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
      while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
  }
};