// https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3642/

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
  void helper(string &S, vector<string> &res, int index) {
    res.push_back(S);
    for (int i = index; i < S.size(); i++) {
      char c = S[i];
      if (c >= 'a' && c <= 'z') {
        S[i] = toupper(c);
        helper(S, res, i + 1);
        S[i] = tolower(c);
      }
    }
  }
  vector<string> letterCasePermutation(string S) {
    vector<string> res;

    for (char &c : S) c = tolower(c);

    helper(S, res, 0);
    return res;
  }
};

// using BFS
class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    int len = S.length();
    vector<string> res;

    queue<string> q;
    q.push(S);

    for (int i = 0; i < len; i++) {
      if (!isalpha(S[i])) continue;
      int size = q.size();
      while (size--) {
        string curr = q.front();
        q.pop();

        curr[i] = tolower(curr[i]);
        q.push(curr);

        curr[i] = toupper(curr[i]);
        q.push(curr);
      }
    }

    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }

    return res;
  }
};