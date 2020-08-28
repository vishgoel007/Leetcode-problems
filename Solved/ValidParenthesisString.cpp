// https://leetcode.com/problems/valid-parenthesis-string/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkValidString(string s) {
    int len = s.length();
    stack<int> left, ash;

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') left.push(i);
      if (s[i] == '*') ash.push(i);
      if (s[i] == ')') {
        if (left.empty()) {
          if (ash.empty()) return false;
          ash.pop();
        } else {
          left.pop();
        }
      }
    }

    while (!ash.empty() && !left.empty()) {
      if (ash.top() < left.top())
        return false;
      else if (ash.top() > left.top())
        ash.pop(), left.pop();
    }

    return left.size() == 0;
  }
};