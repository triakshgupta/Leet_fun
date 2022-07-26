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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr=head->next;
        ListNode* value=head;
        int sum=0;
        while(ptr){
            if(ptr->val!=0){
                sum+=ptr->val;
            }
            else{
                value->val=sum;
                sum=0;
                if(ptr->next==NULL){
                    value->next=NULL;
                }
                else{
                    value=value->next;
                }
            }
            ptr=ptr->next;
        }
        return head;
    }
};