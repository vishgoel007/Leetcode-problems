// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3451/

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

class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    vector<string> words;
    unordered_map<string, char> wordMap;
    unordered_map<char, string> patMap;

    istringstream iss(str);
    for (string s; iss >> s;) words.push_back(s);

    if (words.size() != pattern.length()) return false;

    for (int i = 0; i < words.size(); i++) {
      if (wordMap[words[i]] == 0 && patMap[pattern[i]] == "") {
        patMap[pattern[i]] = words[i];
        wordMap[words[i]] = pattern[i];
      } else if (wordMap[words[i]] != pattern[i] && patMap[pattern[i]] != words[i])
        return false;
    }
    return true;
  }
};