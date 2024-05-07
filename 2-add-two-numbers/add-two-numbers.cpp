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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode((l1->val + l2->val)%10);
        ListNode* curr = head;
        int carry = 0;
        if(l1->val + l2->val > 9) carry = 1;
        l1 = l1->next, l2 = l2->next;
        while((l1 != nullptr && l2 != nullptr)){
            ListNode* node = new ListNode((l1->val+l2->val+carry)%10);
            if(l1->val + l2->val + carry > 9) carry = 1;
            else carry = 0;
            l1 = l1->next, l2 = l2->next;
            curr->next = node;
            curr = node;
        }
        while(l1!=nullptr){
            ListNode* node = new ListNode((l1->val+carry)%10);
            if(l1->val + carry > 9) carry = 1;
            else carry = 0;
            curr->next = node;
            curr = node;
            l1 = l1->next;
        }
        while(l2!=nullptr){
            ListNode* node = new ListNode((l2->val+carry)%10);
            if(l2->val + carry > 9) carry = 1;
            else carry = 0;
            curr->next = node;
            curr = node;
            l2 = l2->next;
        }
        if(carry == 1) curr->next = new ListNode(1);
        return head;
    }
};