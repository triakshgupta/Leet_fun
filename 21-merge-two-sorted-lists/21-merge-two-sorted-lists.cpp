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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        queue<ListNode *> q1;
        queue<ListNode *> q2;
        struct ListNode *ptr1=list1;
        struct ListNode *ptr2=list2;
        while(ptr1!=NULL){
            q1.push(ptr1);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            q2.push(ptr2);
            ptr2=ptr2->next;
        }
        ptr1=NULL;
        ptr2=NULL;
        while(!q1.empty() || !q2.empty()){
            if(q1.size()==0 && q2.size()!=0){
                    ptr2->next=q2.front();
                    ptr2=ptr2->next;
                    q2.pop();
                    continue;
            }
            if(q1.size()!=0 && q2.size()==0){
                    ptr2->next=q1.front();
                    ptr2=ptr2->next;
                    q1.pop();
                    continue;

            }
            if(q1.front()->val>q2.front()->val){
                if(ptr1==NULL){
                    ptr1=q2.front();
                    ptr2=ptr1;
                }
                else{
                    ptr2->next=q2.front();
                    ptr2=ptr2->next;
                }
                q2.pop();
            }
            else{
                if(ptr1==NULL){
                    ptr1=q1.front();
                    ptr2=ptr1;
                }
                else{
                    ptr2->next=q1.front();
                    ptr2=ptr2->next;
                }
                q1.pop();
            }
            
        }
        return ptr1;
    }
};