// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyHashSet {
 public:
  int arr[1000001];
  MyHashSet() {
    memset(arr, 0, sizeof(arr));
  }

  void add(int key) {
    arr[key] = 1;
  }

  void remove(int key) {
    arr[key] = 0;
  }

  bool contains(int key) {
    return arr[key] > 0;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */