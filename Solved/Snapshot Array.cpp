// https://leetcode.com/problems/snapshot-array/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class SnapshotArray {
 public:
  unordered_map<int, map<int, int>> snaps;
  int snapCount = 0;
  SnapshotArray(int length) {
  }

  void set(int index, int val) {
    snaps[index][snapCount] = val;
  }

  int snap() {
    snapCount++;
    return snapCount - 1;
  }

  int get(int index, int snap_id) {
    if (!snaps.count(index)) return 0;

    // return iterator immediate to next snap_id
    auto it = snaps[index].upper_bound(snap_id);
    return it == snaps[index].begin() ? 0 : (it--, it->second);
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */