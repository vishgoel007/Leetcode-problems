// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/

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
  string getNextState(string str) {
    string t = "0";
    for (int i = 1; i < 7; i++) {
      t += str[i - 1] == str[i + 1] ? '1' : '0';
    }
    t += '0';
    return t;
  }

  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    unordered_set<string> set;

    string initialStr = "";
    for (int i = 0; i < cells.size(); i++) initialStr += to_string(cells[i]);

    int count = 0;
    bool isCycle = false;
    string tmp = initialStr;

    for (int i = 0; i < N; i++) {
      string nextState = getNextState(tmp);
      if (set.find(nextState) == set.end()) {
        set.insert(nextState);
        count++;
      } else {
        isCycle = true;
        break;
      }
      tmp = nextState;
    }

    string ans = tmp;
    if (isCycle) {
      N = N % count;
      for (int i = 0; i < N; i++) {
        string nextState = getNextState(ans);
        ans = nextState;
      }
    }

    vector<int> output;
    for (int i = 0; i < ans.length(); i++) output.push_back(ans[i] - '0');

    return output;
  }
};