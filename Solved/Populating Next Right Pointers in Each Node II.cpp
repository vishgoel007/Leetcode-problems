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

// using BFS (mine) (with extra space)
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      Node* prev = NULL;
      while (size--) {
        Node* curr = q.front();
        q.pop();
        if (curr->left && curr->right) {
          if (prev) prev->next = curr->left;
          curr->left->next = curr->right;
          curr->right->next = NULL;
          prev = curr->right;
          q.push(curr->left);
          q.push(curr->right);
        } else if (curr->left) {
          if (prev) prev->next = curr->left;
          curr->left->next = NULL;
          prev = curr->left;
          q.push(curr->left);

        } else if (curr->right) {
          if (prev) prev->next = curr->right;
          curr->right->next = NULL;
          prev = curr->right;
          q.push(curr->right);
        }
      }
    }

    return root;
  }
};

// using BFS (with extra space) (above improvised)
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        Node* curr = q.front();
        q.pop();
        if (i < size - 1) {
          curr->next = q.front();
        }

        if (curr->left) {
          q.push(curr->left);
        }
        if (curr->right) {
          q.push(curr->right);
        }
      }
    }

    return root;
  }
};

// BFS O(1) space
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    Node* head = nullptr;    // node to traverse next layer in the lower level
    Node* prev = nullptr;    // previous node in the lower level
    Node* curr = root;       // current node in the upper level

    while (curr) {
      while (curr) {
        if (curr->left) {
          if (prev) {
            prev->next = curr->left;
          } else {
            head = curr->left;
          }
          prev = curr->left;
        }

        if (curr->right) {
          if (prev) {
            prev->next = curr->right;
          } else {
            head = curr->right;
          }
          prev = curr->right;
        }

        curr = curr->next;
      }
      curr = head;
      head = nullptr;
      prev = nullptr;
    }

    return root;
  }
};
