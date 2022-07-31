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
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode* ptr=head;
        while(ptr){
            count++;
            ptr=ptr->next;
        }
        stack<ListNode*> s;
        queue<ListNode*> q;
        ptr=head;
        for(int i=0;i<count;i++){
            if(i<count/2){
                s.push(ptr);
            }
            else{
                q.push(ptr);
            }
            ptr=ptr->next;
        }
        if(s.size()!=q.size()){
            q.pop();
        }
        for(int i=0;i<count/2;i++){
            if(s.top()->val!=q.front()->val){
                return false;
            }
            s.pop();
            q.pop();
        }
        return true;
    }
};