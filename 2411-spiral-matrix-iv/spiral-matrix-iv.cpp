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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int starti=0, endi=m-1, startj=0, endj=n-1;
        ListNode* temp = head;
        while(head!=NULL && starti<=endi && startj<=endj) {
            for(int j=startj; j<=endj && temp!=NULL; j++) {
                ans[starti][j] = temp->val;
                temp = temp->next;
            }
            starti++;
            for(int i=starti; i<=endi && temp!=NULL; i++) {
                ans[i][endj] = temp->val;
                temp = temp->next;
            }
            endj--;
            for(int j=endj; j>=startj && temp!=NULL; j--) {
                ans[endi][j] = temp->val;
                temp = temp->next;
            }
            endi--;
            for(int i=endi; i>=starti && temp!=NULL; i--) {
                ans[i][startj] = temp->val;
                temp = temp->next;
            }
            startj++;
        }
        return ans;
    }
};