// https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3635/

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
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// iterative
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;

    Node* temp = head;
    while (temp) {
      mp[temp] = new Node(temp->val);
      temp = temp->next;
    }

    temp = head;
    while (temp) {
      mp[temp]->next = mp[temp->next];
      mp[temp]->random = mp[temp->random];
      temp = temp->next;
    }

    return mp[head];
  }
};

// recursive
class Solution {
 public:
  unordered_map<Node*, Node*> mp;

  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    if (mp.find(head) != mp.end()) return mp[head];

    Node* newNode = new Node(head->val);

    mp[head] = newNode;

    newNode->next = copyRandomList(head->next);
    newNode->random = copyRandomList(head->random);

    return newNode;
  }
};