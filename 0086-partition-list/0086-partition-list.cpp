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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode* less=new ListNode(-1);
        ListNode* less_head=less;
        ListNode* more=new ListNode(-1);
        ListNode* more_head=more;
        while(head!=NULL){
            if(head->val<x){
                less->next=head;
                less=less->next;
            }
            else{
                more->next=head;
                more=more->next;
            }
            head=head->next;
        }
        if(less_head->next!=NULL){
            if(more_head->next!=NULL){
                less->next=more_head->next;
                more->next=NULL;
            }
            else {
                less->next=NULL;
            }
            return less_head->next;

        }
        else{
            more->next=NULL;
            return more_head->next;
        }
    }
};