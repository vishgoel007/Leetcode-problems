// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
 private:
  vector<TrieNode*> links;
  bool isEnd;

 public:
  TrieNode() : isEnd(false), links(26, nullptr) {}

  bool isContainKey(char c) {
    return links[c - 'a'] != nullptr;
  }

  TrieNode* get(char c) {
    return links[c - 'a'];
  }

  void put(char c, TrieNode* node) {
    links[c - 'a'] = node;
  }

  void setEnd() {
    isEnd = true;
  }

  bool isWordEnd() {
    return isEnd == true;
  }
};

class Trie {
 public:
  TrieNode* root;
  Trie() {
    root = new TrieNode;
  }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->isContainKey(c)) {
        node->put(c, new TrieNode);
      }
      node = node->get(c);
    }
    node->setEnd();
  }

  TrieNode* searchPrefix(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->isContainKey(c)) return nullptr;
      node = node->get(c);
    }
    return node;
  }

  bool search(string word) {
    TrieNode* node = searchPrefix(word);
    return node != nullptr && node->isWordEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* node = searchPrefix(prefix);
    return node != nullptr;
  }
};

// using map
class Trie {
 private:
  unordered_map<char, Trie*> links;
  bool isEnd = false;

 public:
  void insert(string word) {
    Trie* node = this;
    for (char c : word) {
      if (!node->links.count(c)) {
        node->links[c] = new Trie;
      }
      node = node->links[c];
    }
    node->isEnd = true;
  }

  Trie* searchPrefix(string word) {
    Trie* node = this;
    for (char c : word) {
      if (!node->links.count(c)) return nullptr;
      node = node->links[c];
    }
    return node;
  }

  bool search(string word) {
    Trie* node = searchPrefix(word);
    return node != nullptr && node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = searchPrefix(prefix);
    return node != nullptr;
  }
};