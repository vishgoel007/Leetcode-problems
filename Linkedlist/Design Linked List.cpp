// https://leetcode.com/problems/design-linked-list/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using single linked list
struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr){};
  Node(int val) : val(val), next(nullptr){};
  Node(int val, Node* next) : val(val), next(next){};
};

class MyLinkedList {
 public:
  Node* head;
  int length;
  MyLinkedList() {
    head = new Node();
    length = 0;
  }

  int get(int index) {
    if (index >= length) return -1;
    Node* curr = head;
    while (curr && index >= 0) {
      curr = curr->next;
      index--;
    }
    return curr->val;
  }

  void addAtHead(int val) {
    Node* newNode = new Node(val);
    Node* headNext = head->next;
    head->next = newNode;
    newNode->next = headNext;
    length++;
  }

  void addAtTail(int val) {
    Node* curr = head;
    while (curr->next) curr = curr->next;

    curr->next = new Node(val);
    length++;
  }

  void addAtIndex(int index, int val) {
    if (index > length) return;
    if (index == length || index == 0) {
      index == 0 ? addAtHead(val) : addAtTail(val);
      return;
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;

    Node* newNode = new Node(val);
    Node* tmp = curr->next;
    curr->next = newNode;
    newNode->next = tmp;
    length++;
  }

  void deleteAtIndex(int index) {
    if (index >= length) return;

    Node* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;

    Node* tmp = curr->next;
    curr->next = tmp->next;

    length--;

    delete tmp;
  }
};

// using double linked list
struct DLLNode {
  int val;
  DLLNode* next;
  DLLNode* prev;

  DLLNode() : val(0), prev(nullptr), next(nullptr){};
  DLLNode(int val) : val(val), prev(nullptr), next(nullptr){};
  DLLNode(int val, DLLNode* prev, DLLNode* next) : val(val), prev(prev), next(next){};
};

class MyLinkedList {
 public:
  DLLNode *head, *tail;
  int length;
  MyLinkedList() {
    head = new DLLNode();
    tail = new DLLNode();

    head->next = tail;
    tail->prev = head;

    length = 0;
  }

  void print() {
    DLLNode* tmp = head;
    while (tmp) {
      cout << tmp->val << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }

  int get(int index) {
    if (index >= length) return -1;
    DLLNode* curr = head;

    for (int i = 0; i <= index; i++) curr = curr->next;

    return curr->val;
  }

  void addAtHead(int val) {
    DLLNode* newNode = new DLLNode(val);
    DLLNode* headNext = head->next;
    head->next = newNode;
    newNode->next = headNext;

    newNode->prev = head;
    headNext->prev = newNode;
    length++;
  }

  void addAtTail(int val) {
    DLLNode* newNode = new DLLNode(val);
    DLLNode* tailPrev = tail->prev;

    tailPrev->next = newNode;
    newNode->prev = tailPrev;

    newNode->next = tail;
    tail->prev = newNode;

    length++;
  }

  void addAtIndex(int index, int val) {
    if (index > length) return;

    DLLNode* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;

    DLLNode* newNode = new DLLNode(val);
    DLLNode* tmp = curr->next;
    curr->next = newNode;
    newNode->next = tmp;

    tmp->prev = newNode;
    newNode->prev = curr;

    length++;
  }

  void deleteAtIndex(int index) {
    if (index >= length) return;

    DLLNode* curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;

    DLLNode* tmp = curr->next;

    curr->next = tmp->next;
    curr->next->prev = curr;

    length--;

    delete tmp;
  }
};