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
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        queue<ListNode*> q;
        stack<ListNode*> s;
        ListNode* ptr=head;
        int i=0,count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL){
            if(count%2==0){
                if(i<count/2){
                    q.push(ptr);
                }
                else{
                    s.push(ptr);
                }
            }
            else{
                if(i<(count+1)/2){
                    q.push(ptr);
                }
                else{
                    s.push(ptr);
                }
            }
            i++;
            ptr=ptr->next;
        }
        for(int i=0;i<count;i++){
            if(i%2==0){
                if(s.size()){
                    q.front()->next=s.top();
                    q.pop();
                }
                else{
                     q.front()->next=NULL;
                     q.pop();
                }
            }
            else{
                if(q.size()){
                    s.top()->next=q.front();
                    s.pop();
                }
                else{
                    s.top()->next=NULL;
                    s.pop();
                }
            }
        }
    }
};