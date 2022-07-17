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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        ListNode* ptr=head;
        while(ptr!=NULL){
            pq.push({ptr->val,ptr});
            ptr=ptr->next;
        }
        int sz=pq.size();
        for(auto i=0;i<sz;i++){
            if(i==0){
                head=pq.top().second;
            }
            ptr=pq.top().second;
            pq.pop();
            if(pq.size()){
                ptr->next=pq.top().second;
            }
            else{
                ptr->next=NULL;
            }
        }
        return head;
    }
};