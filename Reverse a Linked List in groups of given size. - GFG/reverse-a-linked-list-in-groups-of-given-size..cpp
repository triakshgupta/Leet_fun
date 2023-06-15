//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* rvrs(node* head){
        if(head==NULL || head->next==NULL) return head;
        node* prev=NULL;
        node* curr=head;
        node* nxt=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt) nxt=nxt->next;
        }
        return prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        int count=0;
        node* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        int x=count/k;
        temp=head;
        node* ans=NULL;
        node* tail=NULL;
        while(x--){
            int c=1;
            head=temp;
            while(c<k){
                temp=temp->next;
                c++;
            }
            node* nxt=temp->next;
            temp->next=NULL;
            temp=nxt;
            node* nhead=rvrs(head);
            if(tail) tail->next=nhead;
            if(!ans) ans=nhead;
            tail=head;
        }
        if((count/k)*k<count){
            node* t=rvrs(temp);
            tail->next=t;
        }
        return ans;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends