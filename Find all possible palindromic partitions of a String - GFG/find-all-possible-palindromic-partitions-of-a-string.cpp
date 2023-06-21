//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void palind(int i,string& s,vector<string>& ds,vector<vector<string>>& ans){
        if(i==s.size()){
            ans.push_back(ds);
            return;
        }
        string temp="";
        for(int x=i;x<s.size();x++){
            temp+=s[x];
            if(safe(temp)){
                ds.push_back(temp);
                palind(x+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    bool safe(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> ds;
        vector<vector<string>> ans;
        palind(0,S,ds,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends