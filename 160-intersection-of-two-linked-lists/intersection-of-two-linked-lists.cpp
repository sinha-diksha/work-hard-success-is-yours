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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode* tempA=headA;
        int n=0;
        while(tempA!=NULL){
            n++;
            tempA=tempA->next;
        }
        ListNode* tempB=headB;
        int m=0;
        while(tempB!=NULL){
            m++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(m>n){
            int diff=m-n;
            while(diff){
                tempB=tempB->next;
                diff--;
            }
        }else if(n>m){
            int diff=n-m;
            while(diff){
                tempA=tempA->next;
                diff--;
            }
        }
        while(tempA!=NULL && tempB!=NULL && tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};