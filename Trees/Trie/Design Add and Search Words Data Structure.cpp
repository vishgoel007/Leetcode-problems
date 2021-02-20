// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <iostream>
#include <map>
#include <queue>
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

class WordDictionary {
 public:
  Trie* root;
  WordDictionary() {
    root = new Trie();
  }

  void addWord(string word) {
    Trie* node = root;
    for (char c : word) {
      if (!node->next[c - 'a']) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->isEnd = true;
  }

  bool searchPrefix(string word, Trie* node) {
    for (int i = 0; i < word.length() && node; i++) {
      char c = word[i];
      if (c != '.') {
        if (!node->next[c - 'a']) return false;
        node = node->next[c - 'a'];
      } else {
        int j = 0;
        bool found = false;
        while (j < 26) {
          if (node->next[j]) {
            found |= searchPrefix(word.substr(i + 1), node->next[j]);
            if (found) return true;
          }
          j++;
        }
        if (j == 26) return false;
      }
    }

    return node != nullptr && node->isEnd;
  }

  bool search(string word) {
    return searchPrefix(word, root);
  };
};