/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        set<ListNode*> s;
        struct ListNode* ptr=head;
        while(ptr!=NULL){
            if(s.count(ptr)>0){
                break;
            }
            else{
                s.insert(ptr);
            }
            ptr=ptr->next;
        }
        return ptr;
    }
};