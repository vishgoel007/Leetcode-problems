// https://leetcode.com/problems/lru-cache/

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class LRUCache {
 public:
  int capacity;
  unordered_map<int, list<int>::iterator> mp;
  unordered_map<int, int> vals;
  list<int> recent;

  LRUCache(int capacity) {
    this->capacity = capacity;
  }

  int get(int key) {
    if (mp.find(key) == mp.end()) return -1;

    recent.erase(mp[key]);
    recent.push_front(key);
    mp[key] = recent.begin();
    return vals[key];
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
      recent.erase(mp[key]);
    } else if (recent.size() >= capacity) {
      int keyToRemove = recent.back();
      mp.erase(keyToRemove);
      vals.erase(keyToRemove);
      recent.pop_back();
    }
    vals[key] = value;
    recent.push_front(key);
    mp[key] = recent.begin();
  }
};

// Using DLL
class DLL {
 public:
  DLL *next;
  DLL *prev;
  int key;
  int val;
  DLL() : val(-1), key(-1), next(NULL), prev(NULL) {}
  DLL(int key, int val) : val(val), key(key), next(NULL), prev(NULL) {}
};

class LRUCache {
 public:
  unordered_map<int, DLL *> mp;
  DLL *head, *tail;
  int capacity;

  LRUCache(int capacity) {
    this->capacity = capacity;
    head = new DLL();
    tail = new DLL();

    head->next = tail;
    tail->prev = head;
  }

  void deleteNode(DLL *toDelete) {
    DLL *toDeletePrev = toDelete->prev;
    DLL *toDeleteNext = toDelete->next;
    toDeletePrev->next = toDeleteNext;
    toDeleteNext->prev = toDeletePrev;

    mp.erase(toDelete->key);
  }

  void deleteNodeFromLast() {
    DLL *toDelete = tail->prev;
    toDelete->prev->next = tail;
    tail->prev = toDelete->prev;

    mp.erase(toDelete->key);
  }

  void addAtFront(int key, int value) {
    DLL *newNode = new DLL(key, value);

    DLL *headNext = head->next;
    head->next = newNode;
    newNode->next = headNext;
    headNext->prev = newNode;
    newNode->prev = head;

    mp[key] = newNode;
  }

  int get(int key) {
    if (mp.find(key) == mp.end()) return -1;
    DLL *nodeToRemove = mp[key];
    deleteNode(nodeToRemove);
    addAtFront(nodeToRemove->key, nodeToRemove->val);
    return nodeToRemove->val;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end())
      deleteNode(mp[key]);
    else if (capacity <= 0)
      deleteNodeFromLast();
    else
      capacity--;
      
    addAtFront(key, value);
  }
};