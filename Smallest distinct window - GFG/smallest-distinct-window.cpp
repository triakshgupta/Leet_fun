//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        unordered_set<char> s;
        for(int i=0;i<str.size();i++){
            if(s.count(str[i])==0) s.insert(str[i]);
        }
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int count=0;
        unordered_map<char,int> m;
        while(j<str.size()){
            if(count<s.size()){
                if(m[str[j]]==0) count++;
                m[str[j]]++;
                j++;
            }
            else{
                while(count==s.size()){
                    ans=min(ans,j-i);
                    m[str[i]]--;
                    if(m[str[i]]==0) count--;
                    i++;
                }
            }
        }
        while(count==s.size()){
            ans=min(ans,j-i);
            m[str[i]]--;
            if(m[str[i]]==0) count--;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends