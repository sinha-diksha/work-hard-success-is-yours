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
    ListNode* helper(ListNode* head){
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* tail=head;
        while(tail->next!=NULL){
            prev=tail;
            tail=tail->next;
        }
        ListNode* newNode=head->next;
        prev->next=NULL;
        ListNode* smallAns=helper(newNode);
        head->next=tail;
        tail->next=smallAns;
        return head;
    }
    void reorderList(ListNode* head) {
        helper(head);
    }
};