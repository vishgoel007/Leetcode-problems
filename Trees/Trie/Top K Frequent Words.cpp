// https://leetcode.com/problems/top-k-frequent-words/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Compare {
 public:
  bool operator()(pair<int, string>& a, pair<int, string>& b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  }
};

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;

    for (string& word : words) mp[word]++;

    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

    vector<string> res;
    for (auto m : mp) {
      pq.push({m.second, m.first});
    }

    while (!pq.empty() && k > 0) {
      auto p = pq.top();
      pq.pop();
      res.push_back(p.second);
      k--;
    }

    return res;
  }
};

// using trie
class Compare {
 public:
  bool operator()(pair<int, string>& a, pair<int, string>& b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  }
};

class Trie {
 public:
  int freq;
  bool isEnd;
  string word;
  vector<Trie*> next;
  Trie() : freq(0), isEnd(false), word(""), next(26, nullptr) {}
};

class Solution {
 public:
  Trie* root = new Trie();
  priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

  void insert(string& word) {
    Trie* node = root;
    for (char c : word) {
      if (!node->next[c - 'a']) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->word = word;
    node->isEnd = true;
    node->freq++;
  }

  void dfs(Trie* node) {
    if (node == nullptr) return;
    for (Trie* t : node->next) {
      if (t && t->freq) {
        pq.push({t->freq, t->word});
      }
      dfs(t);
    }
  }

  vector<string> topKFrequent(vector<string>& words, int k) {
    for (string& word : words) insert(word);

    dfs(root);

    vector<string> res;
    while (!pq.empty() && k > 0) {
      auto p = pq.top();
      pq.pop();
      res.push_back(p.second);
      k--;
    }

    return res;
  }
};

// https://leetcode.com/problems/top-k-frequent-words/discuss/431008/Summary-of-all-the-methods-you-can-imagine-of-this-problem