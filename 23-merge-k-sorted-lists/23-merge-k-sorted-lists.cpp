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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            } 
        }
        ListNode* head=NULL;
        ListNode* curr=NULL;
        while(pq.size()){
            pair<int,ListNode*> temp=pq.top();
            pq.pop();
            if(head==NULL){
                head=temp.second;
                curr=head;
                if(temp.second->next!=NULL){
                    pq.push({temp.second->next->val,temp.second->next});
                }
            }
            else{
                curr->next=temp.second;
                curr=curr->next;
                if(temp.second->next!=NULL){
                    pq.push({temp.second->next->val,temp.second->next});
                }
            }
        }
        if(curr){
            curr->next=NULL;
        }
        return head;
    }
};