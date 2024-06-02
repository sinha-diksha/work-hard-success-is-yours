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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* smallHead=sortList(head->next);
        if(head->val<=smallHead->val){
            head->next=smallHead;
            return head;
        }
        ListNode* node=smallHead;
        ListNode* prev=node;
        while(node!=NULL && node->val<head->val){
            prev=node;
            node=node->next;
        }
        prev->next=head;
        head->next=node;
        return smallHead;
    }
};