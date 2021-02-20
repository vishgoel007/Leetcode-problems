// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

// premium problem

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
  Node* left;
  Node* right;
  Node* parent;
};

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    unordered_set<Node*> set;
    while (p) {
      set.insert(p);
      p = p->parent;
    }
    while (q) {
      if (set.count(q)) return q;
      q = q->parent;
    }

    return nullptr;
  }
};

// alternate method nice way (similar to find intercation of two lists)
class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    Node *a = p, *b = q;
    while (a != b) {
      a = a ? a->parent : q;
      b = b ? b->parent : p;
    }

    return a;
  }
};
