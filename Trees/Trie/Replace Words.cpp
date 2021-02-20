// https://leetcode.com/problems/replace-words/

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

class Trie {
 public:
  vector<Trie*> next;
  bool isEnd;
  Trie() : isEnd(false), next(26, nullptr) {}
};

class Solution {
 public:
  Trie* root = new Trie();

  void addWords(vector<string>& dictionary) {
    for (string word : dictionary) {
      Trie* node = root;
      for (char c : word) {
        if (!node->next[c - 'a']) {
          node->next[c - 'a'] = new Trie();
        }
        node = node->next[c - 'a'];
      }
      node->isEnd = true;
    }
  }

  string searchPrefix(string& word) {
    Trie* node = root;
    string res = "";
    for (char c : word) {
      if (!node->next[c - 'a']) return word;
      res += c;
      node = node->next[c - 'a'];
      if (node->isEnd) return res;
    }
    return res;
  }

  string replaceWords(vector<string>& dictionary, string sentence) {
    addWords(dictionary);

    istringstream ss(sentence);
    string res = "";

    for (string s; ss >> s;) {
      res += searchPrefix(s);
      res += " ";
    }
    
    return res.substr(0, res.length() - 1);
  }
};