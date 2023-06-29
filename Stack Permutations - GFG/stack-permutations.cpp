//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        int i=0;
        int j=0;
        stack<int> s;
        while(i<A.size() && j<B.size()){
            if(s.empty() || s.top()!=B[j]){
                s.push(A[i]);
                i++;
            }
            else if(s.top()==B[j]){
                s.pop();
                j++;
            }
        }
        while(!s.empty()){
            if(s.top()!=B[j]) return false;
            s.pop();
            j++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends