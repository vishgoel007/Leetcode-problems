// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// using BFS
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      Node* prevRight = NULL;
      while (size--) {
        Node* curr = q.front();
        q.pop();
        if (curr->left) {
          if (prevRight) prevRight->next = curr->left;
          curr->left->next = curr->right;
          q.push(curr->left);
        }
        if (curr->right) {
          prevRight = curr->right;
          curr->right->next = NULL;
          q.push(curr->right);
        }
      }
    }

    return root;
  }
};
