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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        
        ListNode* temp=head,*dup=head;
        while(dup->next!=NULL){
            dup=dup->next;
            if(dup->val!=temp->val){
                temp=temp->next;
                temp->val=dup->val;
            }
        }
        temp->next=NULL;
        return head;
    }
};