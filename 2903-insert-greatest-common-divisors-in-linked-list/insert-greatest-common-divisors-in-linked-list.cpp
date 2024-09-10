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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* temp = head, *nextptr = head->next;
        while(nextptr!=NULL) {
            int gcd = __gcd(temp->val, nextptr->val);
            temp->next = new ListNode(gcd);
            temp->next->next = nextptr;
            temp = nextptr;
            nextptr = temp->next;
        }
        return head;
    }
};