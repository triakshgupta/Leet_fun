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
    int getDecimalValue(ListNode* head) {
        struct ListNode *c=head;
        int count=0;
        while(c!=NULL){
            c=c->next;
            count++;
        }
        int result=0;
        int i=count-1;
        struct ListNode *ptr=head;
        while(i!=-1){
            int x=pow(2,i);
            int ans= x*ptr->val;
            result+=ans;
            ptr=ptr->next;
            i--;
        }
        return result;
    }
};