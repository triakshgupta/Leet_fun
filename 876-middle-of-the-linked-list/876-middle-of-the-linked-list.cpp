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
    ListNode* middleNode(ListNode* head) {
        int count=0;
         struct ListNode *ptr=head;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        int n;
        if(count%2!=0){
            n=(count+1)/2;
        }
        else{
            n=count/2 + 1;
        }
        struct ListNode *ptr1=head;
        int i=1;
        while(i!=n){
            ptr1=ptr1->next;
            i++;
        }
        return ptr1;
    }
};