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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* smallHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallHead;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        int carry=0;
        ListNode* prev=head;
        ListNode* nn=head;
        while(head!=NULL){
   
            int a=head->val*2;
            int b=a/10;
            int val1=a%10;
            head->val=val1;
            if(carry!=0){
                head->val+=carry;
            }
            carry=b;
            prev=head;
            head=head->next;
        }
        if(carry!=0){
            ListNode* newNode= new ListNode(carry);
            prev->next=newNode;
        }
        head=reverse(nn);
        return head;
        

    }
};