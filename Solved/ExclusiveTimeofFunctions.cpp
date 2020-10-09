// https://leetcode.com/problems/exclusive-time-of-functions/

#include <iostream>
#include <istream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct LogDet {
  int id;
  string type;
  int time;
};

class Solution {
 public:
  LogDet getIdTypeAndTimestamp(string log) {
    istringstream ss(log);
    string t1, t2, t3;
    getline(ss, t1, ':');
    getline(ss, t2, ':');
    getline(ss, t3, ':');
    return {stoi(t1), t2, stoi(t3)};
  }

  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<vector<int>> vec(n, vector<int>(2, -1));
    vector<int> output(n, 0);
    stack<int> st;
    int lastTime = 0, currentTime = 0;

    for (string log : logs) {
      LogDet det = getIdTypeAndTimestamp(log);
      currentTime = det.time;
      if (det.type == "start") {
        // time spent on previous one till current one start executing
        if (st.size() > 0) output[st.top()] += currentTime - lastTime;
        st.push(det.id);
        lastTime = currentTime;
      } else {
        // time spent on current
        output[st.top()] += currentTime + 1 - lastTime;
        st.pop();
        /**
         * Important!
         * Next job will only start after this end time.
         * Hence lastTime = currentTime + 1.
         */
        lastTime = currentTime + 1;
      }
    }

    return output;
  }
};