// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3415/

#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using DFS
class Solution {
 public:
  map<int, map<int, multiset<int>>> mp;
  void traversalDfs(TreeNode *root, int x, int y) {
    if (!root) return;
    mp[x][y].insert(root->val);
    traversalDfs(root->left, x - 1, y + 1);
    traversalDfs(root->right, x + 1, y + 1);
  }
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> output;
    if (!root) return output;

    traversalDfs(root, 0, 0);

    map<int, map<int, multiset<int>>>::iterator it;
    map<int, multiset<int>>::iterator ptr;

    for (it = mp.begin(); it != mp.end(); it++) {
      vector<int> v;
      for (ptr = it->second.begin(); ptr != it->second.end(); ptr++) {
        v.insert(v.end(), ptr->second.begin(), ptr->second.end());
      }
      output.push_back(v);
    }
    return output;
  }
};

// using BFS
class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> output;
    if (!root) return output;
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        pair<TreeNode *, pair<int, int>> p = q.front();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        mp[x][y].insert(p.first->val);
        if (p.first->left) {
          q.push(make_pair(p.first->left, make_pair(x - 1, y + 1)));
        }
        if (p.first->right) {
          q.push(make_pair(p.first->right, make_pair(x + 1, y + 1)));
        }
      }
    }
    map<int, map<int, multiset<int>>>::iterator it;
    map<int, multiset<int>>::iterator ptr;

    for (it = mp.begin(); it != mp.end(); it++) {
      vector<int> v;
      for (ptr = it->second.begin(); ptr != it->second.end(); ptr++) {
        v.insert(v.end(), ptr->second.begin(), ptr->second.end());
      }
      output.push_back(v);
    }
    return output;
  }
};