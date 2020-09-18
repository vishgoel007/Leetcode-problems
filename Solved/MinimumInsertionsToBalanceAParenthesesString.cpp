// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


class Solution {
 public:
  int minInsertions(string s) {
    stack<char> st;
    int len = s.length(), insert = 0;
    int i = 0;
    while (i < len) {
      if (s[i] == '(') {
        st.push('(');
        i++;
        continue;
      }

      if (s[i] == ')') {
        if (!st.empty()) {
          if (i == len - 1) {
            insert++;
            i++;
          } else if (s[i + 1] == ')') {
            i += 2;
          } else if (s[i + 1] != ')') {
            insert++;
            i++;
          }
          st.pop();
        } else {
          if (i == len - 1) {
            insert += 2;
            i += 2;
          } else if (s[i + 1] == ')') {
            insert++;
            i += 2;
          } else if (s[i + 1] != ')') {
            insert += 2;
            i++;
          }
        }
      }
    }

    insert += 2 * st.size();

    return insert;
  }
};
