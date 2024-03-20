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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* node=list1;
        ListNode* prev=NULL;
        ListNode* next1=NULL;
        ListNode* del1=NULL;
        ListNode* del2=NULL;
        while(count!=a){
            prev=node;
            node=node->next;
            count++;
        }
        del1=node;
        while(count!=b){
            node=node->next;
      
            count++;
        }
        del2=node;
        next1=del2->next;
      
        ListNode* node2=list2;
        while(node2->next!=NULL){
            node2=node2->next;
        }
        
        del2->next=NULL;
        prev->next=list2;
        delete del1;
        node2->next=next1;
        
        return list1;
    }
};