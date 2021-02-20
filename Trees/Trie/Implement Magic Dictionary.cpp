// https://leetcode.com/problems/implement-magic-dictionary/

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

class MagicDictionary {
 private:
  Trie* root;

 public:
  MagicDictionary() {
    root = new Trie();
  }

  void buildDict(vector<string> dictionary) {
    for (string& word : dictionary) {
      Trie* node = root;
      for (char c : word) {
        if (!node->next[c - 'a']) node->next[c - 'a'] = new Trie();

        node = node->next[c - 'a'];
      }
      node->isEnd = true;
    }
  }

  bool searchUtil(string& word, int misMatch, int currInd, Trie* node) {
    if (misMatch >= 2) return false;

    if (currInd == word.length()) {
      return misMatch == 1 && node->isEnd;
    }

    bool isFound = false;
    for (int i = 0; i < 26; i++) {
      if (node->next[i]) {
        if (i == word[currInd] - 'a')
          isFound |= searchUtil(word, misMatch, currInd + 1, node->next[i]);
        else
          isFound |= searchUtil(word, misMatch + 1, currInd + 1, node->next[i]);
      }
    }
    return isFound;
  }

  bool search(string searchWord) {
    return searchUtil(searchWord, 0, 0, root);
  }
};
