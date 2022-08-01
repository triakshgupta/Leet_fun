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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* p=head;
        set<int> s;
        int c=0;
        vector<ListNode*> t;
        while(p){
            if(s.count(p->val)==0){
                s.insert(p->val);
                t.push_back(p);
                c=1;
            }
            else{
                c++;
                if(c==2){
                    t.pop_back();
                }
            }
            p=p->next;
        }
        if(t.size()==0){
            return NULL;
        }
        for(int i=0;i<t.size()-1;i++){
            t[i]->next=t[i+1];
        }
        head=t[0];
        t[t.size()-1]->next=NULL;
        return head;
    }
};