/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this->val = val; }
 *     ListNode(int val, ListNode next) { this->val = val; this->next = next; }
 * }
 */
class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head,*next,*prev;
        prev = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};