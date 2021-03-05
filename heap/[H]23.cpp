// 23. Merge k Sorted Lists - Hard
// https://leetcode.com/problems/merge-k-sorted-lists/

/* Analysis:
- In order to merge lists, we must choose min element from every list each round. For that purpose, we can maintain a min heap to choose with complexity O(log(k)).
- We will have k pointers to k lists' heads. Each time we choose a new node "toh", we point the resulting iterator to "toh", and move the iterator of "tohH 
to the next node in that list.
- Time complexity: O(k * n * log(k)).
- Space complexity: O(k).
*/

class Solution {
public:
  typedef pair<int, ListNode*> pil;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int k = lists.size();
      priority_queue<pil, vector<pil>, greater<pil>> heap;
      for (int i = 0; i < k; ++i) {
        ListNode* it = lists[i];
        if (it != nullptr) {
            heap.push({it->val, it});   
        }
      }
      
      ListNode* head = new ListNode();
      ListNode* it = head;
      while (!heap.empty()) {
        pil toh = heap.top();
        heap.pop();
        it->next = toh.second;
        it = it->next;
        
        auto newIt = toh.second->next;
        if (newIt != nullptr) {
          heap.push({newIt->val, newIt}); 
        }
      }
      return head->next;
    }
};
