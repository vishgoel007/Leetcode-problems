// https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1392/

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
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// using DFS
class Solution {
 public:
  // track for which nodes new code is created
  unordered_map<Node*, Node*> visited;

  // params currnode and its copy
  void DFS(Node* currNode, Node* copy) {
    visited[currNode] = copy;
    for (auto n : currNode->neighbors) {
      if (visited.find(n) == visited.end()) {
        Node* newNode = new Node(n->val);
        copy->neighbors.push_back(newNode);
        DFS(n, newNode);
      } else {
        copy->neighbors.push_back(visited[n]);
      }
    }
  }
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    Node* newStartNode = new Node(node->val);
    visited[node] = newStartNode;
    for (auto n : node->neighbors) {
      // if node is not created
      if (visited.find(n) == visited.end()) {
        // make new node for curr iterating node
        Node* newNode = new Node(n->val);

        newStartNode->neighbors.push_back(newNode);

        // call DFS with curr node and new node
        DFS(n, newNode);
      } else {
        // we already made newnode use that node
        newStartNode->neighbors.push_back(visited[n]);
      }
    }
    return newStartNode;
  }
};

// using BFS
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;

    queue<Node*> q;
    unordered_map<Node*, Node*> visited;

    Node* newStartNode = new Node(node->val);
    visited[node] = newStartNode;
    q.push(node);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
      for (auto n : curr->neighbors) {
        // if new node is not created
        if (visited.find(n) == visited.end()) {
          visited[n] = new Node(n->val);
          q.push(n);
        }
        // append newly created node in current neighbours
        visited[curr]->neighbors.push_back(visited[n]);
      }
    }

    return newStartNode;
  }
};