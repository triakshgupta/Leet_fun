//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void sentence(int i,set<string>& st,string temp,vector<string>& ans,string& s){
        if(i==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int x=i;x<s.size();x++){
            t+=s[x];
            if(st.count(t)){
                sentence(x+1,st,temp+t+' ',ans,s);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        set<string> st;
        for(auto i:dict) st.insert(i);
        vector<string> ans;
        sentence(0,st,"",ans,s);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends