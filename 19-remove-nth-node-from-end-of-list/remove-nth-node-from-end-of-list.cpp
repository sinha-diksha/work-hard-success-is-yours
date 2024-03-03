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
    int length(ListNode* head){
        ListNode* node=head;
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=length(head);
        if(cnt==n){
            ListNode* a=head;
            ListNode* ans=head->next;
            head->next=NULL;
            delete head;
            return ans;
        }
        int k=cnt-n;
        ListNode* prev=NULL;
        ListNode* next1=NULL;
        ListNode* node=head;
        while(k--){
            prev=node;
            node=node->next;
            next1=node->next;
        }
        prev->next=next1;
        node->next=NULL;
        delete node;
        return head;
    }
};