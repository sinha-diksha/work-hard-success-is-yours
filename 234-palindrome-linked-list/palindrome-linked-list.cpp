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

    ListNode* smallReverse=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallReverse;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=NULL;
    while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=NULL && fast->next!=NULL ){
        prev=slow;
        slow=slow->next;
    }
    if(prev==NULL){
        if(head->next==NULL){
            return true;
        }
        if(head->val == head->next->val){
            return true;
        }else{
            return false;
        }
    }
    ListNode* root2=reverse(slow);
    if(prev!=NULL){
        prev->next=root2;
    }
    ListNode* root1=root2;
    while(head!=root1){
        if(head->val!=root2->val){
            return false;
        }
        head=head->next;
        root2=root2->next;
    }
    return true;
    // ListNode* root1;
    // if(prev==NULL){
    //     root1=NULL;
    // }else{
    //     prev->next=NULL;
    //     root1=head;
    // }
    // while(root1!=NULL && root2!=NULL){
    //     if(root1->data !=root2->data){
    //         return false;
    //     }
    // }
    // return true;
    

}

};