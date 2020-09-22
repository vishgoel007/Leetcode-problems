// https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1391/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using BFS
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int len = rooms.size();
    unordered_set<int> visited;

    queue<int> q;
    q.push(0);
    visited.insert(0);

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (int r : rooms[curr]) {
        if (visited.count(r)) continue;
        visited.insert(r);
        q.push(r);
      }
    }

    return visited.size() == len;
  }
};

// using DFS
class Solution {
 public:
  unordered_set<int> visited;
  void DFS(vector<vector<int>>& rooms, int curr) {
    if (visited.count(curr)) return;
    visited.insert(curr);
    for (int r : rooms[curr])
      DFS(rooms, r);
  }
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    DFS(rooms, 0);
    return visited.size() == rooms.size();
  }
};