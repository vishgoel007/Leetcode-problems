// https://leetcode.com/problems/diagonal-traverse-ii/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using BFS
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> res;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto p = q.front();
        q.pop();

        int r = p.first, c = p.second;
        res.push_back(nums[r][c]);

        // The node in the first column can generate two "neighbor nodes"
        if (r < nums.size() - 1 && c == 0) {
          q.push({r + 1, c});
        }

        // otherwise a node can generate only one "neighbor node"
        if (c < nums[r].size() - 1) {
          q.push({r, c + 1});
        }
      }
    }

    return res;
  }
};

// using map
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    map<int, vector<int>> mp;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        mp[i + j].push_back(nums[i][j]);
      }
    }

    for (auto m : mp) {
      for (int i = m.second.size() - 1; i >= 0; i--) {
        res.push_back(m.second[i]);
      }
    }
    return res;
  }
};

// using unordered map
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    unordered_map<int, vector<int>> mp;
    vector<int> res;
    int maxKey = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        mp[i + j].push_back(nums[i][j]);
        maxKey = max(maxKey, i + j);
      }
    }

    for (int key = 0; key < maxKey; key++) {
      for (auto t = mp[key].rbegin(); t != mp[key].rend(); t++) {
        res.push_back(*t);
      }
    }
    return res;
  }
};
