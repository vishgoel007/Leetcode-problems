// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class MinStack {
 public:
  stack<int> st;
  stack<int> aux;

  MinStack() {}

  void push(int x) {
    aux.empty() ? aux.push(x) : aux.push(min(x, aux.top()));
    st.push(x);
  }

  void pop() {
    st.pop(), aux.pop();
  }

  int top() {
    return st.top();
  }

  int getMin() {
    return aux.top();
  }
};

