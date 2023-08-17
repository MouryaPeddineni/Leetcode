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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp = head;
        ListNode* nxt = temp->next;
        while(temp!=NULL && nxt!=NULL){
            temp->val = nxt->val^temp->val;
            nxt->val = nxt->val^temp->val;
            temp->val = nxt->val^temp->val;
            temp = nxt->next;
            if(temp!=NULL){
                nxt=temp->next;
            }
        }
        return head;
    }
};