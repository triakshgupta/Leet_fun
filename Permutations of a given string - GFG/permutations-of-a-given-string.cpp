//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void perm(int i,string s,set<string>& ans){
	        if(i==s.size()) ans.insert(s);
	        for(int x=i;x<s.size();x++){
	            swap(s[x],s[i]);
	            perm(i+1,s,ans);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> st;
		    perm(0,S,st);
		    vector<string> v;
		    for(auto i:st) v.push_back(i);
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends