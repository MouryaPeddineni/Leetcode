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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            sz++;
            temp = temp->next;
        }
        if(sz==1 && n==1) return nullptr;
        int st = 0;
        ListNode* tmp = head;
        while(sz-st-1!=n && tmp!=nullptr){
            st++;
            tmp = tmp->next;
        }
        if(n==sz){
            head = head->next;
        }
        else if(n==1){
            tmp->next = nullptr;
        }
        else{
            tmp->next = tmp->next->next;
        }
        return head;
    }
};