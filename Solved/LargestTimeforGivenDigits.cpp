// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3445/

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
  string largestTimeFromDigits(vector<int>& A) {
    string res = "";
    sort(A.begin(), A.end());

    string hours = "";
    string mins = "";

    hours = to_string(A[0]) + to_string(A[1]);
    mins = to_string(A[2]) + to_string(A[3]);

    res = (hours.compare("23") < 0 && mins.compare("59") < 0) ? hours + ":" + mins : res;

    while (next_permutation(A.begin(), A.end())) {
      hours = to_string(A[0]) + to_string(A[1]);
      mins = to_string(A[2]) + to_string(A[3]);
      res = (hours.compare("23") < 0 && mins.compare("59") < 0) ? hours + ":" + mins : res;
    }

    return res;
  }
};