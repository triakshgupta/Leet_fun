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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *ptr=l1;
        struct ListNode *ptr1=l2;
        int c=0;
        ListNode *pre;
        while(ptr!=NULL && ptr1!=NULL){
            ptr->val+=ptr1->val+c;
            ptr1->val=ptr->val;
            if(ptr->val>9){
                ptr->val=ptr->val%10;
                ptr1->val=ptr->val;
                c=1;
            }
            else{
                c=0;
            }
            pre=ptr;
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        ListNode* prev;
        if(ptr!=NULL){
            while(c!=0 && ptr!=NULL){
                if(ptr->val+c>9){
                    ptr->val=(ptr->val+c)%10;
                    c=1;
                    prev=ptr;
                    ptr=ptr->next;
                }
                else{
                    ptr->val=ptr->val+c;
                    c=0;
                }
            }
            if(c!=0){
                ListNode* t=new ListNode(c);
                prev->next=t;
            }
            return l1;
        }
        else if(ptr1){
            while(c!=0 && ptr1!=NULL){
                if(ptr1->val+c>9){
                    ptr1->val=(ptr1->val+c)%10;
                    c=1;
                    prev=ptr1;
                    ptr1=ptr1->next;
                }
                else{
                    ptr1->val=ptr1->val+c;
                    c=0;
                }
            }
            if(c!=0){
                ListNode* t2=new ListNode(c);
                prev->next=t2;
            }
            return l2;
        }
        else{
            if(c==1){
                ListNode* x=new ListNode(c);
                pre->next=x;
            }
        }
        return l1;
    }
};