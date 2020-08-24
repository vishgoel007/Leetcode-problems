// https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1375/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// using bfs
class Solution {
 public:
  vector<string> getNeighbours(string s) {
    vector<string> v;

    // Every node has 8 edges
    for (int i = 0; i < 4; i++) {
      string t = s;

      // increment a digit at one place for a node
      t[i] = (s[i] - '0' + 1) % 10 + '0';

      v.push_back(t);

      // decrement a digit at one place for a node
      t[i] = (s[i] - '0' - 1 + 10) % 10 + '0';

      v.push_back(t);
    }

    return v;
  }

  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dSet(deadends.begin(), deadends.end());
    if (dSet.find("0000") != dSet.end()) return -1;

    int level = 0;
    queue<string> q;

    // need to maintain this as repeated nodes
    // can come from get neighbours, so to avoid infinite loop
    unordered_set<string> visited;

    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        string curr = q.front();
        q.pop();
        if (curr == target) return level;
        vector<string> neighbours = getNeighbours(curr);
        for (int i = 0; i < neighbours.size(); i++) {
          if (dSet.find(neighbours[i]) == dSet.end() && visited.find(neighbours[i]) == visited.end()) {
            q.push(neighbours[i]);
            visited.insert(neighbours[i]);
          }
        }
      }
      level++;
    }
    return -1;
  }
};

/**
 * Can we apply DFS to this problem ?
 * 
 * Yes, definitely you can apply DFS here. 
 * As the whole search space is 10^4 = 10000, 
 * DFS can work here too. But why many people choose BFS instead?
 *  Because the problem here asks for the minimum number of steps
 *  to achieve the target state. Using BFS, we can report the answer
 *  as long as we reach the target state. But using DFS, we can't guarantee
 *  that the initial target state that we reach is the optimal solution. 
 * You still have to search the whole search space. 
 * 
 */