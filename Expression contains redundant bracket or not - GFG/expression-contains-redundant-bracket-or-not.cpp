//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<int> st;
        int i=0;
        pair<int,int> prev={0,0};
        while(i<s.size()){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int f=st.top();
                st.pop();
                int sc=i;
                if((sc-f==2) || ((prev.first!=0 || prev.second!=0) && prev.first==f+1 && prev.second==sc-1)) {
                    return 1;
                }
                prev={f,sc};
            }
            i++;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends