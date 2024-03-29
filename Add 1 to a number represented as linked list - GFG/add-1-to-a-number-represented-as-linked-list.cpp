//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* x){
        Node* prev=NULL;
        Node* curr=x;
        Node* nxt=x->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt) nxt=nxt->next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* r=reverse(head);
        Node* cpy=r;
        Node* prev;
        int c=1;
        while(r){
            prev=r;
            int t=r->data+c;
            c=0;
            r->data=t%10;
            if(t>9){
                c=1;
            }
            r=r->next;
        }
        if(c){
            Node* temp=new Node(1);
            prev->next=temp;
            prev=temp;
        }
        return reverse(cpy);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends