/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* temp = head;
    int *arr[100];
    int i=0,mid;
    while(temp!=NULL){
        arr[i] = temp;
        temp = temp->next;
        i++;
    }
    mid = i/2;
    return arr[mid];
}