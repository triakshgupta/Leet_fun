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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL || left==right){
            return head;
        }
        ListNode* ptr=head;
        ListNode* templ=NULL;
        ListNode* tempr=NULL;
        stack<ListNode*> s;
        int i=1;
        while(i<=right+1){
            if(i==left-1){
                templ=ptr;
            }
            else if(i==right+1){
                tempr=ptr;
            }
            else if(i>=left && i<=right){
                s.push(ptr);
            }
            if(ptr!=NULL){
                ptr=ptr->next;
            }
            else{
                break;
            }
            i++;
        }
        ListNode* temp=templ;
        while(s.size()){
            if(left==1 && !temp){
                head=s.top();
            }
            else{
                temp->next=s.top();
            }
            temp=s.top();
            s.pop();
        }
        temp->next=tempr;
        return head;
    }
};