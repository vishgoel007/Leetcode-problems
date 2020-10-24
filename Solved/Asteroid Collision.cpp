// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3502/#include <iostream>

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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    int len = asteroids.size();
    stack<int> st;
    for (int a : asteroids) {
      if (st.empty() || a > 0 || st.top() < 0) {
        st.push(a);
        continue;
      }

      while (true) {
        int prev = st.top();
        if (prev < 0) {
          st.push(a);
          break;
        }

        if (prev == -a) {
          st.pop();
          break;
        }

        if (prev > -a) break;

        st.pop();
        if (st.empty()) {
          st.push(a);
          break;
        }
      }
    }

    vector<int> res(st.size());
    for (int i = res.size() - 1; i >= 0; i--) {
      res[i] = st.top();
      st.pop();
    }
    return res;
  }
};