// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3422/

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class CombinationIterator {
 public:
  int count;
  vector<string> vec;

  CombinationIterator(string characters, int combinationLength) {
    count = 0;
    vector<string> v = genrateCombinations(characters, combinationLength);
    filter(v, combinationLength);
  }

  void filter(vector<string> s, int c) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i].length() == c) vec.push_back(s[i]);
    }
    sort(vec.begin(), vec.end());
  }

  vector<string> genrateCombinations(string s, int c) {
    if (s.length() == 0) {
      return vector<string>(1, s);
    }
    vector<string> smallAns = genrateCombinations(s.substr(1), c);
    int len = smallAns.size();
    vector<string> output(2 * len);
    int it = 0, jt = len;
    for (int i = 0; i < len; i++) {
      output[it++] = smallAns[i];
      output[jt++] = s[0] + smallAns[i];
    }
    return output;
  }

  string next() {
    return vec[count++];
  }

  bool hasNext() {
    return count < vec.size();
  }
};

// using bit masking
class CombinationIterator2 {
 public:
  int count;
  vector<string> vec;

  CombinationIterator2(string characters, int combinationLength) {
    count = 0;
    genrateCombinations(characters, combinationLength);
  }

  void genrateCombinations(string s, int c) {
    int len = s.length();
    int mask = 1 << len;
    for (int i = 1; i < mask; i++) {
      int n = i, bitCount = 0;
      string str = "";
      while (n) {
        if (n & 1) str += s[bitCount];
        n >>= 1;
        bitCount++;
      }
      if (str.length() == c) {
        this->vec.push_back(str);
      }
    }
    sort(this->vec.begin(), this->vec.end());
  }

  string next() {
    return vec[this->count++];
  }

  bool hasNext() {
    return this->count < vec.size();
  }
};

// using bit masking / finding next dynamically
class CombinationIterator3 {
 public:
  int mask;
  string s;
  int cLen;
  vector<string> vec;

  CombinationIterator3(string characters, int combinationLength) {
    mask = (1 << characters.length()) - 1;
    s = characters;
    cLen = combinationLength;
  }

  string next() {
    while (mask && __builtin_popcount(mask) != cLen) mask--;
    string ans = "";

    // https://leetcode.com/problems/iterator-for-combination/discuss/789164/C++-Using-Bit-manipulation-or-Detail-Explain/656380
    for (int i = 0; i < s.length(); i++) {
      if (mask & (1 << (s.length() - i - 1))) {    // don't know what is happening here
        ans += s[i];
      }
    }

    mask--;
    return ans;
  }

  bool hasNext() {
    while (mask && __builtin_popcount(mask) != cLen) mask--;
    return !!mask;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */