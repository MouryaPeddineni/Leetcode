/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
        int a = temp->val;
        struct ListNode* prev = temp;
        struct ListNode* curr = temp->next;
        while(curr!=NULL){
            if(curr->val==a){
                prev->next=curr->next;
            }
            // prev=prev->next;
            curr=curr->next;
        }
        temp=temp->next;
    }
    return head;
}