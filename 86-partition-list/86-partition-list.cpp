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
        if(head==NULL || head->next==NULL){
            return head;
        }
        queue<ListNode*> q;
        struct ListNode* ptr=head;
        struct ListNode* curr=NULL;
        while(ptr!=NULL){
            if(ptr->val>=x){
                q.push(ptr);
                ptr=ptr->next;
            }
            else{
                if(curr==NULL){
                    curr=ptr;
                    head=curr;
                    ptr=ptr->next;
                }
                else{
                    curr->next=ptr;
                    curr=ptr;
                    ptr=ptr->next;
                }
            }
        }
        if(curr==NULL){
            return head;
        }
        while(!q.empty()){
            curr->next=q.front();
            curr=q.front();
            q.pop();
        }
        curr->next=NULL;
        return head;
    }
};