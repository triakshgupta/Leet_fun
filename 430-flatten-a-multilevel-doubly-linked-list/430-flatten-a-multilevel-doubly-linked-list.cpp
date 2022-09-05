/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* x){
        Node* p=NULL;
        while(x!=NULL){
            if(x->child!=NULL){
                Node* temp=x->next;
                x->next=x->child;
                x->child->prev=x;
                Node* last=solve(x->child);
                x->child=NULL;
                last->next=temp;
                if(temp){
                    temp->prev=last;   
                }
            }
            p=x;
            x=x->next;
        }
        return p;
    }
    Node* flatten(Node* head) {
        Node* temp=head;
        Node* x=solve(temp);
        //x->next=NULL;
        return head;
    }
};