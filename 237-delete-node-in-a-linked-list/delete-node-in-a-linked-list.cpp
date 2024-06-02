/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next1=node->next;
        ListNode* prev=node;
        while(next1!=NULL){
            
            node->val=next1->val;
            prev=node;
            node=next1;
            
            next1=node->next;
        }
        prev->next=NULL;
    }
};