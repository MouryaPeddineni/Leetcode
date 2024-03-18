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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        
        return mergeLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeLists(std::vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        
        int mid = left + (right - left) / 2;
        ListNode* l = mergeLists(lists, left, mid);
        ListNode* r = mergeLists(lists, mid + 1, right);
        
        return merge(l, r);
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (l && r) {
            if (l->val < r->val) {
                tail->next = l;
                l = l->next;
            } else {
                tail->next = r;
                r = r->next;
            }
            tail = tail->next;
        }
        
        tail->next = l ? l : r;
        
        return dummy->next;
    }
};