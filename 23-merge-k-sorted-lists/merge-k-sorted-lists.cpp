/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareNodes> minHeap;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        for (ListNode* node : lists) {
            if (node != nullptr)
                minHeap.push(node);
        }
        
        while (!minHeap.empty()) {
            tail->next = minHeap.top();
            minHeap.pop();
            tail = tail->next;
            
            if (tail->next != nullptr)
                minHeap.push(tail->next);
        }
        
        return dummy->next;
    }
};