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
        while(tempA!=NULL){
            mp[tempA]++;
            tempA=tempA->next;
        }
        ListNode* tempB=headB;
        while(tempB!=NULL){
            if(mp.count(tempB)>0){
                return tempB;
            }
            tempB=tempB->next;
        }

        return NULL;
    }
};