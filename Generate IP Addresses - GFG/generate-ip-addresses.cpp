//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void ip(int i,string& s,string ds,vector<string>& ans,int k){
        if(i==s.size()){
            ds.pop_back();
            if(k==0) ans.push_back(ds);
            return;
        }
        if(k==0) return;
        if(s[i]=='0'){
            ds+=s[i];
            ds+='.';
            ip(i+1,s,ds,ans,k-1);
        }
        else{
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(temp.size()>3) break;
                if(stoi(temp)>255) break;
                ip(j+1,s,ds+temp+'.',ans,k-1);
            }
        }
    }
    vector<string> genIp(string &s) {
        // Your code here
        vector<string> ans;
        ip(0,s,"",ans,4);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends