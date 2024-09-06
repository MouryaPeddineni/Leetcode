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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        set<int> st;
        for(int i:nums) st.insert(i);
        ListNode* temp = head;
        while(temp!=NULL) {
            if(st.find(temp->val)!=st.end()) temp = temp->next;
            else break;
        }
        ListNode* headptr = temp, *nextptr = temp->next;
        while(nextptr!=NULL) {
            if(st.find(nextptr->val)==st.end()) {
                temp->next = nextptr;
                temp = nextptr;
            }
            nextptr = nextptr->next;
        }
        ListNode* trav = head;
        while(trav->next!=NULL) trav=trav->next;
        if(st.find(trav->val)!=st.end()) temp->next = NULL;
        return headptr;
    }
};