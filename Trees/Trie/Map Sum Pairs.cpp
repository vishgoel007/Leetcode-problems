// https://leetcode.com/problems/map-sum-pairs/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using trie + dfs
class Trie {
 public:
  int val;
  bool isEnd;
  vector<Trie*> next;
  Trie() : val(0), isEnd(false), next(26, nullptr) {}
};

class MapSum {
 public:
  Trie* root;
  MapSum() {
    root = new Trie();
  }

  void insert(string key, int val) {
    Trie* node = root;

    for (char c : key) {
      if (!node->next[c - 'a']) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->val = val;
    node->isEnd = true;
  }

  int restSum(Trie* node) {
    int sum = node->val;
    for (int i = 0; i < 26; i++) {
      if (node->next[i]) {
        sum += restSum(node->next[i]);
      }
    }
    return sum;
  }

  int sum(string prefix) {
    Trie* node = root;
    for (char c : prefix) {
      if (!node->next[c - 'a']) return 0;
      node = node->next[c - 'a'];
    }
    return restSum(node);
  }
};

// using extra variables in trie
class Trie {
 public:
  int sum;
  int val;
  bool isEnd;
  vector<Trie*> next;
  Trie() : sum(0), val(0), isEnd(false), next(26, nullptr) {}
};

class MapSum {
 public:
  Trie* root;
  MapSum() {
    root = new Trie();
  }

  int getPrevValue(string& str) {
    Trie* node = root;
    for (char c : str) {
      if (!node->next[c - 'a']) return 0;
      node = node->next[c - 'a'];
    }
    if (node->isEnd) return node->val;
    return 0;
  }

  void insert(string key, int val) {
    int prevVal = getPrevValue(key);

    int updatedVal = val - prevVal;

    Trie* node = root;
    for (char c : key) {
      if (!node->next[c - 'a']) {
        node->next[c - 'a'] = new Trie();
      }
      node->sum += updatedVal;
      node = node->next[c - 'a'];
    }
    node->sum += updatedVal;
    node->val = val;
    node->isEnd = true;
  }

  int sum(string prefix) {
    Trie* node = root;
    int res = 0;
    for (char c : prefix) {
      if (!node->next[c - 'a']) return 0;
      node = node->next[c - 'a'];
      res = node->sum;
    }
    return res;
  }
};