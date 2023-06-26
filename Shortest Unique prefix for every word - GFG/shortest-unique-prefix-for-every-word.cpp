//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct trie{
    trie* a[26];
    bool end=false;
    int cnt=0;
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        trie* head=new trie();
        for(int i=0;i<n;i++){
            trie* temp=head;
            for(int j=0;j<arr[i].size();j++){
                if(temp->a[arr[i][j]-'a']){
                    temp=temp->a[arr[i][j]-'a'];
                    temp->cnt++;
                }
                else{
                    trie* x=new trie();
                    temp->a[arr[i][j]-'a']=x;
                    temp=x;
                    temp->cnt++;
                }
            }
            temp->end=true;
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            trie* temp=head;
            string x="";
            for(int j=0;j<arr[i].size();j++){
                x+=arr[i][j];
                temp=temp->a[arr[i][j]-'a'];
                if(temp->cnt==1) break;
            }
            ans.push_back(x);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends