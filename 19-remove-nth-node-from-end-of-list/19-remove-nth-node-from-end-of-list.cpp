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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *c=head;
        int count=0;
        while(c!=NULL){
            count++;
            c=c->next;
        }
        struct ListNode *ptr=head;
        struct ListNode *prev=ptr;
        int i=0;
        while(i!=count-n){
            prev=ptr;
            ptr=ptr->next;
            i++;
        }
        if(count==n){
            head=head->next;
            delete(ptr);
            return head;
        }
        else{
            prev->next=ptr->next;
            delete(ptr);
            return head;
        }
    }
};