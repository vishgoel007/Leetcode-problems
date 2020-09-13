// https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Using merge sort merger
 * Time complexity O(N*K*log(k))
 * Space complexity O(K)
 */
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* l = NULL;
    if (l1->val > l2->val) {
      l = l2;
      l->next = mergeTwoLists(l1, l2->next);
    } else {
      l = l1;
      l->next = mergeTwoLists(l1->next, l2);
    }
    return l;
  }
  ListNode* merger(vector<ListNode*>& lists, int low, int high) {
    if (low >= high) return lists[low];
    int mid = low + (high - low) / 2;
    ListNode* L1 = merger(lists, low, mid);
    ListNode* L2 = merger(lists, mid + 1, high);
    return mergeTwoLists(L1, L2);
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size();
    if (len == 0) return NULL;
    if (len == 1) return lists[0];
    return merger(lists, 0, len - 1);
  }
};

/**
 * Using priority queue
 * Time complexity O(N*K*log(k))
 * Space complexity O(K)
 */
class Compare {
 public:
  bool operator()(ListNode* a, ListNode* b) {
    return a->val > b->val;
  }
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    ListNode* temp = new ListNode(-1);
    ListNode* head = temp;

    for (int i = 0; i < lists.size(); i++)
      if (lists[i]) pq.push(lists[i]);

    while (!pq.empty()) {
      ListNode* node = pq.top();
      pq.pop();
      temp->next = node;
      temp = temp->next;
      node = node->next;
      if (node) pq.push(node);
    }
    return head->next;
  }
};