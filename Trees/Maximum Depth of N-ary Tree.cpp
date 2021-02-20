// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// using dfs
class Solution {
 public:
  int depth(Node* root) {
    if (!root) return 0;

    int ans = 0;
    for (auto c : root->children) {
      ans = max(ans, depth(c));
    }
    return ans + 1;
  }
  int maxDepth(Node* root) {
    return depth(root);
  }
};

// using bfs
class Solution {
 public:
  int maxDepth(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
      level++;
      int size = q.size();
      for (int s = 0; s < size; s++) {
        Node* curr = q.front();
        q.pop();
        for (auto n : curr->children) q.push(n);
      }
    }
    return level;
  }
};